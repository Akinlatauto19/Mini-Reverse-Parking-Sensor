/******************************************************************************
 * File: ultrasonic.cpp
 ******************************************************************************/

#include <Arduino.h>

#include "config.h"
#include "ultrasonic.h"

/******************************************************************************
 * Module Constants
 ******************************************************************************/

#define ULTRASONIC_NO_ECHO_DISTANCE_CM    (999.0F)

/******************************************************************************
 * Public Functions
 ******************************************************************************/

void Ultrasonic_Init(void)
{
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);

    digitalWrite(PIN_TRIG, LOW);
}

float Ultrasonic_GetDistanceCm(void)
{
    uint32_t durationUs;

    float distanceCm;

    /**********************************************************************
     * Generate 10 µs trigger pulse
     **********************************************************************/
    digitalWrite(PIN_TRIG, LOW);
    delayMicroseconds(2U);

    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10U);

    digitalWrite(PIN_TRIG, LOW);

    /**********************************************************************
     * Measure echo pulse width
     **********************************************************************/
    durationUs = pulseIn(PIN_ECHO,
                         HIGH,
                         ULTRASONIC_TIMEOUT_US);

    /**********************************************************************
     * Timeout occurred
     **********************************************************************/
    if (durationUs == 0U)
    {
        return ULTRASONIC_NO_ECHO_DISTANCE_CM;
    }

    /**********************************************************************
     * Distance Calculation
     *
     * Speed of sound = 343 m/s
     *                = 0.0343 cm/µs
     *
     * Distance = (Time × Speed) / 2
     *
     * Divide by two because the ultrasonic pulse travels to the obstacle
     * and back to the sensor.
     **********************************************************************/
    distanceCm = ((float)durationUs * 0.0343F) / 2.0F;

    return distanceCm;
}