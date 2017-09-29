//----------------------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from ARM Limited or its affiliates.
//
// (C) COPYRIGHT 2016 ARM Limited or its affiliates.
// ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from ARM Limited or its affiliates.
//----------------------------------------------------------------------------

#include "mbed.h"
#include "mbed-trace/mbed_trace.h"
#include "mbed-trace-helper.h"
#include "SDBlockDevice.h"
#include "UbloxPPPCellularInterface.h"
#include "simplem2mclient.h"
#include "factory_configurator_client.h"
#include "urtp.h"
#include "log.h"

#ifdef MBED_HEAP_STATS_ENABLED
#include "memory_tests.h"
#endif

// Interval to update resource value in ms
#define INCREMENT_INTERVAL 25000

// Datagram storage for URTP
__attribute__ ((section ("CCMRAM")))
static char datagramStorage[URTP_DATAGRAM_STORE_SIZE];

UbloxPPPCellularInterface *cellular = NULL;

extern SDBlockDevice sd;     // in pal_plat_fileSystem.cpp

static Thread resource_thread;

// LEDs
static DigitalOut ledRed(LED1, 1);
static DigitalOut ledGreen(LED2, 1);
static DigitalOut ledBlue(LED3, 1);

bool init_connection() {
    bool success = false;

    srand(time(NULL));

    cellular = new UbloxPPPCellularInterface(MDMTXD, MDMRXD, 230400, true);

    printf ("Initialising cellular...\n");
    if (cellular->init()) {
        printf ("Please wait up to 180 seconds to connect to the packet network...\n");
        if (cellular->connect() == NSAPI_ERROR_OK) {
            success = true;
        } else {
            printf ("Unable to connect to the cellular packet network.\n");
        }
    } else {
        printf ("Unable to initialise cellular.\n");
    }

    return success;
}

static void increment_resource(void const* arg) {
    SimpleM2MClient *client;
    client = (SimpleM2MClient*) arg;
    while(true) {
        Thread::wait(INCREMENT_INTERVAL);
        if(client->is_client_registered()) {
            client->increment_resource_value();
#if defined(MBED_CLOUD_CLIENT_TRANSPORT_MODE_UDP) || \
    defined(MBED_CLOUD_CLIENT_TRANSPORT_MODE_UDP_QUEUE)
            client->keep_alive();
#endif
        }
    }
}

static void increment_resource_thread(void* client) {
    resource_thread.start(callback(increment_resource, (void*)client));
}

static bool init_mbed_trace()
{
    // Create mutex for tracing to avoid broken lines in logs
    if(!mbed_trace_helper_create_mutex()) {
        printf("ERROR -Mutex creation for mbed_trace failed!\n");
        return false;
    }

    // Initialize mbed trace
    mbed_trace_init();
    mbed_trace_mutex_wait_function_set(mbed_trace_helper_mutex_wait);
    mbed_trace_mutex_release_function_set(mbed_trace_helper_mutex_release);

    return true;
}

int main() {
    int x;

    ledGreen = 0;
    printf("Making sure the compiler links datagramStorage (0x%08x).\n", (int) datagramStorage);

    if (!init_mbed_trace()) {
        printf("Failed initializing mbed trace\n - exit" );
        mbed_trace_free();
        mbed_trace_helper_delete_mutex();
        return 1;
    }

    printf("Starting SD card...\n");
    x = sd.init();
    if(x != 0) {
        printf("Failed to initialise SD card with error %d.\n", x);
        return -1;
    }
    printf("SD card started...\n");

#ifdef MBED_HEAP_STATS_ENABLED
    // Print some statistics of the object sizes and heap memory consumption
    m2mobject_stats();
    heap_stats();
#endif
    printf("Start simple mbed Cloud Client\n");

    fcc_status_e status = fcc_init();
    if(status != FCC_STATUS_SUCCESS) {
        printf("fcc_init failed with status %d! - exit\n", status);
        return 1;
    }

    // Resets storage to an empty state.
    // Use this function when you want to clear storage from all the factory-tool generated data and user data.
    // After this operation device must be injected again by using factory tool or developer certificate.
#ifdef RESET_STORAGE
    printf("Resets storage to an empty state\n");
    fcc_status_e delete_status = fcc_storage_delete();
    if (delete_status != FCC_STATUS_SUCCESS) {
        printf("Failed to delete storage - %d\n", delete_status);
    }
#endif

#ifdef MBED_CONF_APP_DEVELOPER_MODE
    printf("Start developer flow\n");
    status = fcc_developer_flow();
    if (status == FCC_STATUS_KCM_FILE_EXIST_ERROR) {
        printf("Developer credentials already exists\n");
    } else if (status != FCC_STATUS_SUCCESS) {
        printf("Failed to load developer credentials - exit\n");
        return 1;
    }    
#endif
    status = fcc_verify_device_configured_4mbed_cloud();
    if (status != FCC_STATUS_SUCCESS) {
        printf("Device not configured for mbed Cloud - exit\n");
        return 1;
    }
    
    SimpleM2MClient *mbedClient = new SimpleM2MClient();
    mbedClient->create_resources();
    increment_resource_thread(mbedClient);
    mbedClient->call_register();
#ifdef MBED_HEAP_STATS_ENABLED
    heap_stats();
#endif
    ledGreen = 1;
    ledBlue = 0;
    while (mbedClient->is_register_called()) {
        wait_ms(1000);
    }
}
