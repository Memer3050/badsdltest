#include <iostream>
#include "include/SDL.h"
#include <windows.h>
#include "src/draw/draw2d.h"
#include <cstdint>

long long framecount = 0;

void Exit() {
    std::cout << "Broke the gameloop.\n";
}

void Start() {
    std::cout << "Main loop started.\n";
}

void Update() {
    std::cout << "Step. [" << framecount << "]\n";
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
    SDL_Window* window = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("TEST", 0, 30, 1920, 1080, SDL_WINDOW_VULKAN);

    if (window == nullptr)
    {   
        SDL_Log("Could not create a window: %s", SDL_GetError());
        return -1;
    }

    SDL_Event event;
    SDL_PollEvent(&event);


    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );

    draw2d Draw2d;

    Draw2d.setPrivateRenderer(renderer);
    Draw2d.setPrivateWindow(window);
    
    Start();

    while (true)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                Exit();
                break;
            }

            framecount++;

            Update();

        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
