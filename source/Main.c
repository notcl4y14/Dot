#include <Dot/Main.h>
#include <Dot/CellBrush.h>
#include <Dot/CellChunk.h>
#include <Dot/CellChunkArray.h>
#include <Dot/CellOptions.h>
#include <Dot/DotApp.h>
#include <Dot/SFMLApp.h>
#include <Dot/System.h>

#include <SFML/Graphics.h>
#include <SFML/System.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

DotApp* Dot_DotApp;
SFMLApp* Dot_SFMLApp;

CellChunkArray cc_arr;
FILE* file_world;

int32_t cellbrush_x = 0;
int32_t cellbrush_y = 0;
int32_t cellbrush_size = 8;

int32_t main (int32_t argc, char** argv)
{
	Main_Setup();
	Main_Load();

	Main_Loop();

	Main_Quit();

	return 0;
}

void Main_Setup ()
{
	System_Init();
	srand(System_GetTimeMS());

	// Allocate global variables
	Dot_DotApp = malloc(sizeof (DotApp));
	Dot_SFMLApp = malloc(sizeof (SFMLApp));

	// Initialize global variables
	DotApp_Create(Dot_DotApp);
	SFMLApp_Create(Dot_SFMLApp);

	// Create Window
	Dot_SFMLApp->window = sfRenderWindow_create(
		(sfVideoMode) {800, 600},
		"Dot",
		sfDefaultStyle,
		NULL);

	// Initialize cell chunk
	// CellChunk_Init(&(Dot_DotApp->cell_chunk), 128, 128);
	CellChunkArray_Create(&cc_arr);
	file_world = fopen("path_to_dot_world_file", "r");
	exit(1); // remove this

	// char buffer[4];
	// fread(buffer, 4, 1, file_world);

	// printf("%d\n", (int)buffer);

	CellChunkArray_LoadFromFile(&cc_arr, file_world);
	CellChunkArray_ReadChunk(&cc_arr, &Dot_DotApp->cell_chunk, 0, 0);

	// Initialize resource managers
	ResManager_Init(&(Dot_DotApp->cell_opt_manager), 4, sizeof(CellOptions));

	// Initialize loop managers
	Dot_DotApp->loop.lps_target = 60;
	Dot_DotApp->loop.loop_count = 0;
}

void Main_Loop ()
{
	sfRenderWindow* const sfml_window = Dot_SFMLApp->window;
	LoopManager* const dot_loop = &(Dot_DotApp->loop);

	Dot_DotApp->is_running = true;
	Dot_DotApp->loop.enabled = true;
	Dot_DotApp->loop.lps_update_time = System_GetTimeMS();

	while (Dot_DotApp->is_running)
	{
		// Process Events
		Main_ProcessEvts();

		// Update
		// Render
		Main_Update();
		Main_Render();

		// Tick
		uint32_t const elapsed_time = System_GetTimeMS();
		bool const should_render_fps = (elapsed_time >= dot_loop->lps_update_time);

		LoopManager_Tick(dot_loop);

		if (should_render_fps == true)
		{
			printf("FPS: %d\n", dot_loop->lps_current);
		}

		// Delay
		uint32_t const sleep_time = (1000 / Dot_DotApp->loop.lps_target);
		System_SleepMS(sleep_time);
	}

	sfRenderWindow_close(sfml_window);
}

void Main_Quit ()
{
	fclose(file_world);
	CellChunkArray_Delete(&cc_arr);

	// Delete global variables
	DotApp_Delete(Dot_DotApp);
	SFMLApp_Delete(Dot_SFMLApp);

	// Free global variables
	free(Dot_DotApp);
	free(Dot_SFMLApp);

	// Set global variables' pointers to NULL
	Dot_DotApp = NULL;
	Dot_SFMLApp = NULL;
}

void Main_Load ()
{
	#include <Dot/CellUpdateMethod.h>

	CellOptions air_cell_opt =
	{
		.id = 0,
		.should_update = false,
		.should_render = false,
		.is_empty = true,
		.is_solid = false,
		.is_powder = false,
		.is_fluid = false,
		.update_method = NULL,
	};

	CellOptions sand_cell_opt =
	{
		.id = 1,
		.should_update = true,
		.should_render = true,
		.is_empty = false,
		.is_solid = false,
		.is_powder = true,
		.is_fluid = false,
		.update_method = _CellUpdateMethod_Powder,
	};

	DotApp_LoadCellOptions(Dot_DotApp, 0, air_cell_opt);
	DotApp_LoadCellOptions(Dot_DotApp, 1, sand_cell_opt);
}

void Main_ProcessEvts ()
{
	sfRenderWindow* const sfml_window = Dot_SFMLApp->window;
	sfEvent* const sfml_event = &(Dot_SFMLApp->event);

	while (sfRenderWindow_pollEvent(sfml_window, sfml_event))
	{
		if (sfml_event->type == sfEvtClosed)
		{
			Dot_DotApp->is_running = false;
		}
	}
}

void Main_Update ()
{
	CellChunk* const cell_chunk = &(Dot_DotApp->cell_chunk);

	// CellChunk_Update(cell_chunk);

	// Add sand cell each tick
	// {
	// 	Cell cell = (Cell) {1};
	// 	CellChunk_SetCell(cell_chunk, 16, 0, cell);
	// }

	// Update CellBrush
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
	{
		cellbrush_x -= 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight))
	{
		cellbrush_x += 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyUp))
	{
		cellbrush_y -= 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown))
	{
		cellbrush_y += 1;
	}

	// cellbrush_x = cellbrush_x < 0
	//             ? 0
	//             : cellbrush_x > cell_chunk->width - cellbrush_size
	// 	            ? cell_chunk->width - cellbrush_size
	// 	            : cellbrush_x;

	// cellbrush_y = cellbrush_y < 0
	//             ? 0
	//             : cellbrush_y > cell_chunk->height - cellbrush_size
	// 	            ? cell_chunk->height - cellbrush_size
	// 	            : cellbrush_y;

	     if (cellbrush_x < 0) cellbrush_x = 0;
	else if (cellbrush_x > cell_chunk->width - cellbrush_size) cellbrush_x = cell_chunk->width - cellbrush_size;

	     if (cellbrush_y < 0) cellbrush_y = 0;
	else if (cellbrush_y > cell_chunk->height - cellbrush_size) cellbrush_y = cell_chunk->height - cellbrush_size;

	if (sfKeyboard_isKeyPressed(sfKeySpace))
	{
		CellBrush_Rectangle(cell_chunk, cellbrush_x, cellbrush_y, cellbrush_size, cellbrush_size, (Cell){1});
	}
	if (sfKeyboard_isKeyPressed(sfKeyZ))
	{
		CellBrush_Rectangle(cell_chunk, cellbrush_x, cellbrush_y, cellbrush_size, cellbrush_size, (Cell){0});
	}
}

void Main_Render ()
{
	sfRenderWindow* const sfml_window = Dot_SFMLApp->window;
	CellChunk* const cell_chunk = &(Dot_DotApp->cell_chunk);

	sfRenderWindow_clear(sfml_window, sfBlack);

	CellChunk_Render(cell_chunk);

	// Render CellBrush
	{
		sfRectangleShape* rect = Dot_SFMLApp->rect;
		sfRectangleShape_setPosition(rect, (sfVector2f) {cellbrush_x * 4, cellbrush_y * 4});
		sfRectangleShape_setSize(rect, (sfVector2f) {cellbrush_size * 4, cellbrush_size * 4});
		sfRectangleShape_setFillColor(rect, (sfColor){255, 255, 255, 255 / 4});

		sfRenderWindow_drawRectangleShape(sfml_window, rect, NULL);
	}

	sfRenderWindow_display(sfml_window);
}