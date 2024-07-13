/*
 * block.h
 *
 *  Created on: Jul 6, 2024
 *      Author: mmk20
 */

#ifndef INC_BLOCK_H_
#define INC_BLOCK_H_

#include "main.h"


struct blocks_controlled
{
  uint8_t x;
  uint8_t y;
  uint8_t z;//(x,y,z)
  uint8_t kind;//1~5
  uint8_t state;//1~12
};

extern struct blocks_controlled Temporary;

void SET_Temporary();

void Temporary_On();
void Temporary_Off();
//void Block_On(uint8_t x, uint8_t y, uint8_t z);
//void Block_Off(uint8_t x, uint8_t y, uint8_t z);

void Temporary_forward();
void Temporary_backward();
void Temporary_left();
void Temporary_right();
void Temporary_rotate();
void Temporary_down();

//void Temporary_auto_down();
//use systick instead

uint8_t Block_or_not();
uint8_t Lock_or_not();
void Lock_Temporary();

void Eliminate();
void Fail_or_not();


#endif /* INC_BLOCK_H_ */
