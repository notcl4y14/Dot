#include <Dot/LoopManager.h>

#include <stdint.h>
#include <stdbool.h>

void LoopManager_Create (LoopManager* lm)
{
	lm->enabled = false;
	lm->lps_current = 0;
	lm->lps_counter = 0;
	lm->lps_update_time = 0;
	lm->lps_target = 0;
	lm->loop_count = 0;
}

void LoopManager_Delete (LoopManager* lm)
{
	lm->enabled = false;
	lm->lps_current = 0;
	lm->lps_counter = 0;
	lm->lps_update_time = 0;
	lm->lps_target = 0;
	lm->loop_count = 0;
}

void LoopManager_Tick (LoopManager* lm)
{
	// lm.loop_count++;
	// lm.lps_counter++;

	// sfml_time = sfClock_getElapsedTime(sfml_clock);

	// if (sfTime_asMilliseconds(sfml_time) >= lm.lps_update_time)
	// {
	// 	lm.lps_current = lm.lps_counter;
	// 	lm.lps_counter = 0;
	// 	lm.lps_update_time += 1000;
	// }
}