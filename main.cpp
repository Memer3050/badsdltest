#include <iostream>
#include "include/SDL.h"
#include <windows.h>
#include "src/draw/draw2d.h"
#include <cstdint>
#include <stdlib.h>

long long framecount = 0;
int fps = 120;


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

    // FPS:
    char *p;

    if (__argc > 1) {
        long conv = strtol(__argv[1], &p, 10);
        fps = conv;
        std::cout << fps << std::endl;
    }


    SDL_Window* window = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Leviathan", 0, 30, 1920, 1080, SDL_WINDOW_VULKAN | SDL_WINDOW_FULLSCREEN);

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

    // Draw2d.drawWireTri(22, 84, 666, 273, 11, 777, 255, 0, 0, 255);
    // Draw2d.drawSquare(27, 55, 199, 444, 255,255,255,255);

    // Draw2d.drawSquare(0, 1050, 100, 1080, 255, 0, 0, 255);
    Draw2d.drawQuad(200, 300, 1500, 450, 1700, 600, 70, 800, 255,255,255,255);

    while (true)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.key.keysym.sym == SDLK_k) {
                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
            }

            if (event.type == SDL_QUIT)
            {
                Exit();
                break;
            }

            framecount++;

            Update();
            SDL_Delay(1000/fps);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
