//----------------------------------------------------------------------
// #### PROYECTO PARA PLACA ARDUINO STM32 - Arduino Blue Pill Board ####
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ## @CPU:    STM32F103
// ##
// #### MAIN.C ############################################
//---------------------------------------------------------

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "hard.h"

#include "timer.h"
#include "gpio.h"
#include "usart.h"

#include <stdio.h>



/* Externals ------------------------------------------------------------------*/
//--- Externals para avisar data ready en usart
volatile unsigned char usart1_have_data;
volatile unsigned char usart2_have_data;
volatile unsigned char usart3_have_data;
#ifdef STM32F10X_HD
volatile unsigned char usart4_have_data;
volatile unsigned char usart5_have_data;
#endif

unsigned short comms_messages = 0;
char buffSendErr[64];

//--- Externals para enviar keepalive por UART
#define TIME_RUN_DEF 250
volatile unsigned short timeRun = TIME_RUN_DEF;

//--- Externals para muestreos de corriente con el ADC
volatile unsigned char flagMuestreo = 0;
volatile unsigned char take_current_samples = 0;

//--- Externals para armar seniales y comprobar el TIM5 en el inicio del programa
volatile unsigned int session_warming_up_channel_1_stage_time = 0;

//--- Externals para el BUZZER
unsigned short buzzer_timeout = 0;

//--- Externals de los timers
volatile unsigned short wait_ms_var = 0;
volatile unsigned short comms_timeout = 0;


/* Globals ------------------------------------------------------------------*/

//--- Module Functions Declarations ----------
void TimingDelay_Decrement(void);
extern void EXTI0_IRQHandler (void);

//--- Module Function Definitions ----------

int main (void)
{
    unsigned char i = 0;
    unsigned long ii = 0;

    //Configuracion systick    
    if (SysTick_Config(72000))
    {
        while (1)	/* Capture error */
        {
            if (LED)
                LED_OFF;
            else
                LED_ON;

            for (i = 0; i < 255; i++)
            {
                asm (	"nop \n\t"
                        "nop \n\t"
                        "nop \n\t" );
            }
        }
    }

    // Configuracion led. & Enabled Channels
    GpioInit();

    //enciendo usart1
    Usart1Config();

    // //enciendo usart2 para comunicacion con micros
    // Usart2Config();
    

    //-- Welcome Messages --------------------
#ifdef HARD
    Usart1Send(HARD);
    Wait_ms(100);    
#else
#error	"No Hardware defined in hard.h file"
#endif

#ifdef SOFT
    Usart1Send(SOFT);
    Wait_ms(100);    
#else
#error	"No Soft Version defined in hard.h file"
#endif
#ifdef FEATURES
    Usart1Send((const char *) FEATURES);
    Wait_ms(100);
#endif

    TIM_1_Init();
    TIM_3_Init();

    UpdateTIMSync(DUTY_FOR_DMAX);
    
    while (1)
    {
        LED_ON;
        Wait_ms(1000);
        LED_OFF;
        Wait_ms(1000);
    }

    
    //---- Prueba Usart3 ----------
    // while (1)
    // {
    //     // Wait_ms(2000);
    //     L_ALARMA_OFF;
    //     Usart3Send("HOLA!!!\n");
    //     Wait_ms(100);

    //     if (usart3_have_data)
    //     {
    //         usart3_have_data = 0;
    //         L_ALARMA_ON;
    //         ReadUsart3Buffer(local_buff, 64);
    //         if (strcmp((const char *) "HOLA!!!", local_buff) == 0)
    //             L_ZONA_ON;
    //         else
    //             L_ZONA_OFF;

    //         Wait_ms(100);
    //         L_ALARMA_OFF;
    //         L_ZONA_OFF;
    //         Wait_ms(1900);
    //     }
    // }
    //---- Fin Prueba Usart3 ----------

    //---- Prueba contra PC o Raspberry ----------
    // while (1)
    // {
    //     UpdateRaspberryMessages();
    // }
    //---- Fin Prueba contra PC o Raspberry ----------    


    //---- Prueba Usart3 loop en terminal ----------
    // while (1)
    // {
    //     if (usart3_have_data)
    //     {
    //         usart3_have_data = 0;
    //         L_ALARMA_ON;
    //         ReadUsart3Buffer(local_buff, 64);
    //         Wait_ms(1000);
    //         i = strlen(local_buff);
    //         if (i < 62)
    //         {
    //             local_buff[i] = '\n';
    //             local_buff[i+1] = '\0';
    //             Usart3Send(local_buff);
    //         }
    //         L_ALARMA_OFF;
    //     }
    // }
    //---- Fin Prueba Usart3 loop en terminal ----------

    //---- Prueba Usart3 envia caracter solo 'd' ----------
    // while (1)
    // {
    //     unsigned char snd = 'd';
    //     Usart3SendUnsigned(&snd, 1);
    //     // USART3->DR = 'd';
    //     Wait_ms(100);
    // }
    //---- Fin Prueba Usart3 envia caracter solo 'd' ----------
}

//--- End of Main ---//

//--- Module Functions Definitions ----------------------
void TimingDelay_Decrement(void)
{
    if (wait_ms_var)
        wait_ms_var--;

    if (comms_timeout)
        comms_timeout--;
    
    // if (timer_standby)
    //     timer_standby--;

    // if (timer_filters)
    //     timer_filters--;
    
    // if (timer_led)
    //     timer_led--;

    // if (timer_led_pwm < 0xFFFF)
    //     timer_led_pwm ++;
    
}

void EXTI0_IRQHandler (void)
{
    if(EXTI->PR & 0x00000001)	//Line0
    {
        if (LED)
            LED_OFF;
        else
            LED_ON;
        
        //reviso que mosfet generaba
        // if (CTRL_M_A)
        // {
        //     DisablePreload_MosfetA();
        //     UpdateTIM_MosfetA(0);
        //     EnablePreload_MosfetA();
        //     UpdateTIM_MosfetA(DUTY_FOR_DMAX);
        // }
        // else if (CTRL_M_B)
        // {
        //     DisablePreload_MosfetB();
        //     UpdateTIM_MosfetB(0);
        //     EnablePreload_MosfetB();
        //     UpdateTIM_MosfetB(DUTY_FOR_DMAX);            
        // }
        // else
        // {
        //     //llegue muy tarde con la INT
        // }

        // current_excess = 1;


        EXTI->PR |= 0x00000001;
    }
}

//--- end of file ---//

