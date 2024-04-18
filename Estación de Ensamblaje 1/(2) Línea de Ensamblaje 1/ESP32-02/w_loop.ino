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

#if !(US_ONLY_WHEN_LINE_IS_FREE) // When US_ONLY_WHEN_LINE_IS_FREE = 0, that #if is working.

long now, lastMsg = 0;

// Tiempo de actualización del sensor US.
long sensorsUpdateInterval = 3000;

#endif

/******************************************************************************/
/*!
 * @brief  Students loop function.
 * @param  void
 * @return void
 */
void on_loop(void)
{
    if (emergency_button.pressed)
    {
        // Create a JSON document.
        JsonDocument doc;
        doc["emergencia"] = "si";

        // Serialize the JSON to a String.
        String msg_json;
        serializeJson(doc, msg_json);

        // Send message by a topic.
        enviarMensajePorTopic(EMERGENCY_BUTTON_STATUS_TOPIC, msg_json);
        
        infoln("Estación 1, Línea 1: ¡El botón de emergencia se ha pulsado!");
        emergency_button.pressed = false;
    }

    #if !(US_ONLY_WHEN_LINE_IS_FREE) // When US_ONLY_WHEN_LINE_IS_FREE = 0, that #if is working.
    
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
            // Create a JSON document.
            JsonDocument doc;
            doc["entrada"] = "hay";
    
            // Serialize the JSON to a String.
            String msg_json;
            serializeJson(doc, msg_json);
    
            // Send message by a topic.
            enviarMensajePorTopic(LINE_ENTRANCE_STATUS_TOPIC, msg_json);
            
            infoln("Estación 1, Línea 1: Hay un P-C disponible en la entrada");
        }
    }
    
    #endif

}   /* on_loop() */

/*** end of file ***/
