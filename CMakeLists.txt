cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(floriquiz)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(floriquiz
  main.c trivia.c
)

pico_generate_pio_header(floriquiz ${CMAKE_CURRENT_LIST_DIR}/neopixel.pio)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(floriquiz pico_stdlib hardware_pio)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(floriquiz)
