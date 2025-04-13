#ifndef DOT_MAIN_H
#define DOT_MAIN_H

#include <stdint.h>

int32_t main (int32_t argc, char** argv);

void Init ();
void Quit ();
void Loop ();

void ProcessEvents ();
void Update ();
void Render ();

#endif