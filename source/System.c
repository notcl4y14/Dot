#include <Dot/System.h>

#include <SFML/System.h>

#include <stdlib.h>
#include <stdint.h>

// #ifdef WIN32
// 	#include <Windows.h>
// #else
// 	#include <unistd.h>
// #endif

#define DOT_TIME_SECOND      1
#define DOT_TIME_MILLISECOND 1000
#define DOT_TIME_NANOSECOND  1000000000

// clock_t _System_Clock;

// static struct timespec _Timespec;

sfClock* _System_Clock;

void System_Init ()
{
	// _System_Clock = clock();
	_System_Clock = sfClock_create();
}

void System_Free ()
{
	free(_System_Clock);

	_System_Clock = NULL;
}

inline uint32_t System_GetTimeS ()
{
	// timespec_get(&_Timespec, TIME_UTC);
	// return _Timespec.tv_sec;
	// return clock() - _System_Clock * 1000;
	sfTime const time = sfClock_getElapsedTime(_System_Clock);
	return sfTime_asSeconds(time);
}
inline uint32_t System_GetTimeMS ()
{
	// timespec_get(&_Timespec, TIME_UTC);
	// return (double)_Timespec.tv_nsec / 1000000;
	// return clock() - _System_Clock;
	sfTime const time = sfClock_getElapsedTime(_System_Clock);
	return sfTime_asMilliseconds(time);
}
inline uint64_t System_GetTimeNS ()
{
	// timespec_get(&_Timespec, TIME_UTC);
	// return _Timespec.tv_nsec;
	// return 0;
	sfTime const time = sfClock_getElapsedTime(_System_Clock);
	return sfTime_asMicroseconds(time) / 1000;
}

inline void System_SleepMS (uint32_t ms)
{
	sfSleep( sfMilliseconds(ms) );
	// #ifdef WIN32
	// 	Sleep(ms);
	// #else
	// 	usleep(ms * 1000);
	// #endif
}