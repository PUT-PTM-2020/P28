#include "ili9341.h"


char walls[6][5][4] = {"0110","1001","0010","1000","0010","1000","0110","1101","0111","1001","0100","1101","0001","1010","0100","0101","0101","0101","1101","0001","0100","0101","0101","0111","0011","0100","0101","0011","1010","1000"};

void init_maze(){
	for (int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<4;k++){
				walls[i][j][k]='1';
			}
		}
	}
}

void display_maze(){
	for(int i=0;i<3;i++){
		ILI9341_DrawLine(0+i, 0, 280, 1, ILI9341_BLACK);
		ILI9341_DrawLine(237+i, 0, 280, 1, ILI9341_BLACK);
		ILI9341_DrawLine(0, 0+i, 240, 0, ILI9341_BLACK);
		ILI9341_DrawLine(0, 277+i, 240, 0, ILI9341_BLACK);
	}

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
