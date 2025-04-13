#include <Dot/manager.h>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void Manager_Init (Manager* manager, uint32_t size, uint32_t stride)
{
	manager->data = calloc(size, 1);
	manager->size = size;
	manager->stride = stride;
}

void Manager_InitC (Manager* manager, uint32_t capacity, uint32_t unit_size)
{
	manager->data = calloc(capacity, unit_size);
	manager->size = capacity * unit_size;
	manager->stride = unit_size;
}

void Manager_Free (Manager* manager)
{
	free(manager->data);
	manager->data = NULL;
}

// 

void Manager_Resize (Manager* manager, uint32_t size)
{
	manager->data = realloc(manager->data, size);
	manager->size = size;
}

// 

void* Manager_GetUnitPtr (Manager* manager, uint32_t location)
{
	return (uint8_t*)(manager->data) + (location * manager->stride);
}

void Manager_GetUnit (Manager* manager, uint32_t location, void* to)
{
	memcpy(to, Manager_GetUnitPtr(manager, location), manager->stride);
}

void Manager_SetUnit (Manager* manager, uint32_t location, void* from)
{
	memcpy(Manager_GetUnitPtr(manager, location), from, manager->stride);
}