#include "application.h"

void init() {
    ini_USART();
    register_pin(LED);
}

int loop() {
    enable_pin(LED);
    _delay_ms(1000);

    serial_write("hello\r\nworld\r\n");

    disable_pin(LED);
    _delay_ms(1000);

    return 1;
}
