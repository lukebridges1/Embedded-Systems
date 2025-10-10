#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define LEDMASK_C 0b0000000001001100      //mask for port c LEDs
#define LEDMASK_B 0b0100000100000001      //mask for PB_0, PB_7 and PB_14
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut ledsC(PortC, 0b0000000001001000);
PortOut ledsB(PortB, 0b0100000100000001);

int main()
{
    while (true) {
        //turn LEDs on
        ledsC = ledsC ^ LEDMASK_C;
        ledsB = ledsB ^ LEDMASK_B;
        wait_us(500000);
    }
}




