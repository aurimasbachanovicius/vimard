#include "write_buffer.h"

char serial_buffer[TX_BUFFER_SIZE];
uint8_t serial_read_pos = 0;
uint8_t serial_write_pos = 0;

ISR(USART_TX_vect) {
    if (serial_read_pos != serial_write_pos) {
        UDR0 = (uint8_t) serial_buffer[serial_read_pos];
        serial_read_pos++;

        if (serial_read_pos >= TX_BUFFER_SIZE) {
            serial_read_pos++;
        }
    }
}

void ini_USART() {
    sei();
    UBRR0H = (unsigned char) (BRC >> 8);
    UBRR0L = (unsigned char) BRC;

    /* Enable receiver and transmitter */
    UCSR0B = (1 << TXCIE0) | (1 << TXEN0);

    /* Set frame format: 8data, 2stop bit */
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}

static void append_serial(char c) {
    serial_buffer[serial_write_pos] = c;
    serial_write_pos++;

    if (serial_write_pos >= TX_BUFFER_SIZE) {
        serial_write_pos = 0;
    }
}

void serial_write(char c[]) {
    for (uint8_t i = 0; i < strlen(c); i++) {
        append_serial(c[i]);
    }

    UDR0 = 0;
    if (UCSR0A & (1 << UDRE0)) {
        UDR0 = 0;
    }
}
