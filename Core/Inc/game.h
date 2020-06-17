#include "ili9341.h"
#include "acc_ball.h"
#include "maze.h"
#include <stdlib.h>

uint16_t butt1=0,butt2=0,butt3=0,butt4=0;
uint16_t background = 0x2137;
uint16_t textcolor = ILI9341_BLACK;
uint16_t selectcolor = ILI9341_WHITE;
uint16_t place_in_menu=1;
uint16_t place_in_game=1;
uint16_t choice=1;
uint16_t difficulty=1;
uint16_t maze_number=1;
int r;
uint16_t lost=0;

float accX, accY, accZ, out[4];
int minuty=0,sekundy=0,czas=0,highscore=138;
char min[3],sek[2];
char cstr[10],rekord_m[1],rekord_s[2],rekord[3];

extern TIM_HandleTypeDef htim3;

void buttons(uint16_t GPIO_Pin){
	switch (GPIO_Pin){
		case 2: //przycisk 1 --UP
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_12);

			switch(place_in_game){
			case 1:
				switch(place_in_menu){
				case 2:
					choice=1;
					break;
				case 3:
					if(maze_number>1){
						maze_number--;
						init_maze(difficulty,maze_number,width,height);
						itoa(maze_number,cstr,10);
						if(difficulty==1){
							rekord[0]=buffer[120];
							rekord[1]=buffer[121];
							rekord[2]=buffer[122];
							highscore=atoi(rekord);
							minuty=highscore/60;
							sekundy=highscore%60;
							itoa(sekundy, rekord_s, 10);
							itoa(minuty, rekord_m, 10);
						}
						else if(difficulty==2){
							rekord[0]=buffer[572];
							rekord[1]=buffer[573];
							rekord[2]=buffer[574];
							highscore=atoi(rekord);
							minuty=highscore/60;
							sekundy=highscore%60;
							itoa(sekundy, rekord_s, 10);
							itoa(minuty, rekord_m, 10);
						}
					}
					break;
				}
				break;
			}
			case 3:
				choice=1;
				break;
			break;

		case 4: //przycisk 2 --DOWN
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);

			switch(place_in_game){
			case 1:
				switch(place_in_menu){
				case 2:
					choice=2;
					break;
				case 3:
					if(maze_number<9){
						maze_number++;
						init_maze(difficulty,maze_number,width,height);
						itoa(maze_number,cstr,10);
						if(difficulty==1){
							rekord[0]=buffer[120];
							rekord[1]=buffer[121];
							rekord[2]=buffer[122];
							highscore=atoi(rekord);
							minuty=highscore/60;
							sekundy=highscore%60;
							itoa(sekundy, rekord_s, 10);
							itoa(minuty, rekord_m, 10);
						}
						else if(difficulty==2){
							rekord[0]=buffer[572];
							rekord[1]=buffer[573];
							rekord[2]=buffer[574];
							highscore=atoi(rekord);
							minuty=highscore/60;
							sekundy=highscore%60;
							itoa(sekundy, rekord_s, 10);
							itoa(minuty, rekord_m, 10);
						}
					}
					break;
				}
				break;
			case 3:
				choice=2;
				break;
			}

			break;

		case 8: //przycisk 3 --ENTER
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_14);

			switch(place_in_game){
			case 1:
				switch(place_in_menu){
				case 1:
					place_in_menu=2;
					ILI9341_FillRectangle(43, 125, 154, 90, background);
					break;
				case 2:
					place_in_menu=3;
					if(choice==1){
						difficulty=1;
						r=9;
						pozycja_start=17;
						width=6;
						height=7;
						point=40;
					}
					else if(choice==2){
						difficulty=2;
						r=4;
						pozycja_start=9;
						width=12;
						height=14;
						point=20;
					}
					init_maze(difficulty,maze_number,width,height);
					itoa(maze_number,cstr,10);
					if(difficulty==1){
						rekord[0]=buffer[120];
						rekord[1]=buffer[121];
						rekord[2]=buffer[122];
						highscore=atoi(rekord);
						minuty=highscore/60;
						sekundy=highscore%60;
						itoa(sekundy, rekord_s, 10);
						itoa(minuty, rekord_m, 10);
					}
					else if(difficulty==2){
						rekord[0]=buffer[572];
						rekord[1]=buffer[573];
						rekord[2]=buffer[574];
						highscore=atoi(rekord);
						minuty=highscore/60;
						sekundy=highscore%60;
						itoa(sekundy, rekord_s, 10);
						itoa(minuty, rekord_m, 10);
					}
					ILI9341_FillRectangle(43, 125, 154, 90, background);
					break;
				case 3:
					place_in_game=2;
					init_ball(difficulty);
					minuty=0;
					sekundy=0;
					czas=0;
					ILI9341_FillScreen(background);
					display_maze(difficulty);
					ILI9341_FillRectangle(237, (height-1)*point, 3, point, ILI9341_GREEN);
					HAL_TIM_Base_Start_IT(&htim3);
					return;
					break;
				}
				break;
			case 3:
				if(choice==1){
					place_in_game=2;
					ILI9341_FillRectangle(0, 125, 240, 90, background);
					display_maze(difficulty);
					ILI9341_FillRectangle(237, (height-1)*point, 3, point, ILI9341_GREEN);
					HAL_TIM_Base_Start_IT(&htim3);
				}
				else if(choice==2){
					place_in_game=1;
					place_in_menu=1;
					choice=1;
					ILI9341_FillScreen(background);
				}
				break;
			case 4:
				place_in_game=1;
				place_in_menu=1;
				choice=1;
				win=0;
				ILI9341_FillScreen(background);
				break;
			case 5:
				place_in_game=1;
				place_in_menu=1;
				choice=1;
				lost=0;
				ILI9341_FillScreen(background);
				break;
			}
			break;

		case 16: //przycisk 4 --ESCAPE
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_15);

			switch(place_in_game){
			case 1:
				if(place_in_menu>1){
					place_in_menu--;
					ILI9341_FillRectangle(43, 125, 155, 83, background);
				}
				break;
			case 2:
				//zapauzowanie gry
				HAL_TIM_Base_Stop_IT(&htim3);
				place_in_game=3;
				ILI9341_FillRectangle(0, 125, 240, 90, background);
				choice=1;
				return;
				break;
			}
			break;
		}
}

void display_menu(){
	ILI9341_WriteString(56, 1, "POLIMAZE", Font_16x26, textcolor, background);
	ILI9341_WriteString(21, 30, "Kulka w labiryncie", Font_11x18, textcolor, background);

	switch(place_in_menu){ //miejsce w menu
	case 1: //poczatek
		ILI9341_WriteString(76, 151, "Nowa gra", Font_11x18, selectcolor, background);
		break;
	case 2: //wybor poziomu trudnosci
		ILI9341_WriteString(43, 125, "Wybierz poziom", Font_11x18, textcolor, background);
		ILI9341_WriteString(70, 145, "trudnosci", Font_11x18, textcolor, background);
		switch(choice)
		{
		case 1:
			ILI9341_WriteString(92, 170, "Latwy", Font_11x18, selectcolor, background);
			ILI9341_WriteString(87, 190, "Trudny", Font_11x18, textcolor, background);
			break;
		case 2:
			ILI9341_WriteString(92, 170, "Latwy", Font_11x18, textcolor, background);
			ILI9341_WriteString(87, 190, "Trudny", Font_11x18, selectcolor, background);
			break;
		}
		break;
	case 3:
		ILI9341_WriteString(54, 125, "Wybierz mape", Font_11x18, textcolor, background);
		ILI9341_WriteString(114, 155, cstr, Font_11x18, selectcolor, background);
		ILI9341_WriteString(59, 185, "Rekord:", Font_11x18, textcolor, background);
		ILI9341_WriteString(147, 185, ":", Font_11x18, textcolor, background);
		ILI9341_WriteString(136, 185, rekord_m, Font_11x18, textcolor, background);
		ILI9341_WriteString(158, 185, rekord_s, Font_11x18, textcolor, background);
		break;
	}
}

void display_game(){
	display_ball(accX, accY, walls,r);
	minuty=czas/60;
	sekundy=czas%60;
	if(minuty==10){
		lost=1;
	}
	if(sekundy==0)
		ILI9341_FillRectangle(94, 290, 11, 30, background);
	itoa(sekundy, sek, 10);
	itoa(minuty, min, 10);
	ILI9341_WriteString(60, 290, min, Font_11x18, textcolor, background);
	ILI9341_WriteString(72, 290, ":", Font_11x18, textcolor, background);
	ILI9341_WriteString(83, 290, sek, Font_11x18, textcolor, background);
	ILI9341_WriteString(1, 290, "Czas:", Font_11x18, textcolor, background);
	ILI9341_WriteString(117, 290, "Rekord:", Font_11x18, textcolor, background);
	ILI9341_WriteString(206, 290, ":", Font_11x18, textcolor, background);
	ILI9341_WriteString(195, 290, rekord_m, Font_11x18, textcolor, background);
	ILI9341_WriteString(217, 290, rekord_s, Font_11x18, textcolor, background);
}

void display_pause(){
	ILI9341_WriteString(92, 126, "Pauza", Font_11x18, textcolor, background);
	switch(choice)
	{
	case 1:
		ILI9341_WriteString(70, 170, "Kontynuuj", Font_11x18, selectcolor, background);
		ILI9341_WriteString(48, 190, "Wyjdz do menu", Font_11x18, textcolor, background);
		break;
	case 2:
		ILI9341_WriteString(70, 170, "Kontynuuj", Font_11x18, textcolor, background);
		ILI9341_WriteString(48, 190, "Wyjdz do menu", Font_11x18, selectcolor, background);
		break;
	}
}

void display_win(){
	ILI9341_WriteString(76, 126, "Wygrales", Font_11x18, textcolor, background);
	ILI9341_WriteString(48, 160, "Wyjdz do menu", Font_11x18, selectcolor, background);
}

void display_lost(){
	ILI9341_WriteString(48, 126, "Przekroczyles", Font_11x18, textcolor, background);
	ILI9341_WriteString(4, 146, "10 minut. Przegrales!", Font_11x18, textcolor, background);
	ILI9341_WriteString(48, 166, "Wyjdz do menu", Font_11x18, selectcolor, background);
}

void game(){
	switch(place_in_game){
		case 1:
			display_menu();
			break;
		case 2:
			display_game();
			if(win==1){
				HAL_TIM_Base_Stop_IT(&htim3);
				place_in_game=4;
				if(czas>highscore)
					save_highscore(difficulty,maze_number,czas);
				ILI9341_FillRectangle(0, 125, 240, 60, background);
				choice=1;
			}
			if(lost==1){
				HAL_TIM_Base_Stop_IT(&htim3);
				place_in_game=5;
				ILI9341_FillRectangle(0, 125, 240, 70, background);
				choice=1;
			}
			break;
		case 3:
			display_pause();
			break;
		case 4:
			display_win();
			break;
		case 5:
			display_lost();
			break;
	}
}
