cmake_minimum_required(VERSION 3.18.3)

#set(CMAKE_CXX_FLAGS "-fpermissive")
set( USE_ZEPHYR ON CACHE INTERNAL "" )
set( ZEPHYR_BASE "${CMAKE_CURRENT_LIST_DIR}/../zephyrproject/zephyr" )

# config board
set( BOARD_ROOT ${ZEPHYR_BASE} )

# config toolchain
set( ZEPHYR_TOOLCHAIN_VARIANT gnuarmemb )
#set (ZEPHYR_SDK_INSTALL_DIR "/home/zephyr-sdk-0.13.1")
set( GNUARMEMB_TOOLCHAIN_PATH "C:/GNU/" ) #!!! todo: set toolchain path default from env if exists, expose as cmake config var 

# config external modules (usually initialised with west update on new zephyr installs)
list( APPEND ZEPHYR_MODULES
    "${ZEPHYR_BASE}/modules/hal/cmsis"
    "${ZEPHYR_BASE}/modules/hal/stm32"
    "${ZEPHYR_BASE}/modules/hal/st"
    "${ZEPHYR_BASE}/modules/debug/segger"
    "${ZEPHYR_BASE}/modules/crypto/mbedtls"
    "${ZEPHYR_BASE}/modules/lib/openthread"
)
#set(MCUBOOT_DIR "${ZEPHYR_BASE}/mcuboot") if using MCUBoot... may not be right
#set(TOOLS_DIR "${TZEPHYR_BASE}/tools") if using any tools... may not be right

find_package(Zephyr REQUIRED HINTS ${ZEPHYR_BASE} )
project(wx_zephyr)

list( APPEND SRCS
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
)

list( APPEND INCS
    "${PROJECT_SOURCE_DIR}/inc"
)

add_compile_options( -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable )

target_sources( app PRIVATE ${SRCS} )
target_include_directories( app PRIVATE ${INCS} )
target_link_options( app PUBLIC "-Wl,-Map=app.map,--cref" )