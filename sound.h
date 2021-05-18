#ifndef SOUND_H
#define SOUND_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_mixer.h>

using namespace std;

void init_sound();
void close_sound();
void play_sound(int v);
void pause_resume_music(SDL_Event e);


#endif
