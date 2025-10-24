#include "mbed.h"

// define pins
AnalogIn tempSensor(A0);    //Temperature sensor input (A0)
PwmOut led(PA_5);           //PWM output for LED (PA5)




// main() runs in its own thread in the OS
int main()
{
    printf("Program Starting...\n");

    const float polling_interval = 0.1f;    //100ms polling interval 
    float temperature = 0.0f;               //variable to store temperature 
    float brightness = 0.0f;                //variable to store brightness

    while (true) {
// read analog input from temperature sensor 
    float analog_value = tempSensor.read();

// convert analog reading to temperature (0°C to 100°C)
    temperature = analog_value * 100.0f;

// adjust brightness of LED depending on temperature 
    if (temperature < 20.0f) {
        brightness = 0.0f;  //LED Off
    }
    else if (temperature >= 20.0f && temperature <= 40.0f) {
        brightness = (temperature - 20.0f) / 20.0f;
// scale brightness proportionally between 20°C and 40°C
    }
    else {
        brightness = 1.0f;  //LED fully On above 40°C
    }

// set PWM duty cycle to control LED brightness 
    led.write(brightness);

// display current readings
    printf("Temperature: %.2f °C | LED Brightness: %.2f\n", temperature, brightness);

//polling interval 
    ThisThread::sleep_for(100ms);

    }
}

