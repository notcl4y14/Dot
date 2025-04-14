#ifndef DOT_RUNNER_H
#define DOT_RUNNER_H

#include <stdint.h>

typedef struct Runner
{
	uint32_t lps_current;
	uint32_t lps_target;
	uint32_t lps_counter;
	uint32_t lps_counter_ntime;
	uint32_t loop_count;
} Runner;

void Runner_Init (Runner* runner);
void Runner_Free (Runner* runner); // This does nothing btw, so we might just nullify the data

void Runner_SetTargetLPS (Runner* runner, uint32_t lps); // TODO: remove this
void Runner_Start (Runner* runner);
void Runner_Stop (Runner* runner);
void Runner_Tick (Runner* runner);

#endif