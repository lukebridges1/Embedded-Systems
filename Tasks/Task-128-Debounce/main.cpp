#include "mbed.h"

DigitalIn ButtonA(PG_0);                    //Button A
DigitalIn BlueButton(USER_BUTTON);          //Blue user button
DigitalOut redLED(PC_2);                    //Red Traffic 1

int main()
{
    redLED = 0;

    while (true) {

        //Wait for a press
        while (ButtonA==0) { };

        //wait for debounce
        wait_us(100000);

        //Toggle LED
        redLED = !redLED;

        //Wait for release
        while (ButtonA==1) { };

        //wait for debounce
        wait_us(100000);
    }
}

