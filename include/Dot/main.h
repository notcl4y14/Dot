#ifndef DOT_MAIN_H
#define DOT_MAIN_H

#include <stdint.h>

int32_t main (int32_t argc, char** argv);

void init ();
void quit ();
void loop ();

void process_events ();
void update ();
void render ();

#endif