#ifndef ULTRASONIC_H
#define ULTRASONIC_H

/******************************************************************************
 * @file    ultrasonic.h
 *
 * @brief   HC-SR04 Ultrasonic Sensor Driver
 *
 * @details
 * Provides functions to initialize and read distance from the
 * HC-SR04 ultrasonic sensor.
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

#include <Arduino.h>
#include "config.h"

/******************************************************************************
 * Public Functions
 ******************************************************************************/

/**
 * @brief Initialize ultrasonic sensor GPIO pins.
 */
void Ultrasonic_Init(void);

/**
 * @brief Read obstacle distance.
 *
 * @return Distance in centimeters.
 */
float Ultrasonic_GetDistanceCm(void);

#ifdef __cplusplus
}
#endif

#endif /* ULTRASONIC_H */