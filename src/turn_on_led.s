    .global turn_on_led
    .type    turn_on_led,%function

turn_on_led:
    ldi r31, 0x3
    sts 0x25, r31

    ldi r31, 0x03
    sts 0x24, r31
