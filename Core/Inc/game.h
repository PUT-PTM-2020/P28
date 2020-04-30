#include "ili9341.h"

uint16_t butt1=0,butt2=0,butt3=0,butt4=0;
uint16_t background = 0x2137;
uint16_t textcolor = ILI9341_BLACK;
uint16_t selectcolor = ILI9341_WHITE;
uint16_t place_in_menu=1;
uint16_t place_in_game=1;
uint16_t choice=1;

void buttons(uint16_t GPIO_Pin){
	switch (GPIO_Pin){
		case 2: //przycisk 1 --UP
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_12);
			//ILI9341_WriteString(10, 10, "Witam serdecznie", Font_7x10, textcolor, background);
			choice=1;
			break;
		case 4: //przycisk 2 --DOWN
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
			//ILI9341_WriteString(10, 10, "Dobry wieczor", Font_7x10, textcolor, background);
			choice=2;
			break;
		case 8: //przycisk 3 --ENTER
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_14);
			//ILI9341_WriteString(10, 10, "Szczesc Boze", Font_7x10, textcolor, background);
			switch(place_in_menu){
			case 1:
				place_in_menu=2;
				ILI9341_FillRectangle(43, 125, 154, 90, background);
				break;
			case 2:
				place_in_game=2;
				break;
			}
			break;
		case 16: //przycisk 4 --ESCAPE
			HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_15);
			//ILI9341_WriteString(10, 10, "Dzien dobry", Font_7x10, textcolor, background);
			switch(place_in_menu){
			case 2:
				place_in_menu=1;
				ILI9341_FillRectangle(43, 125, 154, 90, background);
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
	}
}

void game(){
	switch(place_in_game){
		case 1:
			display_menu();
			break;
		case 2:
			//this is game
			break;
		}
}
