#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>



void ini_USART();

static void append_serial(char c);

void serial_write(char c[]);
