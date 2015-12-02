#include <iostream>
#include <SDL/SDL.h>
#include "debug.h"
#include "cube.h"

using namespace std;

int main(int argc, char *argv[])
{
    int x = 5, y = 5,z = 5;
    bool continuer = true;
    vector<int> algo;
    SDL_Event event;
    SDL_Surface *screen = NULL, *rectangle = NULL;
    Uint8 *keystates = SDL_GetKeyState(NULL);
    screen = SDL_SetVideoMode(2*(y+x)*(PIX+BORDURE) - BORDURE, (2*y+z)*(PIX+BORDURE) - BORDURE, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Rubik", NULL);
    Cube cube(x,y,z);
    cube.render(screen);

    
    debug(2, "Entrée dans la boucle principale...");
    int larg = 1;
    while(continuer)
    {
    SDL_WaitEvent(&event);
    debug(3, "Event détecté: "+to_string(event.type));
      switch(event.type)
        {

            case SDL_QUIT:
                debug(2, "Quit event détecté, fermeture.");
                continuer = false;
                break;
            case SDL_KEYDOWN:
              keystates = SDL_GetKeyState(NULL);
		          switch(event.key.keysym.sym)
              {
              case SDLK_a:
                larg = 1;
                break;
              case SDLK_q:
                larg = 2;
                break;
              case SDLK_w:
                larg = 3;
                break;
              case SDLK_u:
                if(SDL_GetKeyState(NULL)[SDLK_LSHIFT] == 0)
                {cube.move(cube.u(larg));}
                else
                {cube.umove(cube.u(larg));}
                cube.render(screen);
                break;
              case SDLK_l:
                if(SDL_GetKeyState(NULL)[SDLK_LSHIFT] == 0)
                {cube.move(cube.l(larg));}
                else
                {cube.umove(cube.l(larg));}
                cube.render(screen);
                break;
              case SDLK_f:
                if(SDL_GetKeyState(NULL)[SDLK_LSHIFT] == 0)
                {cube.move(cube.f(larg));}
                else
                {cube.umove(cube.f(larg));}
                cube.render(screen);
                break;
              case SDLK_r:
                if(SDL_GetKeyState(NULL)[SDLK_LSHIFT] == 0)
                {cube.move(cube.r(larg));}
                else
                {cube.umove(cube.r(larg));}
                cube.render(screen);
                break;
              case SDLK_b:
                if(SDL_GetKeyState(NULL)[SDLK_LSHIFT] == 0)
                {cube.move(cube.b(larg));}
                else
                {cube.umove(cube.b(larg));}
                cube.render(screen);
                break;
              case SDLK_d:
                if(SDL_GetKeyState(NULL)[SDLK_LSHIFT] == 0)
                {cube.move(cube.d(larg));}
                else
                {cube.umove(cube.d(larg));}
                cube.render(screen);
                break;
              }
            break;
        }
    }
return 0;
}
