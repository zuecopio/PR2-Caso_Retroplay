/**
 * @file     Config.h
 *
 * @brief    Where the necessary definitions are created.
 *
 * @author   Marcos Belda Martinez'   <mbelmar@etsinf.upv.es>  (student)
 * @author   Angela Espert Cornejo'   <aespcor@etsinf.upv.es>  (student)
 * @author   Lourdes Frances Llimera' <lfralli@epsa.upv.es>    (student)
 * @author   Carla Hidalgo Aroca'     <chidaro@etsii.upv.es>   (student)
 *
 * @date     April, 2024
 * @section  PR2-GIIROB
 */

//-----[ COMM BAUDS ]---------------------------------------//

#define BAUDS 115200

#define LOGGER_ENABLED                 // Comentar para deshabilitar el logger por consola serie.

#define LOG_LEVEL TRACE                // Niveles en c_logger: TRACE, DEBUG, INFO, WARN, ERROR, FATAL, NONE.


//-----[ DEVIDE ]-------------------------------------------//

#define DEVICE_RETROPLAY_ID            "04" //"retroplay-device-04"


//-----[ WIFI ]---------------------------------------------//

#define NET_SSID                       "UPV-PSK"
#define NET_PASSWD                     "giirob-pr2-2023"


//-----[ MQTT ]---------------------------------------------//

#define MQTT_SERVER_IP                 "mqtt.dsic.upv.es"
#define MQTT_SERVER_PORT                1883
#define MQTT_USERNAME                  "giirob"
#define MQTT_PASSWORD                  "UPV2024"

/*** end of file ***/
