#include "../../include/SDL.h"
#include "draw2d.h"
#include <Windows.h>

void draw2d::setPrivateRenderer(SDL_Renderer* renderer) {
    m_renderer = renderer;
}

void draw2d::setPrivateWindow(SDL_Window* window) {
    m_window = window;
}

void draw2d::drawLine(int x1, int y1, int x2, int y2, int colorr, int colorg, int colorb, int colora) {
    SDL_SetRenderDrawColor(m_renderer, colorr, colorg, colorb, colora);
    SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);

    SDL_RenderPresent(m_renderer);
    return;
};

/* This causes main thread to crash. Too bad!*/
void draw2d::drawWireTri(int x1, int y1, int x2, int y2, int x3, int y3, int colorr, int colorg, int colorb, int colora) {
    SDL_Point* point;
    point[0].x = x1;
    point[0].y = y1;
    point[1].x = x2;
    point[1].y = y2;
    point[2].x = x3;
    point[2].y = y3;

    SDL_SetRenderDrawColor(m_renderer, colorr, colorg, colorb, colora);
    SDL_RenderDrawLines(m_renderer, point, 4);

    SDL_RenderPresent(m_renderer);
    return;
}

void draw2d::drawSquare(int x, int y, int w, int h, int colorr, int colorg, int colorb, int colora) {
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;

    SDL_SetRenderDrawColor(m_renderer, colorr, colorg, colorb, colora);
    SDL_RenderDrawRect(m_renderer, &r);

    SDL_RenderPresent(m_renderer);
    return;
}

void draw2d::drawQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int colorr, int colorg, int colorb, int colora) {
    SDL_SetRenderDrawColor(m_renderer, colorr, colorg, colorb, colora);
    
    SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(m_renderer, x2, y2, x3, y3);
    SDL_RenderDrawLine(m_renderer, x3, y3, x4, y4);
    SDL_RenderDrawLine(m_renderer, x4, y4, x1, y1);

    SDL_RenderPresent(m_renderer);
    return;
}