/*
 * trafficLight_fsm.h
 *
 *  Created on: Nov 15, 2024
 *      Author: ADMIN
 */

#ifndef INC_TRAFFICLIGHT_FSM_H_
#define INC_TRAFFICLIGHT_FSM_H_

#include "displayLightTraffic.h"
#include "software_timer.h"
#include "button.h"

typedef enum {
    LREDGREEN,
	LREDYELLOW,
    LGREENRED,
	LYELLOWRED,
	LINIT
} TrafficLightState;

typedef enum {
    NORMAL,
	MODIFYRED,
	MODIFYYELLOW,
	MODIFYGREEN,
} SystemState;

#define MAINTASKTIME 1 // 50ms

extern int lightTime1[3];
extern int lightTime2[3];

extern TrafficLightState lightState;
extern SystemState systemState;

void traffic_light_fsm();

#endif /* INC_TRAFFICLIGHT_FSM_H_ */
