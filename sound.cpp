#include "sound.h"

Mix_Music *music = NULL;
Mix_Chunk *gScratch = NULL;
Mix_Chunk *gHigh = NULL;
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLow = NULL;


void init_sound() {
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
    }

    music = Mix_LoadMUS( "resources/sounds/StarWars60.wav" );
    if( music == NULL )
	{
		cout << "Failed to load beat music! SDL_mixer Error: "<<  Mix_GetError() << endl;
	}

    gScratch = Mix_LoadWAV( "resources/sounds/beat.wav" );
    if( gScratch == NULL )
	{
		cout << "Failed to load beat music! SDL_mixer Error: "<<  Mix_GetError() << endl;
	}

    gHigh = Mix_LoadWAV( "resources/sounds/beat.wav" );
    if( gHigh == NULL )
	{
		cout << "Failed to load beat music! SDL_mixer Error: "<<  Mix_GetError() << endl;
	}

    gMedium = Mix_LoadWAV( "resources/sounds/beat.wav" );
    if( gMedium == NULL )
	{
		cout << "Failed to load beat music! SDL_mixer Error: "<<  Mix_GetError() << endl;
	}

    gLow = Mix_LoadWAV( "resources/sounds/beat.wav" );
    if( gLow == NULL )
	{
		cout << "Failed to load beat music! SDL_mixer Error: "<<  Mix_GetError() << endl;
	}
}

void play_sound(int v) {
    switch (v) {
        case 0:
        Mix_PlayChannel( -1, gHigh, 0 );
        break;

        case 1:
        Mix_PlayChannel( -1, gMedium, 0 );
        break;

        case 2:
        Mix_PlayChannel( -1, gLow, 0 );
        break;

        case 3:
        Mix_PlayChannel( -1, gScratch, 0 );
        break;

        case 4:
        Mix_PlayMusic(music, -1);
    }
}

void close_sound() {
    Mix_FreeChunk( gScratch );
	Mix_FreeChunk( gHigh );
	Mix_FreeChunk( gMedium );
	Mix_FreeChunk( gLow );
	gScratch = NULL;
	gHigh = NULL;
	gMedium = NULL;
	gLow = NULL;

	//Free the music
	Mix_FreeMusic( music );
	music = NULL;

    Mix_Quit();
}
