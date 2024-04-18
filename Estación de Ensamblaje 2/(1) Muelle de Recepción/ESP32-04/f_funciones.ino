/**
 * @file     f_funciones.ino
 *
 * @brief    Implementation of functions to change the state of device outputs.
 *
 * @author   Marcos Belda Martinez'   <mbelmar@etsinf.upv.es>  (student)
 * @author   Angela Espert Cornejo'   <aespcor@etsinf.upv.es>  (student)
 * @author   Lourdes Frances Llimera' <lfralli@epsa.upv.es>    (student)
 * @author   Carla Hidalgo Aroca'     <chidaro@etsii.upv.es>   (student)
 * 
 * @date     April, 2024
 * @section  PR2-GIIROB
 */

/******************************************************************************/
/*!
 * @brief  Example function.
 * @param  void
 * @return void
 */
void example(void)
{
    // TODO: Desarrollo de la función ...
    float getDistance()
    {
        unsigned long pingTime;
        float distance;
        
        digitalWrite (trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
    
        prigTime = pulseIn(echoPin, HIGH, timeOut);
        distance (float)pingTime * soundVelocity / 2 / 10000; 
        return distance; 
    }
}   /* example() */

/*** end of file ***/
