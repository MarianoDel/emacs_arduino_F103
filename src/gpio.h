//---------------------------------------------
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ## @CPU:    STM32F103
// ##
// #### GPIO.H ################################
//---------------------------------------------

#ifndef __GPIO_H_
#define __GPIO_H_

//-- Configurations
#define USE_EXTERNAL_INTS

//-- Exported Macros --------------------

//--- RCC clkEnable ---//
#define RCC_GPIOA_CLK (RCC->APB2ENR & 0x00000004)
#define RCC_GPIOA_CLKEN RCC->APB2ENR |= 0x00000004
#define RCC_GPIOA_CLKDIS RCC->APB2ENR &= ~0x00000004

#define RCC_GPIOB_CLK (RCC->APB2ENR & 0x00000008)
#define RCC_GPIOB_CLKEN RCC->APB2ENR |= 0x00000008
#define RCC_GPIOB_CLKDIS RCC->APB2ENR &= ~0x00000008

#define RCC_GPIOC_CLK (RCC->APB2ENR & 0x00000010)
#define RCC_GPIOC_CLKEN RCC->APB2ENR |= 0x00000010
#define RCC_GPIOC_CLKDIS RCC->APB2ENR &= ~0x00000010

#define RCC_GPIOD_CLK (RCC->APB2ENR & 0x00000020)
#define RCC_GPIOD_CLKEN RCC->APB2ENR |= 0x00000020
#define RCC_GPIOD_CLKDIS RCC->APB2ENR &= ~0x00000020

#define RCC_AFIO_CLK (RCC->APB2ENR & 0x00000001)
#define RCC_AFIO_CLKEN RCC->APB2ENR |= 0x00000001
#define RCC_AFIO_CLKDIS RCC->APB2ENR &= ~0x00000001

#define RCC_AFIO_CLK       (RCC->APB2ENR & 0x00000001)
#define RCC_AFIO_CLKEN     RCC->APB2ENR |= 0x00000001
#define RCC_AFIO_CLKDIS    RCC->APB2ENR &= ~0x00000001

// #define RCC_GPIOA_clk (RCC->APB2ENR & 0x00000004)
// #define RCC_GPIOA_clkEnable RCC->APB2ENR |= 0x00000004
// #define RCC_GPIOA_clkDisable RCC->APB2ENR &= ~0x00000004

// #define RCC_GPIOB_clk (RCC->APB2ENR & 0x00000008)
// #define RCC_GPIOB_clkEnable RCC->APB2ENR |= 0x00000008
// #define RCC_GPIOB_clkDisable RCC->APB2ENR &= ~0x00000008

// #define RCC_GPIOC_clk (RCC->APB2ENR & 0x00000010)
// #define RCC_GPIOC_clkEnable RCC->APB2ENR |= 0x00000010
// #define RCC_GPIOC_clkDisable RCC->APB2ENR &= ~0x00000010

// #define RCC_GPIOD_clk (RCC->APB2ENR & 0x00000020)
// #define RCC_GPIOD_clkEnable RCC->APB2ENR |= 0x00000020
// #define RCC_GPIOD_clkDisable RCC->APB2ENR &= ~0x00000020

// #define RCC_AFIO_CLK (RCC->APB2ENR & 0x00000001)
// #define RCC_AFIO_CLKEN RCC->APB2ENR |= 0x00000001
// #define RCC_AFIO_CLKDIS RCC->APB2ENR &= ~0x00000001

// #define RCC_TIM1_CLK (RCC->APB2ENR & 0x00000800)
// #define RCC_TIM1_CLKEN RCC->APB2ENR |= 0x00000800
// #define RCC_TIM1_CLKDIS RCC->APB2ENR &= ~0x00000800

// #define RCC_TIM2_CLK (RCC->APB1ENR & 0x00000001)
// #define RCC_TIM2_CLKEN RCC->APB1ENR |= 0x00000001
// #define RCC_TIM2_CLKDIS RCC->APB1ENR &= ~0x00000001

// #define RCC_TIM3_CLK (RCC->APB1ENR & 0x00000002)
// #define RCC_TIM3_CLKEN RCC->APB1ENR |= 0x00000002
// #define RCC_TIM3_CLKDIS RCC->APB1ENR &= ~0x00000002

// #define RCC_TIM4_CLK (RCC->APB1ENR & 0x00000004)
// #define RCC_TIM4_CLKEN RCC->APB1ENR |= 0x00000004
// #define RCC_TIM4_CLKDIS RCC->APB1ENR &= ~0x00000004

// #define RCC_TIM5_CLK (RCC->APB1ENR & 0x00000008)
// #define RCC_TIM5_CLKEN RCC->APB1ENR |= 0x00000008
// #define RCC_TIM5_CLKDIS RCC->APB1ENR &= ~0x00000008

// #define RCC_USART1_CLK (RCC->APB2ENR & 0x00004000)
// #define RCC_USART1_CLKEN RCC->APB2ENR |= 0x00004000
// #define RCC_USART1_CLKDIS RCC->APB2ENR &= ~0x00004000

// #define RCC_USART2_CLK (RCC->APB1ENR & 0x00020000)
// #define RCC_USART2_CLKEN RCC->APB1ENR |= 0x00020000
// #define RCC_USART2_CLKDIS RCC->APB1ENR &= ~0x00020000

// #define RCC_USART3_CLK (RCC->APB1ENR & 0x00040000)
// #define RCC_USART3_CLKEN RCC->APB1ENR |= 0x00040000
// #define RCC_USART3_CLKDIS RCC->APB1ENR &= ~0x00040000

// #define RCC_UART4_CLK (RCC->APB1ENR & 0x00080000)
// #define RCC_UART4_CLKEN RCC->APB1ENR |= 0x00080000
// #define RCC_UART4_CLKDIS RCC->APB1ENR &= ~0x00080000

// #define RCC_UART5_CLK (RCC->APB1ENR & 0x00100000)
// #define RCC_UART5_CLKEN RCC->APB1ENR |= 0x00100000
// #define RCC_UART5_CLKDIS RCC->APB1ENR &= ~0x00100000

// #define RCC_ADC1_CLK (RCC->APB2ENR & 0x00000200)
// #define RCC_ADC1_CLKEN RCC->APB2ENR |= 0x00000200
// #define RCC_ADC1_CLKDIS RCC->APB2ENR &= ~0x00000200

// #define RCC_ADC2_CLK (RCC->APB2ENR & 0x00000400)
// #define RCC_ADC2_CLKEN RCC->APB2ENR |= 0x00000400
// #define RCC_ADC2_CLKDIS RCC->APB2ENR &= ~0x00000400

// #define RCC_ADC3_CLK (RCC->APB2ENR & 0x00008000)
// #define RCC_ADC3_CLKEN RCC->APB2ENR |= 0x00008000
// #define RCC_ADC3_CLKDIS RCC->APB2ENR &= ~0x00008000

/* Includes ------------------------------------------------------------------*/

//--- Exported Functions ------------------------------
void GpioInit(void);

#endif
