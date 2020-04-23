enable_language(ASM)

cmake_minimum_required(VERSION 3.9)
project("Vimard")
set(PRODUCT_NAME Vimard)
set(F_CPU 16000000)
set(MCU atmega328p)
set(BAUD 9600)
set(PROG_TYPE arduino)

set(E_FUSE 0xfd)
set(H_FUSE 0xda)
set(L_FUSE 0xfd)
set(LOCK_BIT 0xff)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_ASM_COMPILER avr-gcc)

add_definitions(-DF_CPU=${F_CPU} -DBAUD=${BAUD})
set(CMAKE_EXE_LINKER_FLAGS -mmcu=${MCU})

add_compile_options(-mmcu=${MCU} -c)
file(GLOB SRC_FILES "src/*.*")

add_executable(${PRODUCT_NAME} ${SRC_FILES})
set_target_properties(${PRODUCT_NAME} PROPERTIES OUTPUT_NAME ${PRODUCT_NAME}.elf)

add_custom_target(strip ALL avr-strip ${PRODUCT_NAME}.elf DEPENDS ${PRODUCT_NAME})
add_custom_target(hex ALL avr-objcopy -R .eeprom -O ihex ${PRODUCT_NAME}.elf ${PRODUCT_NAME}.hex DEPENDS strip)
add_custom_target(upload ALL avrdude -c${PROG_TYPE} -p${MCU} -P/dev/ttyACM0 -b115200 -D -U flash:w:${PRODUCT_NAME}.hex:i DEPENDS hex)
