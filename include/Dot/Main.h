#ifndef DOT_MAIN_H
#define DOT_MAIN_H

#include <Dot/DotApp.h>
#include <Dot/SFMLApp.h>

#include <stdint.h>

extern DotApp* Dot_DotApp;
extern SFMLApp* Dot_SFMLApp;

int32_t main (int32_t argc, char** argv);

void Main_Setup ();
void Main_Loop ();
void Main_Quit ();

void Main_Load ();

void Main_ProcessEvts ();
void Main_Update ();
void Main_Render ();

#endif