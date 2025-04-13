#ifndef DOT_MAIN_H
#define DOT_MAIN_H

#include <Dot/dot_frame.h>
#include <Dot/sdl_frame.h>

#include <stdint.h>

// Global access
extern DotFrame* _DotFrame;
extern SDLFrame* _SDLFrame;

int32_t main (int32_t argc, char** argv);

void Init ();
void Quit ();
void Loop ();

void ProcessEvents ();
void Update ();
void Render ();

#endif