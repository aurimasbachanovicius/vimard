#include "application.h"

#define F_CPU 16000000
#define BUAD    9600
#define MYUBRR     ((F_CPU/16/BUAD) - 1)

void USART_Init(unsigned int ubrr);

void USART_Transmit(char data[]);

ISR(USART_TX_vect) {}

void init() {
    USART_Init(MYUBRR);

    DDRB = 1u << 0u;

    PORTB = 0b00000000;
    PINB = 0b00000000;
}

int loop() {
    _delay_ms(1000);
    PORTB = (1u << 0u);

    int portB = PORTB;

    if (portB & (1u << 0u)) {
        USART_Transmit("astuonetas\n");
    }
    if (portB & (1u << 1u)) {
        USART_Transmit("9-\n");
    }

    USART_Transmit("\n\r");

//    char value[6] = PORTB;

//    USART_Transmit("\n\r");
//    USART_Transmit(value);
//    USART_Transmit("Hello world!\n\r");

    return 1;
}

void USART_Init(unsigned int ubrr) {
    UBRR0H = (unsigned char) (ubrr >> 8u);
    UBRR0L = (unsigned char) ubrr;
    UCSR0B = (1 << TXCIE0) | (1 << TXEN0);
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);
    sei();
}

void USART_Transmit(char data[]) {
    for (unsigned int i = 0; strlen(data) > i; i++) {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = data[i];
    }
}
