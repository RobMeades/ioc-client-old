#ifndef _LOG_ENUM_
#define _LOG_ENUM_

#ifdef __cplusplus
extern "C" {
#endif

// The possible events for the RAM log
// If you add an item here, don't forget to
// add it to gLogEventStrings (in log_strings.cpp) also.
typedef enum {
    EVENT_NONE,
    EVENT_USER_1,
    EVENT_USER_2,
    EVENT_USER_3,
    EVENT_LOG_START,
    EVENT_LOG_STOP,
    EVENT_SYSTEM_START,
    EVENT_SYSTEM_STOP,
    EVENT_ENTER_STANDBY,
    EVENT_ENTER_STOP,
    EVENT_SLEEP_LEVEL_OFF,
    EVENT_SLEEP_LEVEL_DEREGISTERED,
    EVENT_SLEEP_LEVEL_REGISTERED,
    EVENT_FILE_OPEN,
    EVENT_FILE_OPEN_FAILURE,
    EVENT_FILE_CLOSE,
    EVENT_I2C_START,
    EVENT_I2C_STOP,
    EVENT_BATTERY_CHARGER_BQ24295_START,
    EVENT_BATTERY_CHARGER_BQ24295_START_FAILURE,
    EVENT_BATTERY_CHARGER_BQ24295_CONFIG_FAILURE,
    EVENT_BATTERY_CHARGER_BQ24295_STOP,
    EVENT_BATTERY_GAUGE_BQ27441_START,
    EVENT_BATTERY_GAUGE_BQ27441_START_FAILURE,
    EVENT_BATTERY_GAUGE_BQ27441_CONFIG_FAILURE,
    EVENT_BATTERY_GAUGE_BQ27441_STOP,
    EVENT_WATCHDOG_START,
    EVENT_WATCHDOG_START_FAILURE,
    EVENT_GNSS_START,
    EVENT_GNSS_START_FAILURE,
    EVENT_GNSS_STOP_PENDING,
    EVENT_GNSS_STOP,
    EVENT_SD_CARD_START,
    EVENT_SD_CARD_START_FAILURE,
    EVENT_SD_CARD_STOP,
    EVENT_CLOUD_CLIENT_FILE_STORAGE_INIT,
    EVENT_CLOUD_CLIENT_FILE_STORAGE_INIT_FAILURE,
    EVENT_CLOUD_CLIENT_DEVELOPER_FLOW_START,
    EVENT_CLOUD_CLIENT_DEVELOPER_FLOW_START_FAILURE,
    EVENT_CLOUD_CLIENT_VERIFY_CONFIG_FILES,
    EVENT_CLOUD_CLIENT_VERIFY_CONFIG_FILES_FAILURE,
    EVENT_CLOUD_CLIENT_RESET_STORAGE,
    EVENT_CLOUD_CLIENT_RESET_STORAGE_FAILURE,
    EVENT_CLOUD_CLIENT_INIT_DM,
    EVENT_CLOUD_CLIENT_CONFIG_DM,
    EVENT_CLOUD_CLIENT_CONFIG_DM_FAILURE,
    EVENT_CREATE_LWM2M_OBJECTS,
    EVENT_LWM2M_OBJECT_UPDATE,
    EVENT_DELETE_LWM2M_OBJECTS,
    EVENT_CLOUD_CLIENT_START,
    EVENT_CLOUD_CLIENT_START_FAILURE,
    EVENT_CLOUD_CLIENT_STOP,
    EVENT_MODEM_START,
    EVENT_MODEM_START_FAILURE,
    EVENT_MODEM_STOP,
    EVENT_NETWORK_CONNECTING,
    EVENT_NETWORK_CONNECTION_FAILURE,
    EVENT_NETWORK_CONNECTED,
    EVENT_NETWORK_DISCONNECTING,
    EVENT_NETWORK_DISCONNECTED,
    EVENT_CLOUD_CLIENT_CONNECTING,
    EVENT_CLOUD_CLIENT_CONNECT_FAILURE,
    EVENT_CLOUD_CLIENT_CONNECTED,
    EVENT_CLOUD_CLIENT_REGISTERED,
    EVENT_CLOUD_CLIENT_DEREGISTERED,
    EVENT_CLOUD_CLIENT_DISCONNECTING,
    EVENT_CLOUD_CLIENT_DISCONNECTED,
    EVENT_CLOUD_CLIENT_DELETE,
    EVENT_INITIALISATION_MODE_START,
    EVENT_INITIALISATION_MODE_WAKE_UP_TICK,
    EVENT_READY_MODE_START,
    EVENT_READY_MODE_WAKE_UP_TICK,
    EVENT_READY_MODE_WAKE_UP_TICK_COUNTER_RESET,
    EVENT_READY_MODE_INSTRUCTION_RECEIVED,
    EVENT_SET_POWER_CONTROL,
    EVENT_SET_AUDIO_CONFIG_FIXED_GAIN,
    EVENT_SET_AUDIO_CONFIG_DURATION,
    EVENT_SET_AUDIO_CONFIG_COMUNICATIONS_MODE,
    EVENT_SET_AUDIO_CONFIG_STREAMING_ENABLED,
    EVENT_SET_AUDIO_CONFIG_STREAMING_DISABLED,
    EVENT_SET_INIT_WAKE_UP_TICK_COUNTER_PERIOD,
    EVENT_SET_INIT_WAKE_UP_TICK_COUNTER_MODULO,
    EVENT_SET_READY_WAKE_UP_TICK_COUNTER_PERIOD1,
    EVENT_SET_READY_WAKE_UP_TICK_COUNTER_PERIOD2,
    EVENT_SET_READY_WAKE_UP_TICK_COUNTER_MODULO,
    EVENT_RESET_TEMPERATURE_MIN_MAX,
    EVENT_EXTERNAL_POWER_ON,
    EVENT_EXTERNAL_POWER_OFF,
    EVENT_BATTERY_VOLTAGE,
    EVENT_BATTERY_CURRENT,
    EVENT_BATTERY_PERCENTAGE,
    EVENT_BATTERY_STATUS_FAULT,
    EVENT_BATTERY_STATUS_LOW_BATTERY,
    EVENT_BATTERY_STATUS_NORMAL,
    EVENT_BATTERY_STATUS_CHARGING,
    EVENT_BATTERY_STATUS_CHARGING_COMPLETE,
    EVENT_BATTERY_STATUS_UNKNOWN,
    EVENT_GNSS_TIMESTAMP,
    EVENT_GNSS_LONGITUDE,
    EVENT_GNSS_LATITUDE,
    EVENT_GNSS_RADIUS,
    EVENT_GNSS_SPEED,
    EVENT_GNSS_ALTITUDE,
    EVENT_AUDIO_STREAMING_START,
    EVENT_AUDIO_STREAMING_START_FAILURE,
    EVENT_AUDIO_STREAMING_STOP,
    EVENT_AUDIO_STREAMING_CONNECTION_START,
    EVENT_AUDIO_STREAMING_CONNECTION_START_FAILURE,
    EVENT_AUDIO_STREAMING_CONNECTION_STOP,
    EVENT_SOCKET_OPENING,
    EVENT_SOCKET_OPENING_FAILURE,
    EVENT_SOCKET_OPENED,
    EVENT_TCP_CONNECTING,
    EVENT_TCP_CONNECT_FAILURE,
    EVENT_TCP_CONNECTED,
    EVENT_TCP_CONFIGURED,
    EVENT_TCP_CONFIGURATION_FAILURE,
    EVENT_I2S_START,
    EVENT_I2S_START_FAILURE,
    EVENT_I2S_STOP,
    EVENT_BUTTON_PRESSED,
    EVENT_I2S_DMA_RX_HALF_FULL,
    EVENT_I2S_DMA_RX_FULL,
    EVENT_I2S_DMA_UNKNOWN,
    EVENT_CONTAINER_STATE_EMPTY,
    EVENT_CONTAINER_STATE_WRITING,
    EVENT_CONTAINER_STATE_READY_TO_READ,
    EVENT_CONTAINER_STATE_READING,
    EVENT_CONTAINER_STATE_READ,
    EVENT_DATAGRAM_NUM_SAMPLES,
    EVENT_DATAGRAM_SIZE,
    EVENT_DATAGRAM_OVERFLOW_BEGINS,
    EVENT_DATAGRAM_NUM_OVERFLOWS,
    EVENT_RAW_AUDIO_DATA_0,
    EVENT_RAW_AUDIO_DATA_1,
    EVENT_RAW_AUDIO_POSSIBLE_ROTATION,
    EVENT_RAW_AUDIO_ROTATION_VOTE,
    EVENT_RAW_AUDIO_DATA_ROTATION,
    EVENT_RAW_AUDIO_DATA_ROTATION_NOT_FOUND,
    EVENT_STREAM_MONO_SAMPLE_DATA,
    EVENT_MONO_SAMPLE_UNUSED_BITS,
    EVENT_MONO_SAMPLE_UNUSED_BITS_MIN,
    EVENT_MONO_SAMPLE_AUDIO_SHIFT,
    EVENT_STREAM_MONO_SAMPLE_PROCESSED_DATA,
    EVENT_UNICAM_MAX_ABS_VALUE,
    EVENT_UNICAM_MAX_VALUE_USED_BITS,
    EVENT_UNICAM_SHIFT_VALUE,
    EVENT_UNICAM_CODED_SHIFT_VALUE,
    EVENT_UNICAM_CODED_SHIFTS_BYTE,
    EVENT_UNICAM_SAMPLE,
    EVENT_UNICAM_COMPRESSED_SAMPLE,
    EVENT_UNICAM_10_BIT_CODED_SAMPLE,
    EVENT_UNICAM_BLOCKS_CODED,
    EVENT_UNICAM_BYTES_CODED,
    EVENT_SEND_START,
    EVENT_SEND_STOP,
    EVENT_SEND_FAILURE,
    EVENT_SOCKET_BAD,
    EVENT_SOCKET_ERRORS_FOR_TOO_LONG,
    EVENT_TCP_SEND_TIMEOUT,
    EVENT_SEND_SEQ,
    EVENT_SEND_DURATION_GREATER_THAN_BLOCK_DURATION,
    EVENT_SEND_DURATION,
    EVENT_NEW_PEAK_SEND_DURATION,
    EVENT_NUM_DATAGRAMS_FREE,
    EVENT_NUM_DATAGRAMS_QUEUED,
    EVENT_THROUGHPUT_BITS_S,
    EVENT_TCP_WRITE,
    EVENT_TCP_QUEUELEN,
    EVENT_TCP_SEQ,
    EVENT_TCP_SNDWND,
    EVENT_TCP_CWND,
    EVENT_TCP_WND,
    EVENT_TCP_EFFWND,
    EVENT_TCP_ACK
} LogEvent;

#ifdef __cplusplus
}
#endif

#endif

// End of file
