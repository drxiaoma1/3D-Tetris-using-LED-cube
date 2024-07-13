/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "block.h"
#include "fonts.h"
#include "st7789.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */
int time_from_start = 0;
uint8_t Game_State = 0;
int Score = 0;
int Auto_fall_time = 2000;
uint8_t forward_prev = 0;
uint8_t backward_prev = 0;
uint8_t left_prev = 0;
uint8_t right_prev = 0;
uint8_t rotate_prev = 0;
uint8_t down_prev = 0;
int map[11][5][5];

void Delay_ns(uint16_t ns)
{
  uint32_t time = ns / 60 + 1;
  for (int i=0; i<time; i++)
    {
      __NOP();
    }
}

void LED_Scan()
{
  for(int i=10;i>=0;i--)
  {
    RCLK2_L;
    for(int t=0;t<16;t++)
    {
      SRCLK2_L;
      if(t == i)
      {
        SER2_H;
      }
      else
      {
        SER2_L;
      }
      SRCLK2_H;
    }
    RCLK2_H;

    uint8_t target[32] = {0};

    for(int j=0;j<5;j++)
      for(int k=0;k<5;k++)
      {
        if(map[i][j][k] == 1 || map[i][j][k] == 2)
          target[5*j+k] = 1;
      }

    RCLK1_L;
    for(int t=0;t<32;t++)
    {
      SRCLK1_L;
      if(target[t])
      {
        SER1_H;
      }
      else
      {
        SER1_L;
      }
      SRCLK1_H;
    }
    RCLK1_H;

    HAL_Delay(0);

  }
}

void Roll_Scan()
{
  uint8_t forward_curr = HAL_GPIO_ReadPin(RK_forward_GPIO_Port, RK_forward_Pin);
  uint8_t backward_curr = HAL_GPIO_ReadPin(RK_backward_GPIO_Port, RK_backward_Pin);
  uint8_t left_curr = HAL_GPIO_ReadPin(RK_left_GPIO_Port, RK_left_Pin);
  uint8_t right_curr = HAL_GPIO_ReadPin(RK_right_GPIO_Port, RK_right_Pin);
  uint8_t rotate_curr = HAL_GPIO_ReadPin(RK_rotate_GPIO_Port, RK_rotate_Pin);
  uint8_t down_curr = HAL_GPIO_ReadPin(DW_KC_GPIO_Port, DW_KC_Pin);

  if(!forward_prev && forward_curr)
    {
      Temporary_forward();
    }
  forward_prev = forward_curr;

  if(!backward_prev && backward_curr)
    {
      Temporary_backward();
    }
  backward_prev = backward_curr;

  if(!left_prev && left_curr)
    {
      Temporary_left();
    }
  left_prev = left_curr;

  if(!right_prev && right_curr)
    {
      Temporary_right();
    }
  right_prev = right_curr;

  if(!rotate_prev && rotate_curr)
    {
      Temporary_rotate();
    }
  rotate_prev = rotate_curr;

  if(!down_prev && down_curr)
    {
      Temporary_down();
    }
  down_prev = down_curr;

}

void LCD_Score()
{
  char str[6];
  if(Score > 999999)
    Score = 999999;
  int tmp = Score;
  for(int i=5;i>=0;i--)
    {
      str[i] =tmp % 10 + '0';
      tmp /= 10;
    }
  if(Score > 1000)
    ST7789_WriteString(80, 110, str, Font_16x26, YELLOW, WHITE);
  else
    ST7789_WriteString(80, 110, str, Font_16x26, BLACK, WHITE);
}

void LCD_Over()
{
  for(int i=0;i<5;i++)
    {
      ST7789_WriteString(80, 110, "Game Over!", Font_16x26, WHITE, WHITE);
      HAL_Delay(200);
      ST7789_WriteString(80, 110, "Game Over!", Font_16x26, BLACK, WHITE);
      HAL_Delay(200);
    }
}

void restart()
{
  forward_prev = 0;
  backward_prev = 0;
  left_prev = 0;
  right_prev = 0;
  rotate_prev = 0;
  down_prev = 0;
  Game_State = 0;
  Score = 0;
  Auto_fall_time = 2000;
  SET_Temporary();

  for(int i=0;i<11;i++)
    for(int j=0;j<5;j++)
      for(int k=0;k<5;k++)
        map[i][j][k] = 0;

  LED_Scan();
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

  KR_H;
  RK_H;

  for(int i=0;i<11;i++)
    for(int j=0;j<5;j++)
      for(int k=0;k<5;k++)
	map[i][j][k] = 0;

  Game_State = 0;
  Score = 0;
  Auto_fall_time = 5000;
  forward_prev = 0;
  backward_prev = 0;
  left_prev = 0;
  right_prev = 0;
  rotate_prev = 0;
  down_prev = 0;

  SET_Temporary();
  Temporary_On();


  /*RCLK2_L;
  for(int i=0;i<16;i++)
  {
    SRCLK2_L;
      SER2_H;
    SRCLK2_H;
  }
  RCLK2_H;

  RCLK1_L;
  for(int i=0;i<32;i++)
  {
    SRCLK1_L;
    SER1_H;
    SRCLK1_H;
  }
  RCLK1_H;*/



  //ST7789_Init();
  //ST7789_Fill_Color(WHITE);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
      switch(Game_State)
      {
        case 0:
          LED_Scan();
          Roll_Scan();
          break;

        case 1:
          Eliminate();
          LED_Scan();
          //LCD_Score();
          Fail_or_not();
          break;

        case 2:
          //LCD_Over();
          HAL_Delay(5000);
          restart();
      }

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SER1_Pin|RCLK1_Pin|SRCLK1_Pin|SER2_Pin
                          |RCLK2_Pin|SRCLK2_Pin|BUZ_Pin|RK_Out_Pin
                          |ST7789_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DW_KR_Pin|ST7789_DC_Pin|ST7789_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SER1_Pin RCLK1_Pin SRCLK1_Pin SER2_Pin
                           RCLK2_Pin SRCLK2_Pin BUZ_Pin RK_Out_Pin
                           ST7789_CS_Pin */
  GPIO_InitStruct.Pin = SER1_Pin|RCLK1_Pin|SRCLK1_Pin|SER2_Pin
                          |RCLK2_Pin|SRCLK2_Pin|BUZ_Pin|RK_Out_Pin
                          |ST7789_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : DW_KR_Pin ST7789_DC_Pin ST7789_RST_Pin */
  GPIO_InitStruct.Pin = DW_KR_Pin|ST7789_DC_Pin|ST7789_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : DW_KC_Pin */
  GPIO_InitStruct.Pin = DW_KC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(DW_KC_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RK_left_Pin RK_forward_Pin */
  GPIO_InitStruct.Pin = RK_left_Pin|RK_forward_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : RK_backward_Pin */
  GPIO_InitStruct.Pin = RK_backward_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(RK_backward_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RK_right_Pin RK_rotate_Pin */
  GPIO_InitStruct.Pin = RK_right_Pin|RK_rotate_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
