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

int pozycja_x=0;
int pozycja_y=0;

void acc_ball(float accX, float accY){

	if(accX>=30)
	{
		pozycja_x+=1;
	}
	if(accY>=30)
	{
		pozycja_y+=1;
	}
	if(accX<=-30)
	{
		pozycja_x-=1;
	}
	if(accY<=-30)
	{
		pozycja_y-=1;
	}

	if(accX>=350)
	{
		pozycja_x+=3;
	}
	if(accY>=350)
	{
		pozycja_y+=3;
	}
	if(accX<=-350)
	{
		pozycja_x-=3;
	}
	if(accY<=-350)
	{
		pozycja_y-=3;
	}

}

void display_ball(float accX, float accY){

	acc_ball(accX,accY);

	ILI9341_DrawFilledCircle(ILI9341_WIDTH / 2 + pozycja_x, ILI9341_HEIGHT / 2 - pozycja_y, 10, 10);

}

#endif /* INC_ACC_BALL_H_ */
