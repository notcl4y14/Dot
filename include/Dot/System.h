#ifndef DOT_SYSTEM_H
#define DOT_SYSTEM_H

#include <SFML/System.h>

#include <stdint.h>

// extern clock_t _System_Clock;
extern sfClock* _System_Clock;

void System_Init ();
void System_Free ();

uint32_t System_GetTimeS ();
uint32_t System_GetTimeMS ();
uint64_t System_GetTimeNS ();

void System_SleepMS (uint32_t ms);

#endif