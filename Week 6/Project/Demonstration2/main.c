/**
  ******************************************************************************
  * @file    main.c 
  * @author  Mertcan Ekiz
  * @version V1.0.0
  * @date    25-Nov-2019
  * @brief   Main program body
	*
	*
	*
  ******************************************************************************
  */ 
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
#include "main.h"
#include <stm32f0xx.h>
#define PERIOD 1000
#define PRESCALER 48000
/** @addtogroup STM32F0-Discovery_Demo
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
static __IO uint16_t TIM3_Period;
static const uint16_t TIM3_Prescaler = 48000;
static __IO uint8_t currentState;

/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nTime);
void TIM_Config(void);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
    uint8_t button;
    uint8_t button_accum[2] = { 0, 0 };
    uint8_t button_state = 0;
	STM_EVAL_LEDInit(LED3);
	STM_EVAL_LEDInit(LED4);
	STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);
    SysTick_Config(SystemCoreClock / 1000);
    setState(STATE_OFF_A);
    
	while(1)
    {
        // The STM32F0 Discovery button has a lot of switch bouncing issue. See:
        // https://www.allaboutcircuits.com/technical-articles/switch-bounce-how-to-deal-with-it/
        //
        // Electrically, this can be dealt with using a capacitor,
        // so this is a "capacitor" implementation that accumulates and
        // when the button is held longer than ~10ms, we consider it to be ON.
        
        uint8_t currentButton = STM_EVAL_PBGetState(BUTTON_USER);
        button ^= currentButton;
        if (button == 0) {
            button_accum[currentButton]++;
        } else {
            button_accum[currentButton] = 0;
        }
        button = currentButton;
        if (button_accum[currentButton] > 10) {
            button_state = currentButton;
            button_accum[0] = 0;
            button_accum[1] = 0;
        }
        
        // Finite state machine
        switch(currentState) {
            case STATE_OFF_A:
                STM_EVAL_LEDOff(LED3);
                STM_EVAL_LEDOff(LED4);
                TIM_DeInit(TIM3);
                if (!button_state) setState(STATE_OFF_B);
                break;
            case STATE_OFF_B:
                if (button_state) {
                    setState(STATE_5S_A);
                    TIM_Config();
                }
                break;
            case STATE_3S_A:
                if (!button_state) setState(STATE_3S_B);
                STM_EVAL_LEDOn(LED3);
                STM_EVAL_LEDOff(LED4);
                break;
            case STATE_3S_B:
                if (button_state) setState(STATE_OFF_A);
                STM_EVAL_LEDOn(LED3);
                STM_EVAL_LEDOff(LED4);
                break;
            case STATE_5S_A:
                if (!button_state) setState(STATE_5S_B);
                STM_EVAL_LEDOff(LED3);
                STM_EVAL_LEDOn(LED4);
                break;
            case STATE_5S_B:
                if (button_state) setState(STATE_OFF_A);
                STM_EVAL_LEDOff(LED3);
                STM_EVAL_LEDOn(LED4);
                break;
        }
        Delay(1);
	}
}

void TIM_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    TIM_TimeBaseStructure.TIM_Period = TIM3_Period;
    TIM_TimeBaseStructure.TIM_Prescaler = TIM3_Prescaler;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    TIM_ITConfig(TIM3, TIM_IT_CC3, ENABLE);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_Cmd(TIM3, ENABLE);
}

void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00) TimingDelay--;
}
void Delay(__IO uint32_t nTime) {
	TimingDelay = nTime;
	while (TimingDelay > 0x00);
}

void setPeriod(uint16_t period)
{
    TIM3_Period = period;
}

void setState(uint8_t state)
{
    currentState = state;
    if (state == STATE_3S_A || state ==  STATE_3S_B) setPeriod(300);
    if (state == STATE_5S_A || state ==  STATE_5S_B) setPeriod(700);
}

uint8_t getState(void)
{
    return currentState;
}
