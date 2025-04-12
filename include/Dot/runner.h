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

Runner* Runner_Create ();
void    Runner_Delete (Runner* runner);

void Runner_Init (Runner* runner);
void Runner_Free (Runner* runner);

void Runner_SetTargetLPS (Runner* runner, uint32_t lps);
void Runner_Start (Runner* runner);
void Runner_Stop (Runner* runner);
void Runner_Next (Runner* runner);

#endif