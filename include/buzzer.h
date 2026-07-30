#ifndef BUZZER_H
#define BUZZER_H

/**
 *=========================================================
 * @file    buzzer.h
 *
 * @brief   Buzzer Driver Interface
 *
 * @details
 * This module controls the audible warning indicator for
 * the Mini Reverse Parking Sensor.
 *
 * Responsibilities
 * ----------------
 * - Initialize buzzer hardware.
 * - Generate warning beep pattern.
 * - Update buzzer output according to parking state.
 *
 * System Behaviour
 * ----------------
 * PARK_STATE_SAFE      -> Buzzer OFF
 * PARK_STATE_CAUTION   -> Buzzer OFF
 * PARK_STATE_DANGER    -> Slow intermittent beep
 *
 *=========================================================
 */

#include <Arduino.h>
#include "system_types.h"

/*=========================================================
 * Function Prototypes
 *========================================================*/

/**
 * @brief Initialize buzzer GPIO.
 */
void Buzzer_Init(void);

/**
 * @brief Update buzzer according to current parking state.
 *
 * @param state Current parking state.
 */
void Buzzer_Update(ParkingState_t state);

#endif