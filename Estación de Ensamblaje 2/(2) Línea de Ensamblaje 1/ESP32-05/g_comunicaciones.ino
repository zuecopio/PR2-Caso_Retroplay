/**
 * @file     g_comunicaciones.ino
 *
 * @brief    Implementation of communication functions.
 *
 * @author   Marcos Belda Martinez'   <mbelmar@etsinf.upv.es>  (student)
 * @author   Angela Espert Cornejo'   <aespcor@etsinf.upv.es>  (student)
 * @author   Lourdes Frances Llimera' <lfralli@epsa.upv.es>    (student)
 * @author   Carla Hidalgo Aroca'     <chidaro@etsii.upv.es>   (student)
 *
 * @date     April, 2024
 * @section  PR2-GIIROB
 */

#if US_ONLY_WHEN_LINE_IS_FREE // When US_ONLY_WHEN_LINE_IS_FREE = 1, that #if is working.

long now, lastMsg = 0;

// Tiempo de actualización del sensor US.
long sensorsUpdateInterval = 3000;

#endif

/******************************************************************************/
/*!
 * @brief  Topic subscription function.
 * @param  void
 * @return void
 */
void suscribirseATopics(void)
{
    #if US_ONLY_WHEN_LINE_IS_FREE // When US_ONLY_WHEN_LINE_IS_FREE = 1, that #if is working.
    
    mqtt_subscribe(LINE_STATUS_TOPIC);
    
    #endif

}   /* suscribirseATopics() */

/******************************************************************************/
/*!
 * @brief  Function to manage messages received by different topics.
 * @param  topic            (char *)
 * @param  incomingMessage  (String)
 * @return void
 */
void alRecibirMensajePorTopic(char * topic, String incomingMessage)
{
    #if US_ONLY_WHEN_LINE_IS_FREE // When US_ONLY_WHEN_LINE_IS_FREE = 1, that #if is working.
    
    // Create a JSON document.
    JsonDocument doc;
    // Parse the JSON input.
    DeserializationError err = deserializeJson(doc, incomingMessage);
    // Parsing succeeded?
    if (err)
    {
        warn(F("deserializeJson() returned ")); warnln(err.f_str());
        return;
    }

    String estado = doc["estado"];
    info("(JSON) Message received: "); infoln(estado);


    // If a message is received on the topic ...
    if (strcmp(topic, LINE_STATUS_TOPIC) == 0)
    {
        if (estado == "libre")
        {
            bool hayPC = false;
            
            while (hayPC == false)
            {
                now = millis();
      
                if ((now - lastMsg) > sensorsUpdateInterval)
                {
                    lastMsg = now;
            
                    // Get the distance from the sensor ...
                    //
                    distance = getUsDistance();
            
                    // If the distance is less than 10 cm, there is
                    // a new P-C placed at the entrance of the line.
                    //
                    if (distance < 10.0)
                    {
                        hayPC = true;
                        
                        // Create a JSON document.
                        JsonDocument doc;
                        doc["entrada"] = "hay";
                
                        // Serialize the JSON to a String.
                        String msg_json;
                        serializeJson(doc, msg_json);
                
                        // Send message by a topic.
                        enviarMensajePorTopic(LINE_ENTRANCE_STATUS_TOPIC, msg_json);
                        
                        infoln("Estación 2, Línea 1: Hay un P-C disponible en la entrada");
                    }
                }
            }
        }
    }
    
    #endif

}   /* alRecibirMensajePorTopic() */

/******************************************************************************/
/*!
 * @brief  Function to send a message by a topic.
 * @param  topic            (const char *)
 * @param  outgoingMessage  (String)
 * @return void
 */
void enviarMensajePorTopic(const char * topic, String outgoingMessage)
{
    mqtt_publish(topic, outgoingMessage.c_str());

}   /* enviarMensajePorTopic() */

/*** end of file ***/
