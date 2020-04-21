#include "write_buffer.h"
#include "pin_register.h"
#include "util/delay.h"

#define F_CPU 16000000
#define LED (1 << PB4)

int loop();

void init();
