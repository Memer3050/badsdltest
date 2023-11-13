#pragma once

#include "../../include/SDL.h"

class draw2d
{
private:
    SDL_Renderer*       m_renderer;
    SDL_Window*          m_window;   
public:
    void setPrivateRenderer(SDL_Renderer* renderer);
    void setPrivateWindow(SDL_Window* window);

    void drawLine(int x1, int y1, int x2, int y2, int colorr, int colorg, int colorb, int colora);

    /*
        #####
            ##########
                      ########  Needs x1, y1 for 1 point, same for other
    */

    void drawSquare(int x, int y, int w, int h, int colorr, int colorg, int colorb, int colora);
    // void drawWireQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int colorr, int colorg, int colorb, int colora);

    /*
        ##############      x1, y1, | x2, y2 
        #            #      ------------------
        ##############      x3, y3, |  x4, y4
    */

    void drawWireTri(int x1, int y1, int x2, int y2, int x3, int y3, int colorr, int colorg, int colorb, int colora);

    /*
                ##            x1, y1
               #  #         ----------
              ######     x2, y2 | x3, y3
    */

    void drawQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int colorr, int colorg, int colorb, int colora);

};
