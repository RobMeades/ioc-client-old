// The events as strings (must be kept in line with the
// LogEvent enum in log_enum.h).
// By convention, a "*" prefix means that a bad thing
// has happened, makes them easier to spot in a stream
// of prints flowing up the console window.
const char *gLogStrings[] = {
    "  EMPTY",
    "  USER_1",
    "  USER_2",
    "  USER_3",
    "  LOG_START",
    "  LOG_STOP",
    "  SYSTEM_START",
    "  SYSTEM_STOP",
    "  ENTER_STANDBY",
    "  ENTER_STOP",
    "  SLEEP_LEVEL_OFF",
    "  SLEEP_LEVEL_DEREGISTERED",
    "  SLEEP_LEVEL_REGISTERED",
    "  FILE_OPEN",
    "* FILE_OPEN_FAILURE",
    "  FILE_CLOSE",
    "  I2C_START",
    "  I2C_STOP",
    "  BATTERY_CHARGER_BQ24295_START",
    "* BATTERY_CHARGER_BQ24295_START_FAILURE",
    "* BATTERY_CHARGER_BQ24295_CONFIG_FAILURE",
    "  BATTERY_CHARGER_BQ24295_STOP",
    "  BATTERY_GAUGE_BQ27441_START",
    "* BATTERY_GAUGE_BQ27441_START_FAILURE",
    "* BATTERY_GAUGE_BQ27441_CONFIG_FAILURE",
    "  BATTERY_GAUGE_BQ27441_STOP",
    "  WATCHDOG_START",
    "* WATCHDOG_START_FAILURE",
    "  GNSS_START",
    "* GNSS_START_FAILURE",
    "  GNSS_STOP_PENDING",
    "  GNSS_STOP",
    "  SD_CARD_START",
    "* SD_CARD_START_FAILURE",
    "  SD_CARD_STOP",
    "  CLOUD_CLIENT_FILE_STORAGE_INIT",
    "* CLOUD_CLIENT_FILE_STORAGE_INIT_FAILURE",
    "  CLOUD_CLIENT_DEVELOPER_FLOW_START",
    "* CLOUD_CLIENT_DEVELOPER_FLOW_START_FAILURE",
    "  CLOUD_CLIENT_VERIFY_CONFIG_FILES",
    "* CLOUD_CLIENT_VERIFY_CONFIG_FILES_FAILURE",
    "  CLOUD_CLIENT_RESET_STORAGE",
    "* CLOUD_CLIENT_RESET_STORAGE_FAILURE",
    "  CLOUD_CLIENT_INIT_DM",
    "  CLOUD_CLIENT_CONFIG_DM",
    "* CLOUD_CLIENT_CONFIG_DM_FAILURE",
    "  CREATE_LWM2M_OBJECTS",
    "  LWM2M_OBJECT_UPDATE",
    "  DELETE_LWM2M_OBJECTS",
    "  CLOUD_CLIENT_START",
    "* CLOUD_CLIENT_START_FAILURE",
    "  CLOUD_CLIENT_STOP",
    "  MODEM_START",
    "* MODEM_START_FAILURE",
    "  MODEM_STOP",
    "  NETWORK_CONNECTING",
    "* NETWORK_CONNECT_FAILURE",
    "  NETWORK_CONNECTED",
    "  NETWORK_DISCONNECTING",
    "  NETWORK_DISCONNECTED",
    "  CLOUD_CLIENT_CONNECTING",
    "* CLOUD_CLIENT_CONNECT_FAILURE",
    "  CLOUD_CLIENT_CONNECTED",
    "  CLOUD_CLIENT_REGISTERED",
    "  CLOUD_CLIENT_DEREGISTERED",
    "  CLOUD_CLIENT_DISCONNECTING",
    "  CLOUD_CLIENT_DISCONNECTED",
    "  CLOUD_CLIENT_DELETE",
    "  INITIALISATION_MODE_START",
    "  INITIALISATION_MODE_WAKE_UP_TICK",
    "  READY_MODE_START",
    "  READY_MODE_WAKE_UP_TICK",
    "  READY_MODE_WAKE_UP_TICK_COUNTER_RESET",
    "  READY_MODE_INSTRUCTION_RECEIVED",
    "  SET_POWER_CONTROL",
    "  SET_AUDIO_CONFIG_FIXED_GAIN",
    "  SET_AUDIO_CONFIG_DURATION",
    "  SET_AUDIO_CONFIG_COMUNICATIONS_MODE",
    "  SET_AUDIO_CONFIG_STREAMING_ENABLED",
    "  SET_AUDIO_CONFIG_STREAMING_DISABLED",
    "  SET_INIT_WAKE_UP_TICK_COUNTER_PERIOD",
    "  SET_INIT_WAKE_UP_TICK_COUNTER_MODULO",
    "  SET_READY_WAKE_UP_TICK_COUNTER_PERIOD1",
    "  SET_READY_WAKE_UP_TICK_COUNTER_PERIOD2",
    "  SET_READY_WAKE_UP_TICK_COUNTER_MODULO",
    "  RESET_TEMPERATURE_MIN_MAX",
    "  EXTERNAL_POWER_ON",
    "  EXTERNAL_POWER_OFF",
    "  BATTERY_VOLTAGE",
    "  BATTERY_CURRENT",
    "  BATTERY_PERCENTAGE",
    "* BATTERY_STATUS_FAULT",
    "  BATTERY_STATUS_LOW_BATTERY",
    "  BATTERY_STATUS_NORMAL",
    "  BATTERY_STATUS_CHARGING",
    "  BATTERY_STATUS_CHARGING_COMPLETE",
    "* BATTERY_STATUS_UNKNOWN",
    "  GNSS_TIMESTAMP",
    "  GNSS_LONGITUDE",
    "  GNSS_LATITUDE",
    "  GNSS_RADIUS",
    "  GNSS_SPEED",
    "  GNSS_ALTITUDE",
    "  AUDIO_STREAMING_START",
    "* AUDIO_STREAMING_START_FAILURE",
    "  AUDIO_STREAMING_STOP",
    "  AUDIO_STREAMING_CONNECTION_START",
    "* AUDIO_STREAMING_CONNECTION_START_FAILURE",
    "  AUDIO_STREAMING_CONNECTION_STOP",
    "  SOCKET_OPENING",
    "* SOCKET_OPENING_FAILURE",
    "  SOCKET_OPENED",
    "  TCP_CONNECTING",
    "* TCP_CONNECT_FAILURE",
    "  TCP_CONNECTED",
    "  TCP_CONFIGURED",
    "* TCP_CONFIGURATION_FAILURE",
    "  I2S_START",
    "* I2S_START_FAILURE",
    "  I2S_STOP",
    "  BUTTON_PRESSED",
    "  I2S_DMA_RX_HALF_FULL",
    "  I2S_DMA_RX_FULL",
    "* I2S_DMA_UNKNOWN",
    "  CONTAINER_STATE_EMPTY",
    "  CONTAINER_STATE_WRITING",
    "  CONTAINER_STATE_READY_TO_READ",
    "  CONTAINER_STATE_READING",
    "  CONTAINER_STATE_READ",
    "  DATAGRAM_NUM_SAMPLES",
    "  DATAGRAM_SIZE",
    "* DATAGRAM_OVERFLOW_BEGINS",
    "* DATAGRAM_NUM_OVERFLOWS",
    "  RAW_AUDIO_DATA_0",
    "  RAW_AUDIO_DATA_1",
    "  RAW_AUDIO_POSSIBLE_ROTATION",
    "  RAW_AUDIO_ROTATION_VOTE",
    "  RAW_AUDIO_DATA_ROTATION",
    "  RAW_AUDIO_DATA_ROTATION_NOT_FOUND",
    "  STREAM_MONO_SAMPLE_DATA",
    "  MONO_SAMPLE_UNUSED_BITS",
    "  MONO_SAMPLE_UNUSED_BITS_MIN",
    "  MONO_SAMPLE_AUDIO_SHIFT",
    "  STREAM_MONO_SAMPLE_PROCESSED_DATA",
    "  UNICAM_MAX_ABS_VALUE",
    "  UNICAM_MAX_VALUE_USED_BITS",
    "  UNICAM_SHIFT_VALUE",
    "  UNICAM_CODED_SHIFT_VALUE",
    "  UNICAM_CODED_SHIFTS_BYTE",
    "  UNICAM_SAMPLE",
    "  UNICAM_COMPRESSED_SAMPLE",
    "  UNICAM_10_BIT_CODED_SAMPLE",
    "  UNICAM_BLOCKS_CODED",
    "  UNICAM_BYTES_CODED",
    "  SEND_START",
    "  SEND_STOP",
    "* SEND_FAILURE",
    "* SOCKET_GONE_BAD",
    "* SOCKET_ERRORS_FOR_TOO_LONG",
    "* TCP_SEND_TIMEOUT",
    "  SEND_SEQ",
    "* SEND_DURATION_GREATER_THAN_BLOCK_DURATION",
    "  SEND_DURATION",
    "  NEW_PEAK_SEND_DURATION",
    "  NUM_DATAGRAMS_FREE",
    "  NUM_DATAGRAMS_QUEUED",
    "  THROUGHPUT_BITS_S",
    "  TCP_WRITE",
    "  TCP_QUEUELEN",
    "  TCP_SEQ",
    "  TCP_SNDWND",
    "  TCP_CWND",
    "  TCP_WND",
    "  TCP_EFFWND",
    "  TCP_ACK"
};

const int gNumLogStrings = sizeof (gLogStrings) / sizeof (gLogStrings[0]);

// End of file