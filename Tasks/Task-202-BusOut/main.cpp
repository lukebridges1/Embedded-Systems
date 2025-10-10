#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

// Objects
// DigitalOut grn(TRAF_GRN1_PIN);
// DigitalOut yel(TRAF_YEL1_PIN);
// DigitalOut red(TRAF_RED1_PIN,1);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    while (true) {
       //Count from 0 to 7 in binary (000 to 111)
       for (int i = 0; i < 8; i++)  {
       leds = i;
       wait_us(500000);
    }
  }
}
