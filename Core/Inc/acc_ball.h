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


int pozycja_x;
int pozycja_y;

//(0,0)->pierwszy piksel
//X(120,0)->ostatnia pozycja w prawo->(110,0)->minus ściana(99,0)
//-X(-119,0)->ostatnia pozycja w lewo->(-109,0)->minus ściana(-102,0)
//Y(0,150)->ostatnia pozycja w góre->(0,140)->minus ściana i dół(0,142)
//-Y(0,-149)->ostatnia pozycja w góre->(0,-139)->minus ściana i dół(0,-100)
bool left_wall(int pozycja_x, int pozycja_y,char*** walls){
	int od=100;
	for (int i=0;i<7;i++){
		for(int j=0;j<5;j++){
			if(((j+1)*40)<pozycja_x && pozycja_x<((j+2)*40) && (i*40)<pozycja_y && pozycja_y<((i+1)*40)){
				if(walls[i][j][0]=='1'){
					//od = pozycja_x-((j+2)*40);
					od=1;
					return false;//od;
				}
				else{
					return true;//od;
				}
			}
		}
	}
}
bool right_wall(int pozycja_x, int pozycja_y,char*** walls){
	int od=100;
	for (int i=0;i<7;i++){
		for(int j=0;j<5;j++){
			if((j*40)<pozycja_x && pozycja_x<((j+1)*40) && (i*40)<pozycja_y && pozycja_y<((i+1)*40)){
				if(walls[i][j][0]=='1'){
					//od = pozycja_x-((j+1)*40);
					od=1;
					return false;//od;
				}
				else{
					return true;//od;
				}
			}
		}
	}
}
bool bottom_wall(int pozycja_x, int pozycja_y,char*** walls){
	int od=100;
	for (int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if((j*40)<pozycja_x && pozycja_x<((j+1)*40) && (i*40)<pozycja_y && pozycja_y<((i+1)*40)){
				if(j<5){
					if(walls[i][j][3]=='1'){
						//od = pozycja_y-((i+1)*40);
						od=1;
						return false;//od;
					}
					else{
						return true;//od;
					}
				}
				else{
					if(walls[i][j][1]=='1'){
						//od = pozycja_y-((i+1)*40);
						od=1;
						return false;//od;
					}
					else{
						return true;//od;
					}
				}
			}
		}
	}
}
bool top_wall(int pozycja_x, int pozycja_y,char*** walls){
	int od=100;
	for (int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if((j*40)<pozycja_x && pozycja_x<((j+1)*40) && ((i+1)*40)<pozycja_y && pozycja_y<((i+2)*40)){
				if(j<5){
					if(walls[i][j][3]=='1'){
						//od = pozycja_y-((i+1)*40);
						od=1;
						return false;//od;
					}
					else{
						return true;//od;
					}
				}
				else{
					if(walls[i][j][1]=='1'){
						//od = pozycja_y-((i+1)*40);
						od=1;
						return false;//od;
					}
					else{
						return true;//od;
					}
				}
			}	
		}
	}
}
void acc_ball(float accX, float accY, char*** walls){

	if(accX>=30 && pozycja_x<203 && right_wall(pozycja_x, pozycja_y, walls))//>17)
	{
		pozycja_x+=1;//ruch w prawo
	}
	if(accY>=30 && pozycja_y>0 && top_wall(pozycja_x, pozycja_y, walls))//>17)
	{
		pozycja_y-=1; //ruch piłki w górę
	}
	if(accX<=-30 && pozycja_x>0 && left_wall(pozycja_x,pozycja_y, walls))//>17)
	{
		pozycja_x-=1; //ruch w lewo
	}
	if(accY<=-30 && pozycja_y<243 && bottom_wall(pozycja_x, pozycja_y, walls))//>17)
	{
		pozycja_y+=1; //ruch piłki w dół (może uderzycz w górną ściane)
	}

	if(accX>=350 && pozycja_x<203 && right_wall(pozycja_x, pozycja_y, walls))//>16)
	{
		pozycja_x+=2; //ruch w prawo
		if(!(pozycja_x<203))
			pozycja_x=203;

	}
	if(accY>=350 && pozycja_y>0 && top_wall(pozycja_x, pozycja_y, walls))//>16)
	{
		pozycja_y-=2; //ruch w górę
		if(!(pozycja_y>0))
			pozycja_y=0;
	}
	if(accX<=-350 && pozycja_x>0 && left_wall(pozycja_x, pozycja_y, walls))//>16)
	{
		pozycja_x-=2; //ruch w lewo
		if(!(pozycja_x>0))
			pozycja_x=0;
	}
	if(accY<=-350 && pozycja_y<243 && bottom_wall(pozycja_x, pozycja_y, walls))//>16)
	{
		pozycja_y+=2; //ruch w dół
		if(!(pozycja_y<243))
			pozycja_y=243;
	}

}

void display_ball(float accX, float accY, char*** walls,int r){

	acc_ball(accX,accY,walls);

	ILI9341_DrawFilledCircle(pozycja_x, pozycja_y, r, 10);

}

void reset_ball(){
	pozycja_x=0;
	pozycja_y=0;
}

void init_ball(int difficulty){
	if(difficulty==1){
		pozycja_x=15;
		pozycja_y=15;
	}
	if(difficulty==2){
		pozycja_x=10;
		pozycja_y=10;
	}
}

#endif /* INC_ACC_BALL_H_ */
