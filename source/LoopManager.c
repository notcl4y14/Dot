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
	return;
}