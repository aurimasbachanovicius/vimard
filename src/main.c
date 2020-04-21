#include "application.h"

int main(void) {
    init();
    while (1) {
        if (loop() == 0) {
            break;
        }
    }
}
