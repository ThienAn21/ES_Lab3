/*
 * displayLightTraffic.h
 *
 *  Created on: Nov 16, 2024
 *      Author: ADMIN
 */

#ifndef INC_DISPLAYLIGHTTRAFFIC_H_
#define INC_DISPLAYLIGHTTRAFFIC_H_

#include "led_7seg.h"
#include "lcd.h"
#include "picture.h"

extern int toggleVar;

void drawAllGray(int time1, int time2);

void drawRedGreen(int time1, int time2);

void drawRedYellow(int time1, int time2);

void drawGreenRed(int time1, int time2);

void drawYellowRed(int time1, int time2);

void drawRedGreenToggle(int time1, int time2);

void drawYellowRedToggle(int time1, int time2);

void drawGreenRedToggle(int time1, int time2);

#endif /* INC_DISPLAYLIGHTTRAFFIC_H_ */
