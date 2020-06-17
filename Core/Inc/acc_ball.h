/*
 * acc_ball.h
 *
 *  Created on: May 6, 2020
 *      Author: rafal
 */

#ifndef INC_ACC_BALL_H_
#define INC_ACC_BALL_H_

#include "ili9341.h"
#include <stdlib.h>

int*** walls;

int width,height;
int point;
int pozycja_start;

int pozycja_x;
int pozycja_y;
int od=100;
int win=0;

void init_walls(int width, int height){
	walls = (int***) malloc(height*sizeof(***walls));
	for (int i=0;i<height;i++){
		walls[i] = (int**) malloc(width*sizeof(**walls));
	}
	for (int i=0;i<height;i++){
		for (int j=0;j<width;j++){
			walls[i][j] = (int*) malloc(4*sizeof(*walls));
		}
	}
}

int left_wall(int pozycja_x, int pozycja_y){
	
	od=100;
	if(0<=pozycja_x && pozycja_x<point)
		return od;
	for (int i=0;i<height;i++){
		for(int j=0;j<width-1;j++){
			if(((j+1)*point)<pozycja_x && pozycja_x<((j+2)*point) && (i*point)<pozycja_y && pozycja_y<((i+1)*point)){
				if(i<height-1){
					if(pozycja_y<pozycja_start+point*i && pozycja_y>point*i && pozycja_y>pozycja_start){
						if(walls[i-1][j][0]=='1' || walls[i-1][j][2]=='1' || walls[i-1][j][3]=='1')
							return od = pozycja_x-((j+1)*point);
						else
							return od;
					}
					if(pozycja_y>=pozycja_start+point*i && pozycja_y<=point-pozycja_start+point*i){
						if(walls[i][j][0]=='1')
							return od = pozycja_x-((j+1)*point);
						else
							return od;
					}
					if(pozycja_y>point-pozycja_start+point*i){
						if(walls[i][j][0]=='1' || walls[i][j][2]=='1' || walls[i][j][3]=='1')
							return od = pozycja_x-((j+1)*point);
						else
							return od;
					}
				}
				else{
					if(pozycja_y>=pozycja_start+point*(i-1) && pozycja_y<=point-pozycja_start+point*i){
						if(walls[i-1][j][2]=='1')
							return od = pozycja_x-((j+1)*point);
						else
							return od;
					}
					if(pozycja_y<pozycja_start-1+point*i && pozycja_y>point*i && pozycja_y>pozycja_start){
						if(walls[i-1][j][0]=='1' || walls[i-1][j][2]=='1' || walls[i-1][j][3]=='1')
							return od = pozycja_x-((j+1)*point);
						else
							return od;
					}

				}
			}
		}
	}
	return od;
}
int right_wall(int pozycja_x, int pozycja_y){

	od=100;
	if (pozycja_x==238-pozycja_start && pozycja_y>=(point*(height-1)) && pozycja_y<=point-pozycja_start+point*height){
		win=1;
		return 0;
	}
	if(236-pozycja_start<=pozycja_x && pozycja_x<240)
		return od;
	for (int i=0;i<height;i++){
		for(int j=0;j<width-1;j++){
			if((j*point)<pozycja_x && pozycja_x<((j+1)*point) && (i*point)<pozycja_y && pozycja_y<((i+1)*point)){
				if(i<height-1){
					if(pozycja_y<pozycja_start+point*i && pozycja_y>point*i && pozycja_y>pozycja_start){
						if(walls[i-1][j][0]=='1' || walls[i-1][j][1]=='1' || walls[i-1][j][2]=='1')
							return od = (pozycja_x-((j+1)*point))*(-1);
						else
							return od;
					}
					if(pozycja_y>=pozycja_start+point*i && pozycja_y<=point-pozycja_start+point*i){
						if(walls[i][j][0]=='1')
							return od = (pozycja_x-((j+1)*point))*(-1);
						else
							return od;
					}
					if(pozycja_y>point-pozycja_start+point*i){
						if(walls[i][j][0]=='1' || walls[i][j][1]=='1' || walls[i][j][2]=='1')
							return od = (pozycja_x-((j+1)*point))*(-1);
						else
							return od;
					}
				}
				else{
					if(pozycja_y>=pozycja_start+point*(i-1) && pozycja_y<=point-pozycja_start+point*i){
						if(walls[i-1][j][2]=='1')
							return od = (pozycja_x-((j+1)*point))*(-1);
						else
							return od;
					}
					if(pozycja_y<pozycja_start-1+point*i && pozycja_y>point*i && pozycja_y>pozycja_start){
						if(walls[i-1][j][0]=='1' || walls[i-1][j][1]=='1' || walls[i-1][j][2]=='1')
							return od = (pozycja_x-((j+1)*point))*(-1);
						else
							return od;
					}

				}
			}
		}
	}
	return od;
}
int bottom_wall(int pozycja_x, int pozycja_y){

	od=100;
	if(278-pozycja_start<=pozycja_y && pozycja_y<280)
		return od;
	for (int i=0;i<height-1;i++){
		for(int j=0;j<width;j++){
			if((j*point)<=pozycja_x && pozycja_x<((j+1)*point) && (i*point)<pozycja_y && pozycja_y<((i+1)*point)){
				if(j<width-1){
					if(pozycja_x<pozycja_start+point*j && pozycja_x>=point*j && pozycja_x>pozycja_start){
						if(walls[i][j-1][0]=='1' || walls[i][j-1][1]=='1' || walls[i][j-1][2]=='1' || walls[i][j-1][3]=='1')
							return od = (pozycja_y-((i+1)*point))*(-1);
						else
							return od;
					}
					if(pozycja_x>=pozycja_start+point*j && pozycja_x<=point-pozycja_start+point*j){
						if(walls[i][j][3]=='1')
							return od = (pozycja_y-((i+1)*point))*(-1);
						else
							return od;
					}
					if(pozycja_x>point-pozycja_start+point*j){
						if(walls[i][j][0]=='1' || walls[i][j][1]=='1' || walls[i][j][2]=='1' || walls[i][j][3]=='1')
							return od = (pozycja_y-((i+1)*point))*(-1);
						else
							return od;
					}
				}
				else{
					if(pozycja_x>=pozycja_start+point*j && pozycja_x<=point-pozycja_start+point*j){
						if(walls[i][j-1][1]=='1')
							return od = (pozycja_y-((i+1)*point))*(-1);
						else
							return od;
					}
					if(pozycja_x<pozycja_start+point*j && pozycja_x>point*j && pozycja_x>pozycja_start){
						if(walls[i][j-1][0]=='1' || walls[i][j-1][1]=='1' || walls[i][j-1][2]=='1' || walls[i][j-1][3]=='1')
							return od = (pozycja_y-((i+1)*point))*(-1);
						else
							return od;
					}
				}
			}
		}
	}
	return od;
}
int top_wall(int pozycja_x, int pozycja_y){

	od=100;
	if(0<=pozycja_y && pozycja_y<point)
		return od;
	for (int i=0;i<height-1;i++){
		for(int j=0;j<width;j++){
			if((j*point)<=pozycja_x && pozycja_x<((j+1)*point) && ((i+1)*point)<pozycja_y && pozycja_y<((i+2)*point)){
				if(j<width-1){
					if(pozycja_x<pozycja_start+point*j && pozycja_x>=point*j && pozycja_x>pozycja_start){
						if(walls[i][j-1][0]=='1' || walls[i][j-1][1]=='1' || walls[i][j-1][2]=='1' || walls[i][j-1][3]=='1')
							return od = pozycja_y-((i+1)*point);
						else
							return od;
						}
					if(pozycja_x>=pozycja_start+point*j && pozycja_x<=point-pozycja_start+point*j){
						if(walls[i][j][3]=='1')
							return od = pozycja_y-((i+1)*point);
						else
							return od;
					}
					if(pozycja_x>point-pozycja_start+point*j){
						if(walls[i][j][0]=='1' || walls[i][j][1]=='1' || walls[i][j][2]=='1' || walls[i][j][3]=='1')
							return od = pozycja_y-((i+1)*point);
						else
							return od;
					}
				}
				else{
					if(pozycja_x>=pozycja_start+point*j && pozycja_x<=point-pozycja_start+point*j){
						if(walls[i][j-1][1]=='1')
							return od = pozycja_y-((i+1)*point);
						else
							return od;
					}
					if(pozycja_x<pozycja_start+point*j && pozycja_x>point*j && pozycja_x>pozycja_start){
						if(walls[i][j-1][0]=='1' || walls[i][j-1][1]=='1' || walls[i][j-1][2]=='1' || walls[i][j-1][3]=='1')
							return od = pozycja_y-((i+1)*point);
						else
							return od;
					}

				}
			}
		}
	}
	return od;
}
void acc_ball(float accX, float accY, char*** walls){

	if(accX>=30 && pozycja_x<=238-pozycja_start && right_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_x+=1;//ruch w prawo
	}
	if(accY>=30 && pozycja_y>pozycja_start && top_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_y-=1; //ruch piłki w górę
	}
	if(accX<=-30 && pozycja_x>pozycja_start && left_wall(pozycja_x,pozycja_y)>pozycja_start)
	{
		pozycja_x-=1; //ruch w lewo
	}
	if(accY<=-30 && pozycja_y<=278-pozycja_start && bottom_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_y+=1; //ruch piłki w dół 
	}

	if(accX>=190 && pozycja_x<=238-pozycja_start && right_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_x+=1; //ruch w prawo
	}
	if(accY>=190 && pozycja_y>pozycja_start && top_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_y-=1; //ruch w górę
	}
	if(accX<=-190 && pozycja_x>pozycja_start && left_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_x-=1; //ruch w lewo
	}
	if(accY<=-190 && pozycja_y<=278-pozycja_start && bottom_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_y+=1; //ruch w dół
	}

	if(accX>=350 && pozycja_x<=238-pozycja_start && right_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_x+=1; //ruch w prawo
	}
	if(accY>=350 && pozycja_y>pozycja_start && top_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_y-=1; //ruch w górę
	}
	if(accX<=-350 && pozycja_x>pozycja_start && left_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_x-=1; //ruch w lewo
	}
	if(accY<=-350 && pozycja_y<=278-pozycja_start && bottom_wall(pozycja_x, pozycja_y)>pozycja_start)
	{
		pozycja_y+=1; //ruch w dół
	}

}

void display_ball(float accX, float accY, char*** walls,int r){

	acc_ball(accX,accY,walls);

	ILI9341_DrawFilledCircle(pozycja_x, pozycja_y, r, 10);

}

void init_ball(int difficulty){
	if(difficulty==1){
		pozycja_x=pozycja_start;
		pozycja_y=pozycja_start;
	}
	if(difficulty==2){
		pozycja_x=pozycja_start;
		pozycja_y=pozycja_start;
	}
}

#endif /* INC_ACC_BALL_H_ */
