/*
 * acc_ball.h
 *
 *  Created on: May 6, 2020
 *      Author: rafal
 */

#ifndef INC_ACC_BALL_H_
#define INC_ACC_BALL_H_

#include "ili9341.h"
#include "lis3dsh.h"

void display_ball(){
	ILI9341_DrawFilledCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

}


#endif /* INC_ACC_BALL_H_ */
