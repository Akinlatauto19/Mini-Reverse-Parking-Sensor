/******************************************************************************
 * File: parking_indicator.cpp
 ******************************************************************************/

#include <Arduino.h>

#include "config.h"
#include "parking_indicator.h"
#include "system_types.h"

/******************************************************************************
 * Private Functions
 ******************************************************************************/

/**
 * @brief Turn OFF all parking LEDs.
 */
static void ParkingIndicator_AllOff(void)
{
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_LED_YELLOW, LOW);
    digitalWrite(PIN_LED_RED, LOW);
}

/******************************************************************************
 * Public Functions
 ******************************************************************************/

void ParkingIndicator_Init(void)
{
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_YELLOW, OUTPUT);
    pinMode(PIN_LED_RED, OUTPUT);

    ParkingIndicator_AllOff();
}

void ParkingIndicator_SetState(ParkingState_t state)
{
    ParkingIndicator_AllOff();

    switch (state)
    {
        case PARK_STATE_SAFE:

            digitalWrite(PIN_LED_GREEN, HIGH);

            break;

        case PARK_STATE_CAUTION:

            digitalWrite(PIN_LED_YELLOW, HIGH);

            break;

        case PARK_STATE_WARNING:

            digitalWrite(PIN_LED_RED, HIGH);

            break;

        default:

            ParkingIndicator_AllOff();

            break;
    }
}