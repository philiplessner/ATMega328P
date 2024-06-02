#include <avr/io.h>
#include <util/delay.h>

#define DELAYTIME 1000
#define LED_PORT  PORTB
#define LED_PIN   PINB
#define LED_DDR   DDRB

int main (void) {
    uint8_t i = 0;
    LED_DDR = 0xff;  /* Set up all pins for output */

    while(1) {
    
        while (i < 7) {
            LED_PORT = (i << 1);
            _delay_ms(DELAYTIME);
            i = i + 1;
        }
        /*
        while (i > 0) {
            LED_PORT = (i << 1);
            _delay_ms(DELAYTIME);
            i = i - 1;
        }
        */
        i = 0;
    }
    return (0);
}
