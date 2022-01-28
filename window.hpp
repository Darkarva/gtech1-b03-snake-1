#include <SDL2/SDL.h>

#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window{
    public:

        Window();
        ~Window();

        void ExitWithError(const char *message);
        void InitWin();
        void DestroyWin();
        SDL_Renderer GetRenderer(void);

    private: 
        SDL_Window *playground;
        SDL_Renderer *pgRenderer;
        
};

#endif