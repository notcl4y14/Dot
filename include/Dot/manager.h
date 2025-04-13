#ifndef DOT_MANAGER_H
#define DOT_MANAGER_H

#include <stdint.h>

typedef struct Manager
{
	void*    data;
	uint32_t size;
	uint32_t stride;
} Manager;

void Manager_Init (Manager* manager, uint32_t size, uint32_t stride);
void Manager_InitC (Manager* manager, uint32_t capacity, uint32_t unit_size);
void Manager_Free (Manager* manager);

void Manager_Resize (Manager* manager, uint32_t size);

void* Manager_GetUnitPtr (Manager* manager, uint32_t location);
void Manager_GetUnit (Manager* manager, uint32_t location, void* to);
void Manager_SetUnit (Manager* manager, uint32_t location, void* from);

#endif