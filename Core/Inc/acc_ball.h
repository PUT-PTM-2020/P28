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
#include "maze.h"

int pozycja_x=0;
int pozycja_y=0;
int start_x=18;
int start_y=18;
//(0,0)->pierwszy piksel
//X(120,0)->ostatnia pozycja w prawo->(110,0)->minus ściana(99,0)
//-X(-119,0)->ostatnia pozycja w lewo->(-109,0)->minus ściana(-102,0)
//Y(0,150)->ostatnia pozycja w góre->(0,140)->minus ściana i dół(0,142)
//-Y(0,-149)->ostatnia pozycja w góre->(0,-139)->minus ściana i dół(0,-100)
bool left_wall(float pozycja_x, float pozycja_y){
	if(pozycja_x >0 && pozycja_y < 40)//pierwszy wiersz
	{
		
	}
	if(40 < pozycja_x < 200  && 40 < pozycja_y < 240)//środek
	{
			
	}
	if(pozycja_x > 0 && 240 < pozycja_y < 280)//ostatni wiersz
	{
			
	}
	if(pozycja_x < 40  && 40 < pozycja_y < 240)//pierwsza kolumna
	{
				
	}
	if(pozycja_x > 200  && 40 < pozycja_y < 240)//ostatnia kolumna
	{
					
	}
	
	return true;
}
void acc_ball(float pozycja_x, float pozycja_y){

	if(accX>=30 && pozycja_x<203)
	{
		pozycja_x+=1;//ruch w prawo
	}
	if(accY>=30 && pozycja_y>0)
	{
		pozycja_y-=1; //ruch w górę
	}
	if(accX<=-30 && pozycja_x>0)
	{
		pozycja_x-=1; //ruch w lewo
	}
	if(accY<=-30 && pozycja_y<243)
	{
		pozycja_y+=1; //ruch w dół
	}

	if(accX>=350 && pozycja_x<203)
	{
		pozycja_x+=2; //ruch w prawo
		if(!(pozycja_x<203))
			pozycja_x=203;

	}
	if(accY>=350 && pozycja_y>0)
	{
		pozycja_y-=2; //ruch w górę
		if(!(pozycja_y>0))
			pozycja_y=0;
	}
	if(accX<=-350 && pozycja_x>0)
	{
		pozycja_x-=2; //ruch w lewo
		if(!(pozycja_x>0))
			pozycja_x=0;
	}
	if(accY<=-350 && pozycja_y<243)
	{
		pozycja_y+=2; //ruch w dół
		if(!(pozycja_y<243))
			pozycja_y=243;
	}

}

void display_ball(float accX, float accY){

	acc_ball(accX,accY);

	ILI9341_DrawFilledCircle(start_x + pozycja_x, start_y + pozycja_y, 10, 10);

}

void reset_ball(){
	pozycja_x=0;
	pozycja_y=0;
}

#endif /* INC_ACC_BALL_H_ */
