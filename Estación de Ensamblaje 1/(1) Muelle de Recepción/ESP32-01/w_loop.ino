/**
 * @file     w_loop.ino
 *
 * @brief    Implementation of loop function.
 *
 * @author   Marcos Belda Martinez'   <mbelmar@etsinf.upv.es>  (student)
 * @author   Angela Espert Cornejo'   <aespcor@etsinf.upv.es>  (student)
 * @author   Lourdes Frances Llimera' <lfralli@epsa.upv.es>    (student)
 * @author   Carla Hidalgo Aroca'     <chidaro@etsii.upv.es>   (student)
 *
 * @date     April, 2024
 * @section  PR2-GIIROB
 */

long now, lastMsg = 0;

// Tiempo de actualización de los sensores.
long sensorsUpdateInterval = 5000;

/******************************************************************************/
/*!
 * @brief  Students loop function.
 * @param  void
 * @return void
 */
void on_loop(void)
{
    now = millis();
  
    if ((now - lastMsg) > sensorsUpdateInterval)
    {
        lastMsg = now;

        distance = getUsDistance();

        // If the distance is less than 10 cm, there is
        // a new P-C placed at the entrance of the line.
        //
        if (distance < 10.0)
        {
            // Create a JSON document.
            JsonDocument doc;
            doc["Estado muelle"] = "Ocupado";
    
            // Serialize the JSON to a String.
            String msg_json;
            serializeJson(doc, msg_json);
    
            // Send message by a topic.
            enviarMensajePorTopic(MQTT_TOPIC_RECEPCION_STATUS, msg_json);
            
            infoln("Estación 1: Hay un P-C disponible en la entrada");
        }
    }
    #endif

}   /* on_loop() */

/*** end of file ***/
