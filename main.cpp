#include <iostream>
#include <SDL/SDL.h>
#include "debug.h"
#include "cube.h"

using namespace std;

int main(int argc, char *argv[])
{
    int x = 3, y = 4,z = 5;
    bool continuer = true;
    SDL_Event event;
    SDL_Surface *screen = NULL, *rectangle = NULL;
    Uint8 *keystates = SDL_GetKeyState(NULL);
    screen = SDL_SetVideoMode(2*(y+x)*(PIX+BORDURE) - BORDURE, (2*y+z)*(PIX+BORDURE) - BORDURE, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Rubik", NULL);
    Cube cube(x,y,z);
    cube.render(screen);

    
    debug(2, "Entrée dans la boucle principale...");
    while(continuer)
    {
    SDL_WaitEvent(&event);
    debug(3, "Event détecté: "+to_string(event.type));
      switch(event.type)
        {
            case SDL_QUIT:
                debug(2, "Quit event détecté, fermeture.");
                continuer = false;
            case SDL_KEYDOWN:
              keystates = SDL_GetKeyState(NULL);
		          switch(event.key.keysym.sym)
              {
              case SDLK_u:
                if (SDL_GetKeyState(NULL)[SDLK_LSHIFT] == 0)
                {cube.move(cube.u(1));}
                else
                {cube.umove(cube.u(1));}
                cube.render(screen);
              }
        }
    }
return 0;
}
