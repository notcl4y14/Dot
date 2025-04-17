#ifndef DOT_LOOPMANAGER_H
#define DOT_LOOPMANAGER_H

#include <stdint.h>
#include <stdbool.h>

struct         LoopManager;
typedef struct LoopManager LoopManager;

struct LoopManager
{
	bool enabled;
	int32_t lps_current;
	int32_t lps_counter;
	int32_t lps_update_time;
	int32_t lps_target; // -1 if no max value
	int32_t loop_count;
};

void LoopManager_Create (LoopManager* lm);
void LoopManager_Delete (LoopManager* lm);

void LoopManager_Tick (LoopManager* lm);

#endif