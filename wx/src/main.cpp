/**
 * @file main.cpp
 * @author Chandler Keep (chandlersamkeep@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-18
 * 
 * @copyright Copyright (c)
 * 
 */
#include "main.hpp"

void main(void)
{
	#if defined(CONFIG_SOC_STM32H735XX)
		__GPIOC_CLK_ENABLE();
	#endif
	while(1){
		printk("Hello World!\n");
		k_msleep(1000);
	}
}