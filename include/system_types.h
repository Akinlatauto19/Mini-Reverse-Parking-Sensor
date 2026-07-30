#ifndef SYSTEM_TYPES_H
#define SYSTEM_TYPES_H

/******************************************************************************
 * File: system_types.h
 *
 * Description:
 *      Common project data types.
 *
 *      This file contains all shared enumerations and structures used across
 *      the project.
 *
 *      Any module requiring these common types should include this file.
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
 * Parking Indicator States
 *
 * PARK_STATE_SAFE
 *      Vehicle is far from the obstacle.
 *
 * PARK_STATE_CAUTION
 *      Vehicle is approaching the obstacle.
 *
 * PARK_STATE_WARNING
 *      Vehicle is dangerously close to the obstacle.
 *
 ******************************************************************************/
typedef enum
{
    PARK_STATE_SAFE = 0,

    PARK_STATE_CAUTION,

    PARK_STATE_WARNING

} ParkingState_t;

/******************************************************************************
 * Sensor Data Structure
 *
 * Description:
 *      Holds all sensor measurements collected by the system.
 *
 ******************************************************************************/
typedef struct
{
    float distanceCm;

} SensorData_t;

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_TYPES_H */