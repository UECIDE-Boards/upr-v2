#include "api.h"

const uint8_t __ports[] = {
    PORT_B, PORT_B, PORT_B, PORT_B, PORT_C, PORT_C, PORT_A, PORT_A,
    PORT_C, PORT_C, PORT_C, PORT_C, PORT_C, PORT_C, PORT_A, PORT_A,
    PORT_A, PORT_A, PORT_B, PORT_B, PORT_B, PORT_B
};

const uint8_t __pins[] = {
    7, 6, 0, 1, 6, 7, 1, 0, 
    5, 4, 3, 2, 1, 0, 5, 4, 
    3, 2, 5, 4, 3, 2
};

const uint8_t _pins_max = (sizeof(__pins) / sizeof (__pins[0]));

void __initPLL() {
    OSCCONbits.IRCF = 0b111;
    while (OSCCONbits.IOFS == 0) {
        continue;
    }
    OSCTUNEbits.PLLEN = 1;
}
