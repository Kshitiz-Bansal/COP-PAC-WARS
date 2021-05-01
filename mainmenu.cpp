#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_ttf.h>
#include"mainmenu.h"


void server_or_client(SDL_Renderer *renderer, char *entered_char) {
    SDL_Event e;
    bool pressed = 0;
    while(!pressed) {
        if(SDL_PollEvent(&e)) {
            if(e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_c) {
                    *entered_char = 'c';
                    pressed = true;
                } else if (e.key.keysym.sym == SDLK_s) {
                    *entered_char = 's';
                    pressed = true;
                }
            }
        }
        usleep(250);
        SDL_RenderClear(renderer);

        // display menu stuff //

        SDL_RenderPresent(renderer);
    }
}

void ask_for_ip(SDL_Renderer *renderer, char *ip) {
    // string s = "";
    // for(int i=0; i<15; i++) {
    //     s += " ";
    // }
    // ip = s;
    memset(ip, ' ', 15);
    SDL_Event e;
    int pos = 0;
    bool ok = false;
    while(!ok) {
        if(SDL_PollEvent(&e)) {
            if (e.type == SDL_KEYDOWN) {
                if ((e.key.keysym.sym >= SDLK_0 && e.key.keysym.sym <= SDLK_9) || e.key.keysym.sym == SDLK_PERIOD) {
                    if (pos > 14) {
                        pos = 14;
                    }
                    ip[pos] = e.key.keysym.sym;
                    pos++;
                }
                if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    pos--;
                    if (pos < 0) {
                        pos = 0;
                    }
                    ip[pos] = ' ';
                }
                if (e.key.keysym.sym == SDLK_RETURN) {
                    ip[pos] = '0';
                    ok = true;
                }
            }
        }
        usleep(200);
        SDL_RenderClear(renderer);

        // display IP

        SDL_RenderPresent(renderer);
    }
}
