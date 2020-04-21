#include "pin_register.h"

void register_pin(unsigned int pin) { DDRB |= pin; }

void disable_pin(unsigned int pin) { PORTB &= ~pin; }

void enable_pin(unsigned int pin) { PORTB |= pin; }
