#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#define TX_BUFFER_SIZE 64
#define BUAD    9600
#define BRC     ((F_CPU/16/BUAD) - 1)

void ini_USART();

static void append_serial(char c);

void serial_write(char c[]);
