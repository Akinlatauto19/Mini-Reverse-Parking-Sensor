#include "buzzer.h"
#include "config.h"

/******************************************************************************
 * @file    buzzer.cpp
 *
 * @brief   Buzzer Driver Implementation
 *
 * @details
 * Controls the audible warning for the Reverse Parking Sensor.
 *
 * Warning Behaviour
 * -----------------
 * SAFE      : Silent
 * CAUTION   : Silent
 * WARNING   : Intermittent 2 kHz beep
 *
 * The implementation is non-blocking using millis().
 *
 ******************************************************************************/

/******************************************************************************
 * Module Configuration
 ******************************************************************************/

#define BUZZER_FREQUENCY_HZ      (2000U)

#define WARNING_BEEP_INTERVAL_MS (250U)

/******************************************************************************
 * Module Variables
 ******************************************************************************/

static unsigned long previousToggleTime = 0U;

static bool buzzerEnabled = false;

/******************************************************************************
 * Public Functions
 ******************************************************************************/

void Buzzer_Init(void)
{
    pinMode(PIN_BUZZER, OUTPUT);

    noTone(PIN_BUZZER);

    buzzerEnabled = false;
}

/******************************************************************************
 * Update buzzer according to parking state
 ******************************************************************************/

void Buzzer_Update(ParkingState_t state)
{
    unsigned long currentTime = millis();

    switch (state)
    {
        case PARK_STATE_SAFE:

            noTone(PIN_BUZZER);

            buzzerEnabled = false;

            break;

        case PARK_STATE_CAUTION:

            noTone(PIN_BUZZER);

            buzzerEnabled = false;

            break;

        case PARK_STATE_WARNING:

            if ((currentTime - previousToggleTime) >= WARNING_BEEP_INTERVAL_MS)
            {
                previousToggleTime = currentTime;

                buzzerEnabled = !buzzerEnabled;

                if (buzzerEnabled == true)
                {
                    tone(PIN_BUZZER, BUZZER_FREQUENCY_HZ);
                }
                else
                {
                    noTone(PIN_BUZZER);
                }
            }

            break;

        default:

            noTone(PIN_BUZZER);

            buzzerEnabled = false;

            break;
    }
}