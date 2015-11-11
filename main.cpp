#include <iostream>
#include <SDL/SDL.h>
#include "debug.h"
#include "cube.h"

using namespace std;

int main(int argc, char *argv[])
{
    int x = 3, y = 3, z = 4;
    bool continuer = true;
    SDL_Event event;
    SDL_Surface *screen = NULL, *rectangle = NULL;
    screen = SDL_SetVideoMode(2*(y+x)*(PIX+BORDURE) - BORDURE, (2*y+z)*(PIX+BORDURE) - BORDURE, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Rubik", NULL);
    Cube cube(x,y,z);
    //cube.render(screen);
    cube.move(cube.u());
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
        }
    }
return 0;
}
