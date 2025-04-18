#ifndef DOT_RESMANAGER_H
#define DOT_RESMANAGER_H

#include <stdint.h>

struct         ResManager;
typedef struct ResManager ResManager;

struct ResManager
{
	void*    data;
	uint32_t capacity;
	uint32_t count;
	uint32_t data_size;
	uint32_t unit_size;
};

void ResManager_Create (ResManager* rm);
void ResManager_Delete (ResManager* rm);

void ResManager_Init (ResManager* rm, uint32_t capacity, uint32_t unit_size);
void ResManager_Resize (ResManager* rm, uint32_t capacity);

void ResManager_LoadUnit (ResManager* rm, uint32_t id, void* from);
void* ResManager_GetUnitP (ResManager* rm, uint32_t id);
void ResManager_GetUnit (ResManager* rm, uint32_t id, void* to);

#endif