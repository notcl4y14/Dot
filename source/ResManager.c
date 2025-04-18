#include <Dot/ResManager.h>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void ResManager_Create (ResManager* rm)
{
	rm->data = NULL;
	rm->count = 0;
	rm->capacity = 0;
	rm->data_size = 0;
	rm->unit_size = 0;
}
void ResManager_Delete (ResManager* rm)
{
	free(rm->data);

	rm->data = NULL;
	rm->count = 0;
	rm->capacity = 0;
	rm->data_size = 0;
	rm->unit_size = 0;
}

void ResManager_Init (ResManager* rm, uint32_t capacity, uint32_t unit_size)
{
	uint32_t const data_size = capacity * unit_size;
	rm->data = calloc(capacity, unit_size);
	rm->count = 0;
	rm->capacity = capacity;
	rm->data_size = data_size;
	rm->unit_size = unit_size;
}
void ResManager_Resize (ResManager* rm, uint32_t capacity)
{
	uint32_t const data_size = capacity * rm->unit_size;
	rm->data = realloc(rm->data, data_size);
	rm->capacity = capacity;
	rm->data_size = data_size;
}

void ResManager_LoadUnit (ResManager* rm, uint32_t id, void* from)
{
	void* const copy_dest = ResManager_GetUnitP(rm, id);
	memcpy(copy_dest, from, rm->unit_size);
}
inline void* ResManager_GetUnitP (ResManager* rm, uint32_t id)
{
	return (uint8_t*)(rm->data) + (id * rm->unit_size);
}
void ResManager_GetUnit (ResManager* rm, uint32_t id, void* to)
{
	void* const copy_source = ResManager_GetUnitP(rm, id);
	memcpy(to, copy_source, rm->unit_size);
}