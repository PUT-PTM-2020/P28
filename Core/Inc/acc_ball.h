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
	LIS3DSH_ReadACC(out);
	accX = out[0];
	accY = out[1];

	int x = ILI9341_WIDTH * accX / 32768;
	int y = ILI9341_HEIGHT * accY / 32768;

	ILI9341_DrawFilledCircle(ILI9341_WIDTH / 2 + x, ILI9341_HEIGHT / 2 - y, 10, 90);
}
void acc_ball(int start_x, int start_y){
	LIS3DSH_ReadACC(out);
	accX = out[0];
	accY = out[1];


}

#endif /* INC_ACC_BALL_H_ */
