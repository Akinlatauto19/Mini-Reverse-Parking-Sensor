#ifndef PARKING_INDICATOR_H
#define PARKING_INDICATOR_H

/******************************************************************************
 * @file    parking_indicator.h
 *
 * @brief   Parking Indicator Driver Interface
 *
 * @details
 * Controls the visual LED indicators of the Mini Reverse Parking Sensor.
 *
 * LED Behaviour
 * -------------
 * PARK_STATE_SAFE
 *      - Green LED ON
 *      - Yellow LED OFF
 *      - Red LED OFF
 *
 * PARK_STATE_CAUTION
 *      - Green LED OFF
 *      - Yellow LED ON
 *      - Red LED OFF
 *
 * PARK_STATE_DANGER
 *      - Green LED OFF
 *      - Yellow LED OFF
 *      - Red LED ON
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

#include "system_types.h"

/******************************************************************************
 * Public Function Prototypes
 ******************************************************************************/

/**
 * @brief Initialize parking indicator hardware.
 */
void ParkingIndicator_Init(void);

/**
 * @brief Update LED indicators according to parking state.
 *
 * @param state Current parking state.
 */
void ParkingIndicator_SetState(ParkingState_t state);

#ifdef __cplusplus
}
#endif

#endif /* PARKING_INDICATOR_H */