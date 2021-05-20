#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <unistd.h>
#include "font.h"
#include "constans.h"

void server_or_client(SDL_Renderer *renderer, char *menu, TTF_Font *font, TTF_Font *font2, SDL_Texture *image);
// void server_or_client(SDL_Renderer *renderer, char *menu, TTF_Font *font, SDL_Texture *image);
void ask_for_ip(SDL_Renderer *renderer, TTF_Font *font, char *ip, SDL_Texture *image);
void ask_for_name(SDL_Renderer *renderer, TTF_Font *font, char *name);

#endif
