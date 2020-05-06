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

void display_ball(float accX, float accY){

	int x = ILI9341_WIDTH * accX / 32768;
	int y = ILI9341_HEIGHT * accY / 32768;

	ILI9341_DrawFilledCircle(ILI9341_WIDTH / 2 + x, ILI9341_HEIGHT / 2 - y, 10, ILI9341_BLACK);
}
void acc_ball(float accX, float accY, int start_x, int start_y){

	int x = accX / 32768;
	int y = accY / 32768;
	if(x>=0.1 || y>=0.1)
	{
		ILI9341_DrawFilledCircle(start_x + 10, ILI9341_HEIGHT / 2 - y, 10, 90);
	}

}

#endif /* INC_ACC_BALL_H_ */
