#include "write_buffer.h"
#include "pin_register.h"
#include "util/delay.h"

#define F_CPU 16000000
#define BUAD    9600
#define MYUBRR     ((F_CPU/16/BUAD) - 1)


int loop();

void init();
