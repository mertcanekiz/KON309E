/**
  ******************************************************************************
  * @file    main.c
  * @author  Mertcan Ekiz
  * @version V1.0.0
  * @date    18-May-2015
  * @brief   Blinking LEDs
 *
  ******************************************************************************
  */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
#include "main.h"
#include <stm32f0xx.h>

void LEDToggle(uint16_t delay);
void LEDOff();
void Delay(__IO uint32_t nTime);
void TimingDelay_Decrement(void);

#define FIRST_STATE 0
typedef enum {
    STATE_500_A = FIRST_STATE,
    STATE_500_B,
    STATE_200_A,
    STATE_200_B,
    STATE_100_A,
    STATE_100_B,
    STATE_20_A,
    STATE_20_B,
    STATE_OFF_A,
    STATE_OFF_B
} STATE;

uint8_t state = STATE_OFF_A;
uint16_t counter = 0;
static __IO uint32_t TimingDelay;

int main(void)
{
    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);
    STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);

    LEDOff();
    STM_EVAL_LEDOn(LED3);// Initialize the LEDs at an alternating state

    while (1)
    {
        switch (state)
        {
            // Each state toggles the LEDs as much milliseconds
            // as is written in their name.
            case STATE_500_A:
            case STATE_500_B:
                LEDToggle(500);
                break;
            case STATE_200_A:
            case STATE_200_B:
                LEDToggle(200);
                break;
            case STATE_100_A:
            case STATE_100_B:
                LEDToggle(100);
                break;
            case STATE_20_A:
            case STATE_20_B:
                LEDToggle(20);
                break;
            case STATE_OFF_A:
            case STATE_OFF_B:
                LEDOff();
                break;
            default:
                state = FIRST_STATE;
                break;
        }
        if (STM_EVAL_PBGetState(BUTTON_USER) == (1 - state % 2)) {
            // ^^^ This conditional is equivalent to:
            //
            //     if ((STM_EVAL_PBGetState(BUTTON_USER) == 1 && (state % 2 == 0)) ||
            //         (STM_EVAL_PBGetState(BUTTON_USER) == 0 && (state % 2 == 1))) {
            //
            // Which means that an even numbered state will go to the next state on a button press,
            // whereas an odd numbered state will go to the next state after a button release.

            if (state == STATE_OFF_B) {      // If we just came out of OFF state we need to
                STM_EVAL_LEDOff(LED3);       // restore the alternating behavior of the LEDs.
                STM_EVAL_LEDOn(LED4);
            }
            state++;
        }
        Delay(5);
    }
}

void LEDToggle(uint16_t delay)
{
    if (++counter > delay / 10) {
        STM_EVAL_LEDToggle(LED3);
        STM_EVAL_LEDToggle(LED4);
        counter = 0;
    }
}

void LEDOff()
{
    STM_EVAL_LEDOff(LED3);
    STM_EVAL_LEDOff(LED4);
}

void Delay(__IO uint32_t nTime)
{
    TimingDelay = nTime * 2000; // This 2000 value is arbitrary and roughly eyeballed;
                                // The code needs a better delay implementation.
    while (TimingDelay != 0)
        TimingDelay_Decrement();
}

void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    {
        TimingDelay--;
    }
}
