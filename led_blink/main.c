#include <avr/io.h>
#include <util/delay.h>

#define NBLINKS 5
#define BLINKTIME 500  // ms

int main() {
  // Intialize all PORTB pins as output
  DDRB = 0b11111111;

  while (1) {
    for (uint8_t i =0; i < 7; i++) {
        for (uint8_t j = 0; j < NBLINKS; j++) {
          PORTB |= (1 << i | 1 << (i+1));
          _delay_ms(BLINKTIME);
          PORTB &= ~(1 << i | 1 << (i+1));
          _delay_ms(BLINKTIME);
      }
    }
  }
}
