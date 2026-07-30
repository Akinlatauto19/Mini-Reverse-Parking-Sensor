/******************************************************************************
 * File: state_machine.cpp
 ******************************************************************************/

#include <Arduino.h>

#include "state_machine.h"
#include "config.h"
#include "parking_indicator.h"

/******************************************************************************
 * Module Variables
 ******************************************************************************/

static ParkingState_t currentState = PARK_STATE_SAFE;

/******************************************************************************
 * Public Functions
 ******************************************************************************/

void StateMachine_Init(void)
{
    ParkingIndicator_Init();

    currentState = PARK_STATE_SAFE;

    ParkingIndicator_SetState(currentState);
}

ParkingState_t StateMachine_Update(float distanceCm)
{
    if (distanceCm >= DISTANCE_SAFE_CM)
    {
        currentState = PARK_STATE_SAFE;
    }
    else if (distanceCm >= DISTANCE_CAUTION_CM)
    {
        currentState = PARK_STATE_CAUTION;
    }
    else
    {
        currentState = PARK_STATE_WARNING;
    }

    ParkingIndicator_SetState(currentState);

    return currentState;
}