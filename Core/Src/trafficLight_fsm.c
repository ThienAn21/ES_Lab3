/*
 * trafficLight_fsm.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ADMIN
 */

#include "trafficLight_fsm.h"

int lightTime1[3] = {6, 2, 5}; // second // RED, YELLOW, GREEN
int lightTime2[3] = {7, 2, 4}; // second // RED, YELLOW, GREEN

int displayLightTime1 = 0;
int displayLightTime2 = 0;

TrafficLightState lightState = LINIT;
SystemState systemState = NORMAL;

void traffic_light_fsm() {

    switch (systemState) {
    case NORMAL:
    	if(button_count[0] == 1){
    		systemState = MODIFYRED;
    		setTimer4(0.25*1000/MAINTASKTIME); //0.25s
    		toggleVar = 0;
    		displayLightTime1 = lightTime1[0];
    		displayLightTime2 = lightTime2[2];
    		drawRedGreenToggle(displayLightTime1, displayLightTime2);
    	}
    	else if (lightState == LINIT){
    		setTimer3(1000/MAINTASKTIME); //1s
    		displayLightTime1 = lightTime1[0];
    		displayLightTime2 = lightTime2[2];
    		lightState = LREDGREEN;
        	drawRedGreen(displayLightTime1, displayLightTime2);
    	}
    	else if (lightState == LREDGREEN){
    		if(flag_timer3){
    			setTimer3(1000/MAINTASKTIME);
    			displayLightTime1--;
    			displayLightTime2--;
    		}
    		if(displayLightTime2 == 0){
    			setTimer3(1000/MAINTASKTIME);
    			lightState = LREDYELLOW;
        		displayLightTime2 = lightTime2[1];
            	drawRedYellow(displayLightTime1, displayLightTime2);
    		}
    		else {
    			lightState == LREDGREEN;
    			drawRedGreen(displayLightTime1, displayLightTime2);
    		}
    	}
    	else if (lightState == LREDYELLOW){
    		if(flag_timer3){
    			setTimer3(1000/MAINTASKTIME);
    			displayLightTime1--;
    			displayLightTime2--;
    		}
    		if(displayLightTime2 == 0){
    			setTimer3(1000/MAINTASKTIME);
    			lightState = LGREENRED;
        		displayLightTime1 = lightTime1[2];
        		displayLightTime2 = lightTime2[0];
        		drawGreenRed(displayLightTime1, displayLightTime2);
    		}
    		else {
    			lightState == LREDYELLOW;
    			drawRedYellow(displayLightTime1, displayLightTime2);
    		}
    	}
    	else if (lightState == LGREENRED){
    		if(flag_timer3){
    			setTimer3(1000/MAINTASKTIME);
    			displayLightTime1--;
    			displayLightTime2--;
    		}
    		if(displayLightTime1 == 0){
    			setTimer3(1000/MAINTASKTIME);
    			lightState = LYELLOWRED;
        		displayLightTime1 = lightTime1[1];
        		drawYellowRed(displayLightTime1, displayLightTime2);
    		}
    		else {
    			lightState == LGREENRED;
    			drawGreenRed(displayLightTime1, displayLightTime2);
    		}
    	}
    	else if (lightState == LYELLOWRED){
    		if(flag_timer3){
    			setTimer3(1000/MAINTASKTIME);
    			displayLightTime1--;
    			displayLightTime2--;
    		}
    		if(displayLightTime1 == 0){
    			setTimer3(1000/MAINTASKTIME);
    			lightState = LREDGREEN;
        		displayLightTime1 = lightTime1[0];
        		displayLightTime2 = lightTime2[2];
        		drawRedGreen(displayLightTime1, displayLightTime2);
    		}
    		else {
    			lightState == LYELLOWRED;
    			drawYellowRed(displayLightTime1, displayLightTime2);
    		}
    	}
    	break;
    case MODIFYRED:
		if(flag_timer4){
			toggleVar = 1 - toggleVar;
			setTimer4(0.25*1000/MAINTASKTIME); //0.25s
		}
    	if(button_count[0] == 1){
    		systemState = MODIFYYELLOW;
    		setTimer4(0.25*1000/MAINTASKTIME); //0.25s
    		toggleVar = 0;
    		displayLightTime1 = lightTime1[1];
    		displayLightTime2 = lightTime2[0];
    		drawYellowRedToggle(displayLightTime1, displayLightTime2);
    	}
    	else {
        	if(button_count[1] == 1){
        		if( (displayLightTime1 - lightTime2[1]) < 99 && displayLightTime1 < 99) {
            		++displayLightTime1;
            		displayLightTime2 = displayLightTime1 - lightTime2[1];
        		}
        	}
        	if(button_count[2] == 1){
        		if( (displayLightTime1 - lightTime2[1]) > 1 && displayLightTime1 > 1) {
            		--displayLightTime1;
            		displayLightTime2 = displayLightTime1 - lightTime2[1];
        		}
        	}
        	if(button_count[3] == 1){
        		lightTime1[0] = displayLightTime1;
        		lightTime2[2] = displayLightTime2;
        	}
    		systemState = MODIFYRED;
    		drawRedGreenToggle(displayLightTime1, displayLightTime2);
    	}
    	break;
    case MODIFYYELLOW:
		if(flag_timer4){
			toggleVar = 1 - toggleVar;
			setTimer4(0.25*1000/MAINTASKTIME); //0.25s
		}
    	if(button_count[0] == 1){
    		systemState = MODIFYGREEN;
    		setTimer4(0.25*1000/MAINTASKTIME); //0.25s
    		toggleVar = 0;
    		displayLightTime1 = lightTime1[2];
    		displayLightTime2 = lightTime2[0];
    		drawGreenRedToggle(displayLightTime1, displayLightTime2);
    	}
    	else {
        	if(button_count[1] == 1){
        		if( (displayLightTime1 + lightTime1[2]) < 99 && displayLightTime1 < 99) {
            		++displayLightTime1;
            		displayLightTime2 = displayLightTime1 + lightTime1[2];
        		}
        	}
        	if(button_count[2] == 1){
        		if( (displayLightTime1 + lightTime1[2]) > 1 && displayLightTime1 > 1) {
            		--displayLightTime1;
            		displayLightTime2 = displayLightTime1 + lightTime1[2];
        		}
        	}
        	if(button_count[3] == 1){
        		lightTime1[1] = displayLightTime1;
        		lightTime2[0] = displayLightTime2;
        	}
    		systemState = MODIFYYELLOW;
    		drawYellowRedToggle(displayLightTime1, displayLightTime2);
    	}
    	break;
    case MODIFYGREEN:
		if(flag_timer4){
			toggleVar = 1 - toggleVar;
			setTimer4(0.25*1000/MAINTASKTIME); //0.25s
		}
    	if(button_count[0] == 1){
    		systemState = NORMAL;
    		setTimer3(1000/MAINTASKTIME); //1s
    		displayLightTime1 = lightTime1[0];
    		displayLightTime2 = lightTime2[2];
    		lightState = LREDGREEN;
        	drawRedGreen(displayLightTime1, displayLightTime2);
    	}
    	else {
        	if(button_count[1] == 1){
        		if( (displayLightTime1 + lightTime1[1]) < 99 && displayLightTime1 < 99) {
            		++displayLightTime1;
            		displayLightTime2 = displayLightTime1 + lightTime1[1];
        		}
        	}
        	if(button_count[2] == 1){
        		if( (displayLightTime1 + lightTime1[1]) > 1 && displayLightTime1 > 1) {
            		--displayLightTime1;
            		displayLightTime2 = displayLightTime1 + lightTime1[1];
        		}
        	}
        	if(button_count[3] == 1){
        		lightTime1[2] = displayLightTime1;
        		lightTime2[0] = displayLightTime2;
        	}
    		systemState = MODIFYGREEN;
    		drawGreenRedToggle(displayLightTime1, displayLightTime2);
    	}
    	break;

    default:
        return;
    }
}
