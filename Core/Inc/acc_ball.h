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
int start_x=18;
int start_y=18;
//(0,0)->pierwszy piksel
//X(120,0)->ostatnia pozycja w prawo->(110,0)->minus ściana(99,0)
//-X(-119,0)->ostatnia pozycja w lewo->(-109,0)->minus ściana(-102,0)
//Y(0,150)->ostatnia pozycja w góre->(0,140)->minus ściana i dół(0,142)
//-Y(0,-149)->ostatnia pozycja w góre->(0,-139)->minus ściana i dół(0,-100)

void acc_ball(float accX, float accY){

	if(accX>=30 && pozycja_x<219)
	{
		pozycja_x+=1;
	}
	if(accY>=30 && pozycja_y<260)
	{
		pozycja_y+=1;
	}
	if(accX<=-30 && pozycja_x>18)
	{
		pozycja_x-=1;
	}
	if(accY<=-30 && pozycja_y>18)
	{
		pozycja_y-=1;
	}

	if(accX>=350 && pozycja_x<219)
	{
		pozycja_x+=3;
	}
	if(accY>=350 && pozycja_y<260)
	{
		pozycja_y+=3;
	}
	if(accX<=-350 && pozycja_x>18)
	{
		pozycja_x-=3;
	}
	if(accY<=-350 && pozycja_y>18)
	{
		pozycja_y-=3;
	}

}

void display_ball(float accX, float accY){

	acc_ball(accX,accY);

	ILI9341_DrawFilledCircle(start_x + pozycja_x, start_Y - pozycja_y, 10, 10);

}

#endif /* INC_ACC_BALL_H_ */
