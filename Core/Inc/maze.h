#include "ili9341.h"
#include "ff.h"
#include <stdio.h>

char buffer[256]; //bufor odczytu i zapisu
static FATFS FatFs; //uchwyt do urządzenia FatFs (dysku, karty SD...)
FRESULT fresult; //do przechowywania wyniku operacji na bibliotece FatFs
FIL file; //uchwyt do otwartego pliku
WORD bytes_written; //liczba zapisanych byte
WORD bytes_read; //liczba odczytanych byte
char filename[10]; //nazwa pliku wybranego labiryntu
int n;

char walls[6][5][4];
char walls_h[13][11][4];

void change_filename(int difficulty, int maze_number){
	if(difficulty==2){
		n=sprintf(filename,"hard%d.txt",maze_number);
	}
	else if(difficulty==1){
		n=sprintf(filename,"easy%d.txt",maze_number);
	}
}

void open_maze_file(int byte_num, char* filename){
	fresult = f_mount(&FatFs, "", 0);
	fresult = f_open(&file, filename, FA_READ);
	fresult = f_read(&file, buffer, byte_num, &bytes_read);
	fresult = f_close(&file);
}

void init_maze(int difficulty, int maze_number){
	change_filename(difficulty, maze_number);
	int buff_index=0;
	if(difficulty==1){
		open_maze_file(120, filename);
		for (int i=0;i<6;i++){
			for(int j=0;j<5;j++){
				for(int k=0;k<4;k++){
					walls[i][j][k]=buffer[buff_index];
					buff_index++;
				}
			}
		}
	}
	else if (difficulty==2){
		open_maze_file(572, filename);
		for (int i=0;i<13;i++){
			for(int j=0;j<11;j++){
				for(int k=0;k<4;k++){
					walls_h[i][j][k]=buffer[buff_index];
					buff_index++;
				}
			}
		}
	}
}

void display_maze(int difficulty){
	for(int i=0;i<3;i++){
		ILI9341_DrawLine(0+i, 0, 280, 1, ILI9341_BLACK);
		ILI9341_DrawLine(237+i, 0, 280, 1, ILI9341_BLACK);
		ILI9341_DrawLine(0, 0+i, 240, 0, ILI9341_BLACK);
		ILI9341_DrawLine(0, 277+i, 240, 0, ILI9341_BLACK);
	}
	if(difficulty==1){
		for (int i=0;i<6;i++){
			for(int j=0;j<5;j++){
				if(walls[i][j][0]=='1'){
					ILI9341_DrawLine((j+1)*40, (i+1)*40-40, 40, 1, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*40-1, (i+1)*40-40, 40, 1, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*40+1, (i+1)*40-40, 40, 1, ILI9341_BLACK);
				}
				if(walls[i][j][1]=='1'){
					ILI9341_DrawLine((j+1)*40, (i+1)*40, 40, 0, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*40, (i+1)*40-1, 40, 0, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*40, (i+1)*40+1, 40, 0, ILI9341_BLACK);
				}
				if(walls[i][j][2]=='1'){
					ILI9341_DrawLine((j+1)*40, (i+1)*40, 40, 1, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*40-1, (i+1)*40, 40, 1, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*40+1, (i+1)*40, 40, 1, ILI9341_BLACK);
				}
				if(walls[i][j][3]=='1'){
					ILI9341_DrawLine((j+1)*40-40, (i+1)*40, 40, 0, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*40-40, (i+1)*40-1, 40, 0, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*40-40, (i+1)*40+1, 40, 0, ILI9341_BLACK);
				}
			}
		}
	}
	else if(difficulty==2){
		for (int i=0;i<13;i++){
			for(int j=0;j<11;j++){
				if(walls_h[i][j][0]=='1'){
					ILI9341_DrawLine((j+1)*20, (i+1)*20-20, 20, 1, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*20-1, (i+1)*20-20, 20, 1, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*20+1, (i+1)*20-20, 20, 1, ILI9341_BLACK);
				}
				if(walls_h[i][j][1]=='1'){
					ILI9341_DrawLine((j+1)*20, (i+1)*20, 20, 0, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*20, (i+1)*20-1, 20, 0, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*20, (i+1)*20+1, 20, 0, ILI9341_BLACK);
				}
				if(walls_h[i][j][2]=='1'){
					ILI9341_DrawLine((j+1)*20, (i+1)*20, 20, 1, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*20-1, (i+1)*20, 20, 1, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*20+1, (i+1)*20, 20, 1, ILI9341_BLACK);
				}
				if(walls_h[i][j][3]=='1'){
					ILI9341_DrawLine((j+1)*20-20, (i+1)*20, 20, 0, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*20-20, (i+1)*20-1, 20, 0, ILI9341_BLACK);
					ILI9341_DrawLine((j+1)*20-20, (i+1)*20+1, 20, 0, ILI9341_BLACK);
				}
			}
		}
	}
}
