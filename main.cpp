#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "window.hpp"
#define FPS_LIMIT 250

void SDL_LimitFPS(unsigned int limit);

int main(int argc, char *argv[])
{
    unsigned int frame_limit = 0;
    frame_limit = SDL_GetTicks() + FPS_LIMIT;

    //Objects creation//
    Window snakeWindow;

    //Window Initialization//
    snakeWindow.InitWin();

    SDL_bool program_launched = SDL_TRUE;

    while(program_launched){

        const Uint8* keystates = SDL_GetKeyboardState(0);
        SDL_Event event;

        while(SDL_PollEvent(&event)){
            switch(event.type){

                case  SDL_KEYDOWN:
                    switch(event.key.keysym.sym){

                        case SDLK_ESCAPE:
                            program_launched = SDL_FALSE;
                            break;

                        default:
                            continue;

                    }
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }

        SDL_LimitFPS(frame_limit);
        frame_limit = SDL_GetTicks() + FPS_LIMIT;

    }

    snakeWindow.DestroyWin();
}

void SDL_LimitFPS(unsigned int limit){
    unsigned int ticks = SDL_GetTicks();

    if(limit < ticks){
        return;
    }
    else if(limit > ticks + FPS_LIMIT){
        SDL_Delay(FPS_LIMIT);
    }
    else{
        SDL_Delay(limit - ticks);
    }
}