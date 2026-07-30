#ifndef CONFIG_H
#define CONFIG_H

/******************************************************************************
 * @file    config.h
 *
 * @brief   Project Configuration File
 *
 * @details
 * Contains all hardware pin assignments, distance thresholds,
 * timing constants and project-wide configuration values.
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/*=========================================================
 * Hardware Pin Definitions
 *========================================================*/

#define PIN_TRIG                (9U)
#define PIN_ECHO                (8U)

#define PIN_LED_GREEN           (2U)
#define PIN_LED_YELLOW          (3U)
#define PIN_LED_RED             (4U)

#define PIN_BUZZER              (5U)

/*=========================================================
 * Parking Distance Thresholds (cm)
 *========================================================*/

#define DISTANCE_SAFE_CM        (100.0F)
#define DISTANCE_CAUTION_CM     (50.0F)
#define DISTANCE_DANGER_CM      (20.0F)

/*=========================================================
 * Ultrasonic Configuration
 *========================================================*/

#define ULTRASONIC_TIMEOUT_US   (30000UL)

/*=========================================================
 * Main Loop Timing
 *========================================================*/

#define SYSTEM_LOOP_DELAY_MS    (100U)

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_H */