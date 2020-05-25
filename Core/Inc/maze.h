#include "ili9341.h"


int wall_size = 3;

char walls[11][14][4];

int cell_coordinates = 20;

void init_maze(){
	for (int i=0;i<11;i++){
		for(int j=0;j<14;j++){
			for(int k=0;k<4;k++){
				walls[i][j][k]='1';
			}
		}
	}
}

void display_maze(){
	for(int i=0;i<3;i++){
		ILI9341_DrawLine(0+i, 0, 300, 1, ILI9341_BLACK);
		ILI9341_DrawLine(237+i, 0, 300, 1, ILI9341_BLACK);
		ILI9341_DrawLine(0, 0+i, 240, 0, ILI9341_BLACK);
		ILI9341_DrawLine(0, 297+i, 240, 0, ILI9341_BLACK);
	}

	for (int i=0;i<11;i++){
		for(int j=0;j<14;j++){
			if(walls[i][j][0]=='1'){
				ILI9341_DrawLine((i+1)*20, (j+1)*20-20, 20, 1, ILI9341_BLACK);
				ILI9341_DrawLine((i+1)*20-1, (j+1)*20-20, 20, 1, ILI9341_BLACK);
				ILI9341_DrawLine((i+1)*20+1, (j+1)*20-20, 20, 1, ILI9341_BLACK);
			}
			if(walls[i][j][1]=='1'){
				ILI9341_DrawLine((i+1)*20, (j+1)*20, 20, 1, ILI9341_BLACK);
				ILI9341_DrawLine((i+1)*20, (j+1)*20-1, 20, 1, ILI9341_BLACK);
				ILI9341_DrawLine((i+1)*20, (j+1)*20+1, 20, 1, ILI9341_BLACK);
			}
			if(walls[i][j][2]=='1'){
				ILI9341_DrawLine((i+1)*20, (j+1)*20, 20, 1, ILI9341_BLACK);
				ILI9341_DrawLine((i+1)*20-1, (j+1)*20, 20, 1, ILI9341_BLACK);
				ILI9341_DrawLine((i+1)*20+1, (j+1)*20, 20, 1, ILI9341_BLACK);
			}
			if(walls[i][j][3]=='1'){
				ILI9341_DrawLine((i+1)*20-20, (j+1)*20, 20, 1, ILI9341_BLACK);
				ILI9341_DrawLine((i+1)*20-20, (j+1)*20-1, 20, 1, ILI9341_BLACK);
				ILI9341_DrawLine((i+1)*20-20, (j+1)*20+1, 20, 1, ILI9341_BLACK);
			}
		}
	}
}
