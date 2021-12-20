/**
 * @file main.hpp
 * @author chandler keep (chandlersamkeep@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <zephyr.h>
#include <kernel.h>
#include <console/console.h>
#if defined(CONFIG_SOC_STM32H735XX)
	#include <stm32h7xx_hal.h>
	#include <stm32h7xx_hal_gpio.h>
#endif