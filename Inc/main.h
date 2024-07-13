/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdlib.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

extern uint8_t Game_State;
extern int Score;
extern int Auto_fall_time;
extern int time_from_start;
extern int map[11][5][5];

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SER1_Pin GPIO_PIN_1
#define SER1_GPIO_Port GPIOA
#define RCLK1_Pin GPIO_PIN_2
#define RCLK1_GPIO_Port GPIOA
#define SRCLK1_Pin GPIO_PIN_3
#define SRCLK1_GPIO_Port GPIOA
#define SER2_Pin GPIO_PIN_4
#define SER2_GPIO_Port GPIOA
#define RCLK2_Pin GPIO_PIN_5
#define RCLK2_GPIO_Port GPIOA
#define SRCLK2_Pin GPIO_PIN_6
#define SRCLK2_GPIO_Port GPIOA
#define BUZ_Pin GPIO_PIN_7
#define BUZ_GPIO_Port GPIOA
#define DW_KR_Pin GPIO_PIN_0
#define DW_KR_GPIO_Port GPIOB
#define DW_KC_Pin GPIO_PIN_1
#define DW_KC_GPIO_Port GPIOB
#define RK_left_Pin GPIO_PIN_9
#define RK_left_GPIO_Port GPIOA
#define RK_backward_Pin GPIO_PIN_6
#define RK_backward_GPIO_Port GPIOC
#define RK_forward_Pin GPIO_PIN_10
#define RK_forward_GPIO_Port GPIOA
#define RK_Out_Pin GPIO_PIN_11
#define RK_Out_GPIO_Port GPIOA
#define ST7789_CS_Pin GPIO_PIN_15
#define ST7789_CS_GPIO_Port GPIOA
#define ST7789_DC_Pin GPIO_PIN_4
#define ST7789_DC_GPIO_Port GPIOB
#define ST7789_SPI_Pin GPIO_PIN_5
#define ST7789_SPI_GPIO_Port GPIOB
#define RK_right_Pin GPIO_PIN_6
#define RK_right_GPIO_Port GPIOB
#define RK_rotate_Pin GPIO_PIN_7
#define RK_rotate_GPIO_Port GPIOB
#define ST7789_RST_Pin GPIO_PIN_8
#define ST7789_RST_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define SER1_H SER1_GPIO_Port->ODR |= SER1_Pin;
#define SER1_L SER1_GPIO_Port->ODR &= ~SER1_Pin;
#define RCLK1_H RCLK1_GPIO_Port->ODR |= RCLK1_Pin;
#define RCLK1_L RCLK1_GPIO_Port->ODR &= ~RCLK1_Pin;
#define SRCLK1_H SRCLK1_GPIO_Port->ODR |= SRCLK1_Pin;
#define SRCLK1_L SRCLK1_GPIO_Port->ODR &= ~SRCLK1_Pin;
#define SER2_H SER2_GPIO_Port->ODR |= SER2_Pin;
#define SER2_L SER2_GPIO_Port->ODR &= ~SER2_Pin;
#define RCLK2_H RCLK2_GPIO_Port->ODR |= RCLK2_Pin;
#define RCLK2_L RCLK2_GPIO_Port->ODR &= ~RCLK2_Pin;
#define SRCLK2_H SRCLK2_GPIO_Port->ODR |= SRCLK2_Pin;
#define SRCLK2_L SRCLK2_GPIO_Port->ODR &= ~SRCLK2_Pin;
#define BUZ_H BUZ_GPIO_Port->ODR |= BUZ_Pin;
#define BUZ_L BUZ_GPIO_Port->ODR &= ~BUZ_Pin;
#define KR_H DW_KR_GPIO_Port->ODR |= DW_KR_Pin;
#define KR_L DW_KR_GPIO_Port->ODR &= ~DW_KR_Pin;
#define RK_H RK_Out_GPIO_Port->ODR |= RK_Out_Pin;
#define RK_L RK_Out_GPIO_Port->ODR &= ~RK_Out_Pin;



/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
