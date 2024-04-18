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
    
        //
        // Read and process sensors ...
        //
    }

}   /* on_loop() */

/*** end of file ***/
