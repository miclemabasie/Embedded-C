#include <avr/io.h>/
#include <util/delay.h>

#define Green_LED PB0
#define Yellow_LED PB1
#define Red_LED PB2

int main(void)
{
    // Declare data direction registers (DDR)
    DDRB |= (1 << Green_LED);
    DDRB |= (1 << Yellow_LED);
    DDRB |= (1 << Red_LED);

    while (1)
    {
        // Turn on Red led
        PORTB |= (1 << Red_LED);
        _delay_ms(500); // delay 500ms

        // Turn on Yellow led
        PORTB |= (1 << Yellow_LED);
        _delay_ms(500); // delay 500ms

        // Turn on Green led
        PORTB |= (1 << Green_LED);
        _delay_ms(500); // delay 500ms

        // Turn off all LEDs in reverse sequence
        PORTB &= ~(1 << Green_LED);
        _delay_ms(500);

        PORTB &= ~(1 << Yellow_LED);
        _delay_ms(500);

        PORTB &= ~(1 << Red_LED);
        _delay_ms(500);
    }
}