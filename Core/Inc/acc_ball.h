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


ILI9341_DrawLine((j+1)*40-40, (i+1)*40, 40, 0, ILI9341_BLACK);
				ILI9341_DrawLine((j+1)*40-40, (i+1)*40-1, 40, 0, ILI9341_BLACK);
				ILI9341_DrawLine((j+1)*40-40, (i+1)*40+1, 40, 0, ILI9341_BLACK);



//(0,0)->pierwszy piksel
//X(120,0)->ostatnia pozycja w prawo->(110,0)->minus ściana(99,0)
//-X(-119,0)->ostatnia pozycja w lewo->(-109,0)->minus ściana(-102,0)
//Y(0,150)->ostatnia pozycja w góre->(0,140)->minus ściana i dół(0,142)
//-Y(0,-149)->ostatnia pozycja w góre->(0,-139)->minus ściana i dół(0,-100)
bool left_wall(float pozycja_x, float pozycja_y){
	for (int i=0;i<6;i++){
		for(int j=0;j<5;j++){
			if(((j+1)*40)<pozycja_x<((j+2)*40) && (i*40)<pozycja_y<(i*40)){
				if(walls[i][j][0]=='1'){
					return false;
				}
				else{
					return true;
				}
			}
		}
	}
}
bool right_wall(float pozycja_x, float pozycja_y){
	for (int i=0;i<6;i++){
		for(int j=0;j<5;j++){
			if((j*40)<pozycja_x<((j+1)*40) && (i*40)<pozycja_y<((i+1)*40)){
				if(walls[i][j][0]=='1'){
					return false;
				}
				else{
					return true;
				}
			}
		}
	}
}
bool bottom_wall(float pozycja_x, float pozycja_y){
	for (int i=0;i<6;i++){
		for(int j=0;j<5;j++){
			if((j*40)<pozycja_x<((j+1)*40) && (i*40)<pozycja_y<((i+1)*40)){
				if(j<4){
					if(walls[i][j][3]=='1'){
						return false;
					}
					else{
						return true;
					}
				}
				else{
					if(walls[i][j][1]=='1'){
						return false;
					}
						else{
						return true;
					}
				}
			}
		}
	}
}
bool top_wall(float pozycja_x, float pozycja_y){
	for (int i=0;i<6;i++){
		for(int j=0;j<5;j++){
			if((j*40)<pozycja_x<((j+1)*40) && ((i+1)*40)<pozycja_y<((i+2)*40)){
				if(j<4){
					if(walls[i][j][3]=='1'){
						return false;
					}
					else{
						return true;
					}
				}
				else{
					if(walls[i][j][1]=='1'){
						return false;
					}
					else{
						return true;
					}
				}
			}
		}
	}
}
void acc_ball(float accX, float accY){

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
