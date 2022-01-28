#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.hpp"
#include "window.hpp"

Snake::Snake(){
    
}

Snake::~Snake(){

}

void Snake::move(int direction){

    const Uint8* keystates = SDL_GetKeyboardState(0);


    // Player input.
    if (keystates[SDL_SCANCODE_UP]){
        direction = 0;
    }

    if (keystates[SDL_SCANCODE_DOWN]){
        direction = 1;
    }

    if (keystates[SDL_SCANCODE_LEFT]){
        direction = 2;
    }

    if (keystates[SDL_SCANCODE_RIGHT]){
        direction = 3;
    }

    // Head Direction.

    if (direction == 0){
        posY -= 40;
        if ( posY <= 0 )
            posY = 0;
    }
    if (direction == 1){
        posY += 40;
        if (posY >= 600 - 40)
            posY = 600 - 40;
    }
    if (direction == 2){
        posX -= 40;
        if (posX <= 0)
            posX = 0;
    }
    if (direction == 3){
        posX += 40;
        if (posX >= 800 - 40)
            posX = 800 - 40;
    }
}

void Snake::print(){

    SDL_RenderClear(pgRenderer);

    if(SDL_SetRenderDrawColor(pgRenderer, 144, 28, 68, 255) != 0){
        Window::ExitWithError("Impossible de changer la couleur pour le rendu");
    }

    SDL_Rect rectangle;
    rectangle.x = posX;
    rectangle.y = posY;
    rectangle.w = HEAD_SIZE;
    rectangle.h = HEAD_SIZE;

    if(SDL_RenderFillRect(pgRenderer, &rectangle) != 0){
        ExitWithError("Impossible de dessiner un rectangle");
    }

    if(SDL_SetRenderDrawColor(pgRenderer, 0, 0, 0, 255) != 0){
        ExitWithError("Impossible de changer la couleur pour le rendu");
    }

    SDL_RenderPresent(pgRenderer);
}