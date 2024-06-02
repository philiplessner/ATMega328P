#include <avr/io.h>
#include <avr/interrupt.h>

// goal is to flip LED every second;


ISR(TIMER1_OVF_vect) {
    PORTB ^= _BV(PORTB5);
    TCNT1 = 65535 - (F_CPU/1024);
}

int main(void) {
    DDRB |= _BV(DDB5);
    // Maximum value (65535) minus number of ticks equal to one second
    TCNT1 = 65535 - (F_CPU/1024);
    // Sets the prescaler to 1024
    // 16M/1024 = 15625Hz
    TCCR1B = (1 << CS10) | (1 << CS12);
    TCCR1A = 0x00;  // Normal mode
    // Timer Counter 1 overflow interrupt enabled
    // When TCNT1 reaches 65535 the interrupt will be triggered.
    TIMSK1 = (1 << TOIE1);

    sei();

    while (1) {
        ;;
    }
}
