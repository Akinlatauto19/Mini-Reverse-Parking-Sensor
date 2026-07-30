#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

/******************************************************************************
 * @file    state_machine.h
 *
 * @brief   Reverse Parking Sensor State Machine
 *
 * @details
 * Determines the current parking state from the measured
 * ultrasonic distance.
 *
 * Responsibilities
 * ----------------
 *  - Evaluate obstacle distance
 *  - Determine parking state
 *  - Update visual indicators
 *  - Notify other modules of current state
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

#include <Arduino.h>
#include "system_types.h"

/******************************************************************************
 * Public Functions
 ******************************************************************************/

/**
 * @brief Initialize the state machine.
 */
void StateMachine_Init(void);

/**
 * @brief Update parking state.
 *
 * @param distanceCm Measured obstacle distance (cm)
 *
 * @return Current parking state.
 */
ParkingState_t StateMachine_Update(float distanceCm);

#ifdef __cplusplus
}
#endif

#endif /* STATE_MACHINE_H */