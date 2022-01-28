#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "window.hpp"

Window::Window(){

}

Window::~Window(){

}

void Window::ExitWithError(const char *message){
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
}

void Window::InitWin(){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        ExitWithError("SDL init failed.");
    }

    playground = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if(playground == NULL){
        ExitWithError("Window creation failed.");
    }

    pgRenderer = SDL_CreateRenderer(playground, -1, SDL_RENDERER_ACCELERATED);

     if(pgRenderer == NULL){
        ExitWithError("Window creation failed.");
    }
}

void Window::DestroyWin(){
    SDL_DestroyRenderer(pgRenderer);
    SDL_DestroyWindow(playground);
    SDL_Quit();
}