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
#include <stdlib.h>

int*** walls;
//char walls[6][5][4] = {"0110","1001","0010","1000","0010","1000","0110","1101","0111","1001","0100","1101","0001","1010","0100","0101","0101","0101","1101","0001","0100","0101","0101","0111","0011","0100","0101","0011","1010","1000"};

void init_walls(int difficulty){
	if(difficulty==1){
		walls = (int***) malloc(6*sizeof(***walls));
		for (int i=0;i<6;i++){
			walls[i] = (int**) malloc(5*sizeof(**walls));
		}
		for (int i=0;i<6;i++){
			for (int j=0;j<5;j++){
				walls[i][j] = (int*) malloc(4*sizeof(*walls));
			}
		}
	}
	else if (difficulty==2){
		walls = (int***) malloc(13*sizeof(***walls));
		for (int i=0;i<13;i++){
			walls[i] = (int**) malloc(11*sizeof(**walls));
		}
		for (int i=0;i<13;i++){
			for (int j=0;j<11;j++){
				walls[i][j] = (int*) malloc(4*sizeof(*walls));
			}
		}
	}
}

int pozycja_x;
int pozycja_y;

//(0,0)->pierwszy piksel
//X(120,0)->ostatnia pozycja w prawo->(110,0)->minus ściana(99,0)
//-X(-119,0)->ostatnia pozycja w lewo->(-109,0)->minus ściana(-102,0)
//Y(0,150)->ostatnia pozycja w góre->(0,140)->minus ściana i dół(0,142)
//-Y(0,-149)->ostatnia pozycja w góre->(0,-139)->minus ściana i dół(0,-100)
int left_wall(int pozycja_x, int pozycja_y){//,char*** walls){
	//char walls[6][5][4] = {"0110","1001","0010","1000","0010","1000","0110","1101","0111","1001","0100","1101","0001","1010","0100","0101","0101","0101","1101","0001","0100","0101","0101","0111","0011","0100","0101","0011","1010","1000"};

	int od=100;
	for (int i=0;i<7;i++){
		for(int j=0;j<5;j++){
			if(((j+1)*40)<=pozycja_x && pozycja_x<=((j+2)*40) && (i*40)<=pozycja_y && pozycja_y<=((i+1)*40)){
				if(walls[i][j][0]=='1'){
					od = pozycja_x-((j+2)*40);
					return od;
				}
				else{
					return od;
				}
			}
		}
	}
}
int right_wall(int pozycja_x, int pozycja_y){//,char*** walls){

	int od=100;
	for (int i=0;i<7;i++){
		for(int j=0;j<5;j++){
			if((j*40)<=pozycja_x && pozycja_x<=((j+1)*40) && (i*40)<=pozycja_y && pozycja_y<=((i+1)*40)){
				if(pozycja_y<58+40*i){
					if(walls[i-1][j][0]=='1' || walls[i-1][j][1]=='1' || walls[i-1][j][2]=='1')
						return 1;
					else
						return od;
				}
				if(pozycja_y<18)
					return 1;
				if(pozycja_y>=18+40*i && pozycja_y<=24+40*i){
					if(walls[i][j][0]=='1'){
						od = (pozycja_x-((j+1)*40))*(-1);
						return od;
					}
					else{
						return od;
					}
				}
				if(pozycja_y>64+40*(i-1)){
					if(pozycja_y<264){
						if(walls[i+1][j][0]=='1' || walls[i+1][j][1]=='1' || walls[i+1][j][2]=='1')
							return 1;
						else
							return od;
					}
					else
						return od;
				}
			}
		}
	}
}
int bottom_wall(int pozycja_x, int pozycja_y){//,char*** walls){
	//char walls[6][5][4] = {"0110","1001","0010","1000","0010","1000","0110","1101","0111","1001","0100","1101","0001","1010","0100","0101","0101","0101","1101","0001","0100","0101","0101","0111","0011","0100","0101","0011","1010","1000"};

	int od=100;
	for (int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if((j*40)<=pozycja_x && pozycja_x<=((j+1)*40) && (i*40)<=pozycja_y && pozycja_y<=((i+1)*40)){
				if(j<5){
					if(walls[i][j][3]=='1'){
						od = (pozycja_y-((i+1)*40))*(-1);
						return od;
					}
					else{
						return od;
					}
				}
				else{
					if(walls[i][j][1]=='1'){
						od = pozycja_y-((i+1)*40);
						return od;
					}
					else{
						return od;
					}
				}
			}
		}
	}
}
int top_wall(int pozycja_x, int pozycja_y){//,char*** walls){
	//char walls[6][5][4] = {"0110","1001","0010","1000","0010","1000","0110","1101","0111","1001","0100","1101","0001","1010","0100","0101","0101","0101","1101","0001","0100","0101","0101","0111","0011","0100","0101","0011","1010","1000"};

	int od=100;
	for (int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if((j*40)<=pozycja_x && pozycja_x<=((j+1)*40) && ((i+1)*40)<=pozycja_y && pozycja_y<=((i+2)*40)){
				if(j<5){
					if(walls[i][j][3]=='1'){
						od = pozycja_y-((i+1)*40);
						return od;
					}
					else{
						return od;
					}
				}
				else{
					if(walls[i][j][1]=='1'){
						od = pozycja_y-((i+1)*40);
						return od;
					}
					else{
						return od;
					}
				}
			}	
		}
	}
}
void acc_ball(float accX, float accY, char*** walls){

	if(accX>=30 && pozycja_x<203 && right_wall(pozycja_x, pozycja_y)>17)
	{
		pozycja_x+=1;//ruch w prawo
	}
	if(accY>=30 && pozycja_y>0 && top_wall(pozycja_x, pozycja_y)>17)
	{
		pozycja_y-=1; //ruch piłki w górę
	}
	if(accX<=-30 && pozycja_x>0 && left_wall(pozycja_x,pozycja_y)>17)
	{
		pozycja_x-=1; //ruch w lewo
	}
	if(accY<=-30 && pozycja_y<243 && bottom_wall(pozycja_x, pozycja_y)>17)
	{
		pozycja_y+=1; //ruch piłki w dół 
	}

	if(accX>=350 && pozycja_x<203 && right_wall(pozycja_x, pozycja_y)>16)
	{
		pozycja_x+=2; //ruch w prawo
		if(!(pozycja_x<203))
			pozycja_x=203;

	}
	if(accY>=350 && pozycja_y>0 && top_wall(pozycja_x, pozycja_y)>16)
	{
		pozycja_y-=2; //ruch w górę
		if(!(pozycja_y>0))
			pozycja_y=0;
	}
	if(accX<=-350 && pozycja_x>0 && left_wall(pozycja_x, pozycja_y)>16)
	{
		pozycja_x-=2; //ruch w lewo
		if(!(pozycja_x>0))
			pozycja_x=0;
	}
	if(accY<=-350 && pozycja_y<243 && bottom_wall(pozycja_x, pozycja_y)>16)
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
		pozycja_x=17;
		pozycja_y=17;
	}
	if(difficulty==2){
		pozycja_x=11;
		pozycja_y=11;
	}
}

#endif /* INC_ACC_BALL_H_ */
