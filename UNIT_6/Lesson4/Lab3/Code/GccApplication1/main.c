/*
 * GccApplication1.c
 *
 * Created: 8/21/2024 11:34:09 PM
 * Author : alaar
 */ 
#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void Interrupt_Init(){
    // any logical change for INT0
    MCUCR |= (1<<ISC00);
    MCUCR &= ~(1<<ISC01);

    // rising edge for INT1
    MCUCR |= (1<<ISC10) | (1<<ISC11);

    // falling edge for INT2
    MCUCSR &= ~(1<<ISC2);

    // Enable INT2, INT1, INT0
    GICR |= (1<<INT2) | (1<<INT1) | (1<<INT0);

    // Global Interrupt Enable
    sei();
}

int main(){
    // Set PD5, PD6, PD7 as output
    DDRD = 0b11100000;
    
    Interrupt_Init();
    
    while(1){
        // Wait for interrupts
    }
}

ISR(INT0_vect){
    PORTD |= (1<<PD5);  // Turn on LED connected to PD5
    _delay_ms(1000);    // Delay for 1 second (not ideal inside ISR)
    PORTD &= ~(1<<PD5); // Turn off LED
}

ISR(INT1_vect){
    PORTD |= (1<<PD6);  // Turn on LED connected to PD6
    _delay_ms(1000);    // Delay for 1 second (not ideal inside ISR)
    PORTD &= ~(1<<PD6); // Turn off LED
}

ISR(INT2_vect){
    PORTD |= (1<<PD7);  // Turn on LED connected to PD7
    _delay_ms(1000);    // Delay for 1 second (not ideal inside ISR)
    PORTD &= ~(1<<PD7); // Turn off LED
}
