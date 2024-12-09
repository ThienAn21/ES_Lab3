/*
 * displayLightTraffic.c
 *
 *  Created on: Nov 16, 2024
 *      Author: ADMIN
 */

#include "displayLightTraffic.h"

int toggleVar = 0;

void drawAllGray(int time1, int time2){
	lcd_DrawCircle(50, 50, GRAY, 40, 1);
	lcd_DrawCircle(50, 140, GRAY, 40, 1);
	lcd_DrawCircle(50, 230, GRAY, 40, 1);

	lcd_ShowIntNum(95, 140, time1, 2, BRED, WHITE, 16);

	lcd_DrawCircle(190, 50, GRAY, 40, 1);
	lcd_DrawCircle(190, 140, GRAY, 40, 1);
	lcd_DrawCircle(190, 230, GRAY, 40, 1);

	lcd_ShowIntNum(125, 140, time2, 2, BRED, WHITE, 16);
}

void drawRedGreen(int time1, int time2){
	lcd_DrawCircle(50, 50, GRED, 40, 1);
	lcd_DrawCircle(50, 140, GRAY, 40, 1);
	lcd_DrawCircle(50, 230, GRAY, 40, 1);

	lcd_ShowIntNum(95, 140, time1, 2, BRED, WHITE, 16);

	lcd_DrawCircle(190, 50, GRAY, 40, 1);
	lcd_DrawCircle(190, 140, GRAY, 40, 1);
	lcd_DrawCircle(190, 230, GREEN, 40, 1);

	lcd_ShowIntNum(125, 140, time2, 2, BRED, WHITE, 16);
}

void drawRedYellow(int time1, int time2){
	lcd_DrawCircle(50, 50, GRED, 40, 1);
	lcd_DrawCircle(50, 140, GRAY, 40, 1);
	lcd_DrawCircle(50, 230, GRAY, 40, 1);

	lcd_ShowIntNum(95, 140, time1, 2, BRED, WHITE, 16);

	lcd_DrawCircle(190, 50, GRAY, 40, 1);
	lcd_DrawCircle(190, 140, YELLOW, 40, 1);
	lcd_DrawCircle(190, 230, GRAY, 40, 1);

	lcd_ShowIntNum(125, 140, time2, 2, BRED, WHITE, 16);
}

void drawGreenRed(int time1, int time2){
	lcd_DrawCircle(50, 50, GRAY, 40, 1);
	lcd_DrawCircle(50, 140, GRAY, 40, 1);
	lcd_DrawCircle(50, 230, GREEN, 40, 1);

	lcd_ShowIntNum(95, 140, time1, 2, BRED, WHITE, 16);

	lcd_DrawCircle(190, 50, GRED, 40, 1);
	lcd_DrawCircle(190, 140, GRAY, 40, 1);
	lcd_DrawCircle(190, 230, GRAY, 40, 1);

	lcd_ShowIntNum(125, 140, time2, 2, BRED, WHITE, 16);
}

void drawYellowRed(int time1, int time2){
	lcd_DrawCircle(50, 50, GRAY, 40, 1);
	lcd_DrawCircle(50, 140, YELLOW, 40, 1);
	lcd_DrawCircle(50, 230, GRAY, 40, 1);

	lcd_ShowIntNum(95, 140, time1, 2, BRED, WHITE, 16);

	lcd_DrawCircle(190, 50, GRED, 40, 1);
	lcd_DrawCircle(190, 140, GRAY, 40, 1);
	lcd_DrawCircle(190, 230, GRAY, 40, 1);

	lcd_ShowIntNum(125, 140, time2, 2, BRED, WHITE, 16);
}

void drawRedGreenToggle(int time1, int time2){
	if(toggleVar == 0){
		drawRedGreen(time1, time2);
	}
	else {
		drawAllGray(time1, time2);
	}
}

void drawYellowRedToggle(int time1, int time2){
	if(toggleVar == 0){
		drawYellowRed(time1, time2);
	}
	else {
		drawAllGray(time1, time2);
	}
}

void drawGreenRedToggle(int time1, int time2){
	if(toggleVar == 0){
		drawGreenRed(time1, time2);
	}
	else {
		drawAllGray(time1, time2);
	}
}
