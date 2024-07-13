/*
 * block.c
 *
 *  Created on: Jul 6, 2024
 *      Author: mmk20
 */

#include "block.h"

struct blocks_controlled Temporary;

void SET_Temporary()
{
  Temporary.x = 2;
  Temporary.y = 2;
  Temporary.z = 10;
  Temporary.state = 1;

  srand(HAL_GetTick());
  Temporary.kind = rand()%5 + 1;
}

void Temporary_On()
{
  uint8_t x = Temporary.x;
  uint8_t y = Temporary.y;
  uint8_t z = Temporary.z;
  switch(Temporary.kind)
  {
    case 1:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z][x][y+1] = 2;map[z][x+1][y+1] = 2;break;
	case 2:
	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x][y+1] = 2;map[z][x-1][y+1] = 2;break;
	case 3:
	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x][y-1] = 2;map[z][x-1][y-1] = 2;break;
	case 4:
	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z][x][y-1] = 2;map[z][x+1][y-1] = 2;break;
	case 5:
	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z+1][x][y] = 2;map[z+1][x][y+1] = 2;break;
	case 6:
	  map[z][x][y] = 2;map[z][x][y-1] = 2;map[z+1][x][y] = 2;map[z+1][x][y-1] = 2;break;
	case 7:
	  map[z][x][y] = 2;map[z][x][y-1] = 2;map[z-1][x][y] = 2;map[z-1][x][y-1] = 2;break;
	case 8:
	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z-1][x][y] = 2;map[z-1][x][y+1] = 2;break;
	case 9:
	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z+1][x][y] = 2;map[z+1][x+1][y] = 2;break;
	case 10:
	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z-1][x][y] = 2;map[z-1][x+1][y] = 2;break;
	case 11:
	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z-1][x][y] = 2;map[z-1][x-1][y] = 2;break;
	case 12:
	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z+1][x][y] = 2;map[z+1][x-1][y] = 2;break;
      }
      break;
    case 2:
      switch(Temporary.state)
      {
      	case 1:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z][x+2][y] = 2;map[z][x][y+1] = 2;break;
      	case 2:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x][y+1] = 2;map[z][x][y+2] = 2;break;
      	case 3:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x][y-1] = 2;map[z][x-2][y] = 2;break;
      	case 4:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z][x][y-1] = 2;map[z][x][y-2] = 2;break;
      	case 5:
      	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z+1][x][y] = 2;map[z+2][x][y] = 2;break;
      	case 6:
      	  map[z][x][y] = 2;map[z][x][y-1] = 2;map[z+1][x][y] = 2;map[z][x][y-2] = 2;break;
      	case 7:
      	  map[z][x][y] = 2;map[z][x][y-1] = 2;map[z-1][x][y] = 2;map[z][x][y-2] = 2;break;
      	case 8:
      	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z-1][x][y] = 2;map[z][x][y+2] = 2;break;
      	case 9:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z+1][x][y] = 2;map[z+2][x][y] = 2;break;
      	case 10:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z-1][x][y] = 2;map[z][x+2][y] = 2;break;
      	case 11:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z-1][x][y] = 2;map[z-2][x][y] = 2;break;
      	case 12:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x-2][y] = 2;map[z+1][x][y] = 2;break;
       }
       break;
    case 3:
      switch(Temporary.state)
      {
      	case 1:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z][x][y+1] = 2;map[z][x-1][y+1] = 2;break;
      	case 2:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x][y+1] = 2;map[z][x-1][y-1] = 2;break;
      	case 3:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x][y-1] = 2;map[z][x+1][y-1] = 2;break;
      	case 4:
      	  map[z][x][y] = 2;map[z][x][y-1] = 2;map[z][x+1][y] = 2;map[z][x+1][y+1] = 2;break;
      	case 5:
      	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z+1][x][y] = 2;map[z-1][x][y+1] = 2;break;
      	case 6:
      	  map[z][x][y] = 2;map[z][x][y-1] = 2;map[z+1][x][y] = 2;map[z+1][x][y+1] = 2;break;
      	case 7:
      	  map[z][x][y] = 2;map[z][x][y-1] = 2;map[z-1][x][y] = 2;map[z+1][x][y-1] = 2;break;
      	case 8:
      	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z-1][x][y] = 2;map[z-1][x][y-1] = 2;break;
      	case 9:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z+1][x][y] = 2;map[z-1][x+1][y] = 2;break;
      	case 10:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z-1][x][y] = 2;map[z-1][x-1][y] = 2;break;
      	case 11:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z-1][x][y] = 2;map[z+1][x-1][y] = 2;break;
      	case 12:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z+1][x][y] = 2;map[z+1][x+1][y] = 2;break;
       }
       break;
    case 4:
      switch(Temporary.state)
      {
      	case 1:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z][x][y+1] = 2;map[z][x-1][y] = 2;break;
      	case 2:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x][y+1] = 2;map[z][x][y-1] = 2;break;
      	case 3:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x][y-1] = 2;map[z][x+1][y] = 2;break;
      	case 4:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z][x][y-1] = 2;map[z][x][y+1] = 2;break;
      	case 5:
      	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z+1][x][y] = 2;map[z][x][y-1] = 2;break;
      	case 6:
      	  map[z][x][y] = 2;map[z][x][y-1] = 2;map[z+1][x][y] = 2;map[z-1][x][y] = 2;break;
      	case 7:
      	  map[z][x][y] = 2;map[z][x][y-1] = 2;map[z-1][x][y] = 2;map[z][x][y+1] = 2;break;
      	case 8:
      	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z-1][x][y] = 2;map[z+1][x][y] = 2;break;
      	case 9:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z+1][x][y] = 2;map[z][x-1][y] = 2;break;
      	case 10:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z-1][x][y] = 2;map[z+1][x][y] = 2;break;
      	case 11:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z-1][x][y] = 2;map[z][x+1][y] = 2;break;
      	case 12:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z+1][x][y] = 2;map[z-1][x][y] = 2;break;
       }
       break;
    case 5:
      switch(Temporary.state)
      {
      	case 1:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z][x+2][y] = 2;map[z][x-1][y] = 2;break;
      	case 2:
      	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z][x][y+2] = 2;map[z][x][y-1] = 2;break;
      	case 3:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x-2][y] = 2;map[z][x+1][y] = 2;break;
      	case 4:
      	  map[z][x][y] = 2;map[z][x][y-2] = 2;map[z][x][y-1] = 2;map[z][x][y+1] = 2;break;
      	case 5:
      	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z][x][y+2] = 2;map[z][x][y-1] = 2;break;
      	case 6:
      	  map[z][x][y] = 2;map[z+1][x][y] = 2;map[z+2][x][y] = 2;map[z-1][x][y] = 2;break;
      	case 7:
      	  map[z][x][y] = 2;map[z][x][y+1] = 2;map[z][x][y-1] = 2;map[z][x][y-2] = 2;break;
      	case 8:
      	  map[z][x][y] = 2;map[z-1][x][y] = 2;map[z-2][x][y] = 2;map[z+1][x][y] = 2;break;
      	case 9:
      	  map[z][x][y] = 2;map[z+1][x][y] = 2;map[z+2][x][y] = 2;map[z-1][x][y] = 2;break;
      	case 10:
      	  map[z][x][y] = 2;map[z][x+1][y] = 2;map[z][x+2][y] = 2;map[z][x-1][y] = 2;break;
      	case 11:
      	  map[z][x][y] = 2;map[z-1][x][y] = 2;map[z-2][x][y] = 2;map[z+1][x][y] = 2;break;
      	case 12:
      	  map[z][x][y] = 2;map[z][x-1][y] = 2;map[z][x-2][y] = 2;map[z][x+1][y] = 2;break;
       }
       break;
  }
}

void Temporary_Off()
{
  uint8_t x = Temporary.x;
  uint8_t y = Temporary.y;
  uint8_t z = Temporary.z;
  switch(Temporary.kind)
  {
    case 1:
      switch(Temporary.state)
      {
      case 1:
	map[z][x][y] = 0;map[z][x+1][y] = 0;map[z][x][y+1] = 0;map[z][x+1][y+1] = 0;break;
      case 2:
	map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x][y+1] = 0;map[z][x-1][y+1] = 0;break;
      case 3:
	map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x][y-1] = 0;map[z][x-1][y-1] = 0;break;
      case 4:
	map[z][x][y] = 0;map[z][x+1][y] = 0;map[z][x][y-1] = 0;map[z][x+1][y-1] = 0;break;
      case 5:
	map[z][x][y] = 0;map[z][x][y+1] = 0;map[z+1][x][y] = 0;map[z+1][x][y+1] = 0;break;
      case 6:
	map[z][x][y] = 0;map[z][x][y-1] = 0;map[z+1][x][y] = 0;map[z+1][x][y-1] = 0;break;
      case 7:
	map[z][x][y] = 0;map[z][x][y-1] = 0;map[z-1][x][y] = 0;map[z-1][x][y-1] = 0;break;
      case 8:
	map[z][x][y] = 0;map[z][x][y+1] = 0;map[z-1][x][y] = 0;map[z-1][x][y+1] = 0;break;
      case 9:
	map[z][x][y] = 0;map[z][x+1][y] = 0;map[z+1][x][y] = 0;map[z+1][x+1][y] = 0;break;
      case 10:
	map[z][x][y] = 0;map[z][x+1][y] = 0;map[z-1][x][y] = 0;map[z-1][x+1][y] = 0;break;
      case 11:
	map[z][x][y] = 0;map[z][x-1][y] = 0;map[z-1][x][y] = 0;map[z-1][x-1][y] = 0;break;
      case 12:
	map[z][x][y] = 0;map[z][x-1][y] = 0;map[z+1][x][y] = 0;map[z+1][x-1][y] = 0;break;
      }
      break;
    case 2:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z][x+2][y] = 0;map[z][x][y+1] = 0;break;
	case 2:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x][y+1] = 0;map[z][x][y+2] = 0;break;
	case 3:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x][y-1] = 0;map[z][x-2][y] = 0;break;
	case 4:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z][x][y-1] = 0;map[z][x][y-2] = 0;break;
	case 5:
	  map[z][x][y] = 0;map[z][x][y+1] = 0;map[z+1][x][y] = 0;map[z+2][x][y] = 0;break;
	case 6:
	  map[z][x][y] = 0;map[z][x][y-1] = 0;map[z+1][x][y] = 0;map[z][x][y-2] = 0;break;
	case 7:
	  map[z][x][y] = 0;map[z][x][y-1] = 0;map[z-1][x][y] = 0;map[z][x][y-2] = 0;break;
	case 8:
	  map[z][x][y] = 0;map[z][x][y+1] = 0;map[z-1][x][y] = 0;map[z][x][y+2] = 0;break;
	case 9:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z+1][x][y] = 0;map[z+2][x][y] = 0;break;
	case 10:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z-1][x][y] = 0;map[z][x+2][y] = 0;break;
	case 11:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z-1][x][y] = 0;map[z-2][x][y] = 0;break;
	case 12:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x-2][y] = 0;map[z+1][x][y] = 0;break;
       }
       break;
    case 3:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z][x][y+1] = 0;map[z][x-1][y+1] = 0;break;
	case 2:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x][y+1] = 0;map[z][x-1][y-1] = 0;break;
	case 3:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x][y-1] = 0;map[z][x+1][y-1] = 0;break;
	case 4:
	  map[z][x][y] = 0;map[z][x][y-1] = 0;map[z][x+1][y] = 0;map[z][x+1][y+1] = 0;break;
	case 5:
	  map[z][x][y] = 0;map[z][x][y+1] = 0;map[z+1][x][y] = 0;map[z-1][x][y+1] = 0;break;
	case 6:
	  map[z][x][y] = 0;map[z][x][y-1] = 0;map[z+1][x][y] = 0;map[z+1][x][y+1] = 0;break;
	case 7:
	  map[z][x][y] = 0;map[z][x][y-1] = 0;map[z-1][x][y] = 0;map[z+1][x][y-1] = 0;break;
	case 8:
	  map[z][x][y] = 0;map[z][x][y+1] = 0;map[z-1][x][y] = 0;map[z-1][x][y-1] = 0;break;
	case 9:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z+1][x][y] = 0;map[z-1][x+1][y] = 0;break;
	case 10:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z-1][x][y] = 0;map[z-1][x-1][y] = 0;break;
	case 11:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z-1][x][y] = 0;map[z+1][x-1][y] = 0;break;
	case 12:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z+1][x][y] = 0;map[z+1][x+1][y] = 0;break;
       }
       break;
    case 4:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z][x][y+1] = 0;map[z][x-1][y] = 0;break;
	case 2:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x][y+1] = 0;map[z][x][y-1] = 0;break;
	case 3:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x][y-1] = 0;map[z][x+1][y] = 0;break;
	case 4:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z][x][y-1] = 0;map[z][x][y+1] = 0;break;
	case 5:
	  map[z][x][y] = 0;map[z][x][y+1] = 0;map[z+1][x][y] = 0;map[z][x][y-1] = 0;break;
	case 6:
	  map[z][x][y] = 0;map[z][x][y-1] = 0;map[z+1][x][y] = 0;map[z-1][x][y] = 0;break;
	case 7:
	  map[z][x][y] = 0;map[z][x][y-1] = 0;map[z-1][x][y] = 0;map[z][x][y+1] = 0;break;
	case 8:
	  map[z][x][y] = 0;map[z][x][y+1] = 0;map[z-1][x][y] = 0;map[z+1][x][y] = 0;break;
	case 9:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z+1][x][y] = 0;map[z][x-1][y] = 0;break;
	case 10:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z-1][x][y] = 0;map[z+1][x][y] = 0;break;
	case 11:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z-1][x][y] = 0;map[z][x+1][y] = 0;break;
	case 12:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z+1][x][y] = 0;map[z-1][x][y] = 0;break;
       }
       break;
    case 5:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z][x+2][y] = 0;map[z][x-1][y] = 0;break;
	case 2:
	  map[z][x][y] = 0;map[z][x][y+1] = 0;map[z][x][y+2] = 0;map[z][x][y-1] = 0;break;
	case 3:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x-2][y] = 0;map[z][x+1][y] = 0;break;
	case 4:
	  map[z][x][y] = 0;map[z][x][y-2] = 0;map[z][x][y-1] = 0;map[z][x][y+1] = 0;break;
	case 5:
	  map[z][x][y] = 0;map[z][x][y+1] = 0;map[z][x][y+2] = 0;map[z][x][y-1] = 0;break;
	case 6:
	  map[z][x][y] = 0;map[z+1][x][y] = 0;map[z+2][x][y] = 0;map[z-1][x][y] = 0;break;
	case 7:
	  map[z][x][y] = 0;map[z][x][y+1] = 0;map[z][x][y-1] = 0;map[z][x][y-2] = 0;break;
	case 8:
	  map[z][x][y] = 0;map[z-1][x][y] = 0;map[z-2][x][y] = 0;map[z+1][x][y] = 0;break;
	case 9:
	  map[z][x][y] = 0;map[z+1][x][y] = 0;map[z+2][x][y] = 0;map[z-1][x][y] = 0;break;
	case 10:
	  map[z][x][y] = 0;map[z][x+1][y] = 0;map[z][x+2][y] = 0;map[z][x-1][y] = 0;break;
	case 11:
	  map[z][x][y] = 0;map[z-1][x][y] = 0;map[z-2][x][y] = 0;map[z+1][x][y] = 0;break;
	case 12:
	  map[z][x][y] = 0;map[z][x-1][y] = 0;map[z][x-2][y] = 0;map[z][x+1][y] = 0;break;
       }
       break;
    }
}

uint8_t Block_or_not()
{
  uint8_t x = Temporary.x;
  uint8_t y = Temporary.y;
  uint8_t z = Temporary.z;
  switch(Temporary.kind)
  {
    case 1:
      switch(Temporary.state)
      {
      case 1:
      if(z<0 || x<0 || y<0 || z>10 || x>3 || y>3
          || map[z][x][y] || map[z][x+1][y] || map[z][x][y+1] || map[z][x+1][y+1])return 1;
      break;
      case 2:
      if(z<0 || x<1 || y<0 || z>10 || x>4 || y>3 || map[z][x][y] || map[z][x-1][y] || map[z][x][y+1] || map[z][x-1][y+1])return 1;
      break;
      case 3:
      if(z<0 || x<1 || y<1 || z>10 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z][x][y-1] || map[z][x-1][y-1])return 1;
      break;
      case 4:
      if(z<0 || x<0 || y<0 || z>10 || x>3 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z][x][y-1] || map[z][x+1][y-1])return 1;
      break;
      case 5:
      if(z<0 || x<0 || y<0 || z>9 || x>4 || y>3 || map[z][x][y] || map[z][x][y+1] || map[z+1][x][y] || map[z+1][x][y+1])return 1;
      break;
      case 6:
      if(z<0 || x<0 || y<1 || z>9 || x>4 || y>4 || map[z][x][y] || map[z][x][y-1] || map[z+1][x][y] || map[z+1][x][y-1])return 1;
      break;
      case 7:
      if(z<1 || x<0 || y<1 || z>10 || x>4 || y>4 || map[z][x][y] || map[z][x][y-1] || map[z-1][x][y] || map[z-1][x][y-1])return 1;
      break;
      case 8:
      if(z<1 || x<0 || y<0 || z>10 || x>4 || y>3 || map[z][x][y] || map[z][x][y+1] || map[z-1][x][y] || map[z-1][x][y+1])return 1;
      break;
      case 9:
      if(z<0 || x<0 || y<0 || z>9 || x>3 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z+1][x][y] || map[z+1][x+1][y])return 1;
      break;
      case 10:
      if(z<1 || x<0 || y<0 || z>10 || x>3 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z-1][x][y] || map[z-1][x+1][y])return 1;
      break;
      case 11:
      if(z<1 || x<1 || y<0 || z>10 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z-1][x][y] || map[z-1][x-1][y])return 1;
      break;
      case 12:
      if(z<0 || x<1 || y<0 || z>9 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z+1][x][y] || map[z+1][x-1][y])return 1;
      break;
      }
      break;
    case 2:
      switch(Temporary.state)
      {
      case 1:
	if(z<0 || x<0 || y<0 || z>10 || x>2 || y>3 || map[z][x][y] || map[z][x+1][y] || map[z][x+2][y] || map[z][x][y+1])return 1;
	break;
      case 2:
	if(z<0 || x<0 || y<0 || z>10 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z][x][y+1] || map[z][x][y+2])return 1;
	break;
      case 3:
	if(z<0 || x<2 || y<1 || z>10 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z][x][y-1] || map[z][x-2][y])return 1;
	break;
      case 4:
	if(z<0 || x<0 || y<2 || z>10 || x>3 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z][x][y-1] || map[z][x][y-2])return 1;
	break;
      case 5:
	if(z<0 || x<0 || y<0 || z>8 || x>4 || y>3 || map[z][x][y] || map[z][x][y+1] || map[z+1][x][y] || map[z+2][x][y])return 1;
	break;
      case 6:
	if(z<0 || x<0 || y<2 || z>9 || x>4 || y>4 || map[z][x][y] || map[z][x][y-1] || map[z+1][x][y] || map[z][x][y-2])return 1;
	break;
      case 7:
	if(z<1 || x<0 || y<2 || z>10 || x>4 || y>4 || map[z][x][y] || map[z][x][y-1] || map[z-1][x][y] || map[z][x][y-2])return 1;
	break;
      case 8:
	if(z<1 || x<0 || y<0 || z>10 || x>4 || y>2 || map[z][x][y] || map[z][x][y+1] || map[z-1][x][y] || map[z][x][y+2])return 1;
	break;
      case 9:
	if(z<0 || x<0 || y<0 || z>8 || x>3 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z+1][x][y] || map[z+2][x][y])return 1;
	break;
      case 10:
	if(z<1 || x<0 || y<0 || z>10 || x>2 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z-1][x][y] || map[z][x+2][y])return 1;
	break;
      case 11:
	if(z<2 || x<1 || y<0 || z>10 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z-1][x][y] || map[z-2][x][y])return 1;
	break;
      case 12:
	if(z<0 || x<2 || y<0 || z>9 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z][x-2][y] || map[z+1][x][y])return 1;
	break;
       }
       break;
    case 3:
      switch(Temporary.state)
      {
      case 1:
	if(z<0 || x<1 || y<0 || z>10 || x>3 || y>3 || map[z][x][y] || map[z][x+1][y] || map[z][x][y+1] || map[z][x-1][y+1])return 1;
	break;
      case 2:
	if(z<0 || x<1 || y<1 || z>10 || x>4 || y>3 || map[z][x][y] || map[z][x-1][y] || map[z][x][y+1] || map[z][x-1][y-1])return 1;
	break;
      case 3:
	if(z<0 || x<1 || y<1 || z>10 || x>3 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z][x][y-1] || map[z][x+1][y-1])return 1;
	break;
      case 4:
	if(z<0 || x<0 || y<1 || z>10 || x>3 || y>3 || map[z][x][y] || map[z][x][y-1] || map[z][x+1][y] || map[z][x+1][y+1])return 1;
	break;
      case 5:
	if(z<1 || x<0 || y<0 || z>9 || x>4 || y>3 || map[z][x][y] || map[z][x][y+1] || map[z+1][x][y] || map[z-1][x][y+1])return 1;
	break;
      case 6:
	if(z<0 || x<0 || y<1 || z>9 || x>4 || y>3 || map[z][x][y] || map[z][x][y-1] || map[z+1][x][y] || map[z+1][x][y+1])return 1;
	break;
      case 7:
	if(z<1 || x<0 || y<1 || z>9 || x>4 || y>4 || map[z][x][y] || map[z][x][y-1] || map[z-1][x][y] || map[z+1][x][y-1])return 1;
	break;
      case 8:
	if(z<1 || x<0 || y<1 || z>10 || x>4 || y>3 || map[z][x][y] || map[z][x][y+1] || map[z-1][x][y] || map[z-1][x][y-1])return 1;
	break;
      case 9:
	if(z<1 || x<0 || y<0 || z>9 || x>3 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z+1][x][y] || map[z-1][x+1][y])return 1;
	break;
      case 10:
	if(z<1 || x<1 || y<0 || z>10 || x>3 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z-1][x][y] || map[z-1][x-1][y])return 1;
	break;
      case 11:
	if(z<1 || x<1 || y<0 || z>9 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z-1][x][y] || map[z+1][x-1][y])return 1;
	break;
      case 12:
	if(z<0 || x<1 || y<0 || z>9 || x>3 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z+1][x][y] || map[z+1][x+1][y])return 1;
	break;
       }
       break;
    case 4:
      switch(Temporary.state)
      {
      case 1:
	if(z<0 || x<1 || y<0 || z>10 || x>3 || y>3 || map[z][x][y] || map[z][x+1][y] || map[z][x][y+1] || map[z][x-1][y])return 1;
	break;
      case 2:
	if(z<0 || x<1 || y<1 || z>10 || x>4 || y>3 || map[z][x][y] || map[z][x-1][y] || map[z][x][y+1] || map[z][x][y-1])return 1;
	break;
      case 3:
	if(z<0 || x<1 || y<1 || z>10 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z][x][y-1] || map[z][x+1][y])return 1;
	break;
      case 4:
	if(z<0 || x<0 || y<1 || z>10 || x>3 || y>3 || map[z][x][y] || map[z][x+1][y] || map[z][x][y-1] || map[z][x][y+1])return 1;
	break;
      case 5:
	if(z<0 || x<0 || y<1 || z>9 || x>4 || y>3 || map[z][x][y] || map[z][x][y+1] || map[z+1][x][y] || map[z][x][y-1])return 1;
	break;
      case 6:
	if(z<1 || x<0 || y<1 || z>9 || x>4 || y>4 || map[z][x][y] || map[z][x][y-1] || map[z+1][x][y] || map[z-1][x][y])return 1;
	break;
      case 7:
	if(z<1 || x<0 || y<1 || z>10 || x>4 || y>3 || map[z][x][y] || map[z][x][y-1] || map[z-1][x][y] || map[z][x][y+1])return 1;
	break;
      case 8:
	if(z<1 || x<0 || y<0 || z>9 || x>4 || y>3 || map[z][x][y] || map[z][x][y+1] || map[z-1][x][y] || map[z+1][x][y])return 1;
	break;
      case 9:
	if(z<0 || x<1 || y<0 || z>9 || x>3 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z+1][x][y] || map[z][x-1][y])return 1;
	break;
      case 10:
	if(z<1 || x<0 || y<0 || z>9 || x>3 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z-1][x][y] || map[z+1][x][y])return 1;
	break;
      case 11:
	if(z<1 || x<1 || y<0 || z>10 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z-1][x][y] || map[z][x+1][y])return 1;
	break;
      case 12:
	if(z<1 || x<1 || y<0 || z>9 || x>4 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z+1][x][y] || map[z-1][x][y])return 1;
	break;
       }
       break;
    case 5:
      switch(Temporary.state)
      {
      case 1:
	if(z<0 || x<1 || y<0 || z>10 || x>2 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z][x+2][y] || map[z][x-1][y])return 1;
	break;
      case 2:
	if(z<0 || x<0 || y<1 || z>10 || x>4 || y>2 || map[z][x][y] || map[z][x][y+1] || map[z][x][y+2] || map[z][x][y-1])return 1;
	break;
      case 3:
	if(z<0 || x<2 || y<0 || z>10 || x>3 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z][x-2][y] || map[z][x+1][y])return 1;
	break;
      case 4:
	if(z<0 || x<0 || y<2 || z>10 || x>4 || y>3 || map[z][x][y] || map[z][x][y-2] || map[z][x][y-1] || map[z][x][y+1])return 1;
	break;
      case 5:
	if(z<0 || x<0 || y<1 || z>10 || x>4 || y>2 || map[z][x][y] || map[z][x][y+1] || map[z][x][y+2] || map[z][x][y-1])return 1;
	break;
      case 6:
	if(z<1 || x<0 || y<0 || z>8 || x>4 || y>4 || map[z][x][y] || map[z+1][x][y] || map[z+2][x][y] || map[z-1][x][y])return 1;
	break;
      case 7:
	if(z<0 || x<0 || y<1 || z>10 || x>4 || y>2 || map[z][x][y] || map[z][x][y+1] || map[z][x][y-1] || map[z][x][y-2])return 1;
	break;
      case 8:
	if(z<2 || x<0 || y<0 || z>9 || x>4 || y>4 || map[z][x][y] || map[z-1][x][y] || map[z-2][x][y] || map[z+1][x][y])return 1;
	break;
      case 9:
	if(z<1 || x<0 || y<0 || z>8 || x>4 || y>4 || map[z][x][y] || map[z+1][x][y] || map[z+2][x][y] || map[z-1][x][y])return 1;
	break;
      case 10:
	if(z<0 || x<1 || y<0 || z>10 || x>2 || y>4 || map[z][x][y] || map[z][x+1][y] || map[z][x+2][y] || map[z][x-1][y])return 1;
	break;
      case 11:
	if(z<2 || x<0 || y<0 || z>9 || x>4 || y>4 || map[z][x][y] || map[z-1][x][y] || map[z-2][x][y] || map[z+1][x][y])return 1;
	break;
      case 12:
	if(z<0 || x<2 || y<0 || z>10 || x>3 || y>4 || map[z][x][y] || map[z][x-1][y] || map[z][x-2][y] || map[z][x+1][y])return 1;
	break;
       }
       break;
    }
  return 0;
}

uint8_t Lock_or_not()
{
  Temporary_Off();
  Temporary.z--;
  if(Block_or_not())
    {
      Temporary.z++;
      Temporary_On();
      return 1;
    }
  else
    {
      Temporary.z++;
      Temporary_On();
      return 0;
    }
}

void Lock_Temporary()
{
  Temporary_Off();
  uint8_t x = Temporary.x;
  uint8_t y = Temporary.y;
  uint8_t z = Temporary.z;
  switch(Temporary.kind)
  {
    case 1:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z][x][y+1] = 1;map[z][x+1][y+1] = 1;break;
	case 2:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x][y+1] = 1;map[z][x-1][y+1] = 1;break;
	case 3:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x][y-1] = 1;map[z][x-1][y-1] = 1;break;
	case 4:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z][x][y-1] = 1;map[z][x+1][y-1] = 1;break;
	case 5:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z+1][x][y] = 1;map[z+1][x][y+1] = 1;break;
	case 6:
	  map[z][x][y] = 1;map[z][x][y-1] = 1;map[z+1][x][y] = 1;map[z+1][x][y-1] = 1;break;
	case 7:
	  map[z][x][y] = 1;map[z][x][y-1] = 1;map[z-1][x][y] = 1;map[z-1][x][y-1] = 1;break;
	case 8:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z-1][x][y] = 1;map[z-1][x][y+1] = 1;break;
	case 9:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z+1][x][y] = 1;map[z+1][x+1][y] = 1;break;
	case 10:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z-1][x][y] = 1;map[z-1][x+1][y] = 1;break;
	case 11:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z-1][x][y] = 1;map[z-1][x-1][y] = 1;break;
	case 12:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z+1][x][y] = 1;map[z+1][x-1][y] = 1;break;
      }
      break;
    case 2:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z][x+2][y] = 1;map[z][x][y+1] = 1;break;
	case 2:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x][y+1] = 1;map[z][x][y+2] = 1;break;
	case 3:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x][y-1] = 1;map[z][x-2][y] = 1;break;
	case 4:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z][x][y-1] = 1;map[z][x][y-2] = 1;break;
	case 5:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z+1][x][y] = 1;map[z+2][x][y] = 1;break;
	case 6:
	  map[z][x][y] = 1;map[z][x][y-1] = 1;map[z+1][x][y] = 1;map[z][x][y-2] = 1;break;
	case 7:
	  map[z][x][y] = 1;map[z][x][y-1] = 1;map[z-1][x][y] = 1;map[z][x][y-2] = 1;break;
	case 8:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z-1][x][y] = 1;map[z][x][y+2] = 1;break;
	case 9:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z+1][x][y] = 1;map[z+2][x][y] = 1;break;
	case 10:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z-1][x][y] = 1;map[z][x+2][y] = 1;break;
	case 11:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z-1][x][y] = 1;map[z-2][x][y] = 1;break;
	case 12:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x-2][y] = 1;map[z+1][x][y] = 1;break;
       }
       break;
    case 3:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z][x][y+1] = 1;map[z][x-1][y+1] = 1;break;
	case 2:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x][y+1] = 1;map[z][x-1][y-1] = 1;break;
	case 3:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x][y-1] = 1;map[z][x+1][y-1] = 1;break;
	case 4:
	  map[z][x][y] = 1;map[z][x][y-1] = 1;map[z][x+1][y] = 1;map[z][x+1][y+1] = 1;break;
	case 5:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z+1][x][y] = 1;map[z-1][x][y+1] = 1;break;
	case 6:
	  map[z][x][y] = 1;map[z][x][y-1] = 1;map[z+1][x][y] = 1;map[z+1][x][y+1] = 1;break;
	case 7:
	  map[z][x][y] = 1;map[z][x][y-1] = 1;map[z-1][x][y] = 1;map[z+1][x][y-1] = 1;break;
	case 8:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z-1][x][y] = 1;map[z-1][x][y-1] = 1;break;
	case 9:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z+1][x][y] = 1;map[z-1][x+1][y] = 1;break;
	case 10:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z-1][x][y] = 1;map[z-1][x-1][y] = 1;break;
	case 11:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z-1][x][y] = 1;map[z+1][x-1][y] = 1;break;
	case 12:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z+1][x][y] = 1;map[z+1][x+1][y] = 1;break;
       }
       break;
    case 4:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z][x][y+1] = 1;map[z][x-1][y] = 1;break;
	case 2:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x][y+1] = 1;map[z][x][y-1] = 1;break;
	case 3:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x][y-1] = 1;map[z][x+1][y] = 1;break;
	case 4:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z][x][y-1] = 1;map[z][x][y+1] = 1;break;
	case 5:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z+1][x][y] = 1;map[z][x][y-1] = 1;break;
	case 6:
	  map[z][x][y] = 1;map[z][x][y-1] = 1;map[z+1][x][y] = 1;map[z-1][x][y] = 1;break;
	case 7:
	  map[z][x][y] = 1;map[z][x][y-1] = 1;map[z-1][x][y] = 1;map[z][x][y+1] = 1;break;
	case 8:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z-1][x][y] = 1;map[z+1][x][y] = 1;break;
	case 9:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z+1][x][y] = 1;map[z][x-1][y] = 1;break;
	case 10:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z-1][x][y] = 1;map[z+1][x][y] = 1;break;
	case 11:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z-1][x][y] = 1;map[z][x+1][y] = 1;break;
	case 12:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z+1][x][y] = 1;map[z-1][x][y] = 1;break;
       }
       break;
    case 5:
      switch(Temporary.state)
      {
	case 1:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z][x+2][y] = 1;map[z][x-1][y] = 1;break;
	case 2:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z][x][y+2] = 1;map[z][x][y-1] = 1;break;
	case 3:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x-2][y] = 1;map[z][x+1][y] = 1;break;
	case 4:
	  map[z][x][y] = 1;map[z][x][y-2] = 1;map[z][x][y-1] = 1;map[z][x][y+1] = 1;break;
	case 5:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z][x][y+2] = 1;map[z][x][y-1] = 1;break;
	case 6:
	  map[z][x][y] = 1;map[z+1][x][y] = 1;map[z+2][x][y] = 1;map[z-1][x][y] = 1;break;
	case 7:
	  map[z][x][y] = 1;map[z][x][y+1] = 1;map[z][x][y-1] = 1;map[z][x][y-2] = 1;break;
	case 8:
	  map[z][x][y] = 1;map[z-1][x][y] = 1;map[z-2][x][y] = 1;map[z+1][x][y] = 1;break;
	case 9:
	  map[z][x][y] = 1;map[z+1][x][y] = 1;map[z+2][x][y] = 1;map[z-1][x][y] = 1;break;
	case 10:
	  map[z][x][y] = 1;map[z][x+1][y] = 1;map[z][x+2][y] = 1;map[z][x-1][y] = 1;break;
	case 11:
	  map[z][x][y] = 1;map[z-1][x][y] = 1;map[z-2][x][y] = 1;map[z+1][x][y] = 1;break;
	case 12:
	  map[z][x][y] = 1;map[z][x-1][y] = 1;map[z][x-2][y] = 1;map[z][x+1][y] = 1;break;
       }
       break;
    }
  Game_State = 1;
}

void Temporary_forward()
{
  Temporary_Off();
  Temporary.y--;
  if(Block_or_not())
    {
      Temporary.y++;
      Temporary_On();
    }
  else
    Temporary_On();
}

void Temporary_backward()
{
  Temporary_Off();
  Temporary.y++;
  if(Block_or_not())
    {
      Temporary.y--;
      Temporary_On();
    }
  else
    Temporary_On();
}

void Temporary_left()
{
  Temporary_Off();
  Temporary.x--;
  if(Block_or_not())
    {
      Temporary.x++;
      Temporary_On();
    }
  else
    Temporary_On();
}

void Temporary_right()
{
  Temporary_Off();
  Temporary.x++;
  if(Block_or_not())
    {
      Temporary.x--;
      Temporary_On();
    }
  else
    Temporary_On();
}

void Temporary_rotate()
{
  Temporary_Off();
  Temporary.state++;
  if(Temporary.state == 13)Temporary.state = 1;
  if(Block_or_not())
    {
      Temporary.state--;
      if(!Temporary.state)Temporary.state = 12;
      Temporary_On();
    }
  else
    Temporary_On();
}

void Temporary_down()
{
  Temporary_Off();
  Temporary.z--;
  if(Block_or_not())
    {
      Temporary.z++;
      Lock_Temporary();
    }
  else
    {
      Temporary_On();
    }
}

void Eliminate()
{
  if(Game_State != 1)
    return;
  uint8_t line_full = 0;
  uint8_t flag = 0;
  for(int i=0;i<11;i++)
  {
    flag = 0;
    for(int j=0;j<5;j++)
    {
      if(flag)break;
      for(int k=0;k<5;k++)
      {
        if(!map[i][j][k])
        {
        flag = 1;
        break;
        }
      }
    }
    if(flag)
      for(int j=0;j<5;j++)
        for(int k=0;k<5;k++)
          map[i-line_full][j][k] = map[i][j][k];
    else
      line_full++;
  }
  for(int i=10;i>10-line_full;i--)
    for(int j=0;j<5;j++)
      for(int k=0;k<5;k++)
        map[i][j][k] = 0;
  Score += 100*line_full*line_full;
  Auto_fall_time -= 500*line_full;
}

void Fail_or_not()
{
  if(Game_State != 1)
    return;
  uint8_t flag = 0;
  for(int i=10;i>=9;i--)
  {
    if(flag)break;
    for(int j=0;j<5;j++)
     {
      if(flag)break;
      for(int k=0;k<5;k++)
        if(map[i][j][k] == 1)
	      {
          flag = 1;
          break;
	      }
     }
  }
  if(flag)Game_State = 2;
  else
  {
    Game_State = 0;
    SET_Temporary();
  }
}
