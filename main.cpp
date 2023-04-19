/*  LED-Brightness-Template
*   This template code is configure to work with a RGB LED. Three PwmOut objects are created to control the red, green and blue colours.
*   The program cycles through two colours (red and green) in turn, ramping the brightness by incrmenting the duty cycle by 2% per loop iteration.
*   
*   The code should be modified in accordance with ADC & PWM Activity 2. 
*
*   Board: NUCLEO L476RG
*   Author: James Chandler 2021
*/
#include "mbed.h"

#define WAIT_TIME_MS 50 //Wait timw used to set the for loop frequency (i.e. increment 2% per 50 ms = 100% in 2.5 s)

PwmOut red_LED(PB_3);   //PWM output to red led
PwmOut green_LED(PB_5); //PWM output to green led
PwmOut blue_LED(PB_4);  //PWM output to blue led

AnalogIn pot1(PA_5);
AnalogIn pot2(PA_6);
AnalogIn pot3(PA_7);

float frequency = 100;  //Create frequency variable to set PWM frequencies to 100 Hz

void init();            // Declare led initialisation function

int main()
{
    init();
    
    while (true)
    {
        float val = pot1.read();
        red_LED.write(val);

        float PWM = pot2.read();
        green_LED.write(PWM);

        float PWM3 = pot3.read();
        blue_LED.write(PWM3);
        
        
    }
}

void init(){
    red_LED.write(0.0);                 //initialise leds with inital PWM value to 0.0 = 0%
    green_LED.write(0.0); 
    blue_LED.write(0.0);
        
    red_LED.period(1/frequency);        //set the period of the wave form as 1/100Hz
    green_LED.period(1/frequency);
    blue_LED.period(1/frequency); 
}