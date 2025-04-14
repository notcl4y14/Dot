#include <Dot/runner.h>

#include <SDL3/SDL.h>

#include <stdlib.h>
#include <stdint.h>

void Runner_Init (Runner* runner)
{
	runner->lps_current = 0;
	runner->lps_target = 0;
	runner->lps_counter = 0;
	runner->lps_counter_ntime = 0;
	runner->loop_count = 0;
}

void Runner_Free (Runner* runner)
{
	runner->lps_current = 0;
	runner->lps_target = 0;
	runner->lps_counter = 0;
	runner->lps_counter_ntime = 0;
	runner->loop_count = 0;
}

// 

inline void Runner_SetTargetLPS (Runner* runner, uint32_t lps)
{
	runner->lps_target = lps;
}

void Runner_Start (Runner* runner)
{
	runner->lps_counter = 0;
	runner->lps_counter_ntime = SDL_GetTicks();
}

// TODO: add something in Runner_Stop
void Runner_Stop (Runner* runner)
{
	return;
}

void Runner_Tick (Runner* runner)
{
	runner->loop_count++;
	runner->lps_counter++;

	if (SDL_GetTicks() >= runner->lps_counter_ntime)
	{
		runner->lps_current = runner->lps_counter;
		runner->lps_counter = 0;
		runner->lps_counter_ntime += 1000;
	}
}