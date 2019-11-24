/**
  ******************************************************************************
  * @file    main.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    23-March-2012
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  * Define to prevent recursive inclusion -------------------------------------*/
	
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "stm32f0_discovery.h"

/* Exported types ------------------------------------------------------------*/
typedef enum {
    STATE_OFF_A = 0,
    STATE_OFF_B,
    STATE_3S_A,
    STATE_3S_B,
    STATE_5S_A,
    STATE_5S_B
} State;
/* Private define ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);
void TIM_Config(void);
void setPeriod(uint16_t period);
void setState(uint8_t state);
uint8_t getState(void);
#endif /* __MAIN_H */

