/******************************************************************************
 * File: main.cpp
 *
 * Project:
 *      Mini Reverse Parking Assist System
 *
 * Description:
 *      Main application entry point.
 *
 *      Responsibilities
 *      ----------------
 *      • Initialize all modules
 *      • Read ultrasonic distance
 *      • Execute parking state machine
 *      • Update buzzer warning
 *
 ******************************************************************************/

#include <Arduino.h>

#include "config.h"
#include "ultrasonic.h"
#include "state_machine.h"
#include "buzzer.h"

/******************************************************************************
 * Arduino Setup
 ******************************************************************************/

void setup(void)
{
    Ultrasonic_Init();

    StateMachine_Init();

    Buzzer_Init();
}

/******************************************************************************
 * Arduino Main Loop
 ******************************************************************************/

void loop(void)
{
    float distanceCm;

    ParkingState_t parkingState;

    /**********************************************************************
     * Read Distance
     **********************************************************************/
    distanceCm = Ultrasonic_GetDistanceCm();

    /**********************************************************************
     * Determine Parking State
     **********************************************************************/
    parkingState = StateMachine_Update(distanceCm);

    /**********************************************************************
     * Update Audible Warning
     **********************************************************************/
    Buzzer_Update(parkingState);

    /**********************************************************************
     * Maintain Constant Loop Timing
     **********************************************************************/
    delay(SYSTEM_LOOP_DELAY_MS);
}