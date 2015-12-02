#include "cube.h"
//#include "defalgs.h"
#include "debug.h"
#include <string>
#include <iostream>

using namespace std;

int Cube::getx()
{return m_x;}

int Cube::gety()
{return m_y;}

int Cube::getz()
{return m_z;}

void Cube::render(SDL_Surface *screen)
{
	SDL_Surface *rectangle = NULL;
  Uint32 rouge = SDL_MapRGB(screen->format, 255, 0, 0), vert = SDL_MapRGB(screen->format, 0, 255, 0), bleu = SDL_MapRGB(screen->format, 0, 0, 255), blanc = SDL_MapRGB(screen->format, 255, 255, 255), noir = SDL_MapRGB(screen->format, 0, 0, 0), jaune = SDL_MapRGB(screen->format, 255, 255, 0), orange = SDL_MapRGB(screen->format, 255, 125, 0), gris = SDL_MapRGB(screen->format, 125, 125, 125);
    Uint32 couleur[6];
    couleur[U] = blanc;
    couleur[L] = rouge;
    couleur[F] = bleu;
    couleur[R] = orange;
    couleur[B] = vert;
    couleur[D] = jaune;
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, PIX, PIX, 32, 0, 0, 0, 0);
    SDL_FillRect(rectangle, NULL, blanc);
    //SDL_Rect pos;
    
    for(int i = 0 ; i < tab.size() ; i++)
    {
      SDL_FillRect(rectangle, NULL, couleur[coul[tab[i]]]);
      SDL_BlitSurface(rectangle, NULL, screen, &pos[i]);
    }
    SDL_Flip(screen);
}



void Cube::move(std::vector<int> algo)
{
  const vector<int> old = tab;
  for(int i = 0; i < algo.size() ; i++)
  {
    tab[i] = old[algo[i]];
  }
}

void Cube::umove(std::vector<int> algo)
{
  const vector<int> old = tab;
  for(int i = 0; i < algo.size() ; i++)
  {
    tab[algo[i]] = old[i];
  }
}

vector<int> Cube::u(int i)
{return m_u[i-1];}

vector<int> Cube::l(int i)
{return m_l[i-1];}

vector<int> Cube::f(int i)
{return m_f[i-1];}

vector<int> Cube::r(int i)
{return m_r[i-1];}

vector<int> Cube::b(int i)
{return m_b[i-1];}

vector<int> Cube::d(int i)
{return m_d[i-1];}

void Cube::reset()
{
  int i = 0;
	debug(2, "Réinitialisation du cube (Taille:  " + to_string(tab.size()) + ")");
  for(i = 0; i < tab.size(); i++)
  {
    tab[i] = i;
  }
  
}

Cube::Cube(int x,int y,int z):m_x(x),m_y(y),m_z(z), tab(2*(m_x*m_y+m_x*m_z+m_y*m_z)), coul(2*(m_x*m_y+m_x*m_z+m_y*m_z)), pos(2*(m_x*m_y+m_x*m_z+m_y*m_z)), m_u(genU(x,y,z)), m_l(genL(x,y,z)), m_f(genF(x,y,z)), m_r(genR(x,y,z)), m_b(genB(x,y,z)), m_d(genD(x,y,z))
{
	debug(2, "Création d'un cube de taille " + to_string(m_x) + " x " + to_string(m_y) + " x " + to_string(m_z));
  int i = 0;
    while(i < m_x*m_y)      // Initialisation du tableau de couleurs
  {
  	coul[i] = U;
  	coul[coul.size()-i-1] = D;
  	i++;
  }
  while(i < m_y*(m_x+m_z))
  {
  	coul[i] = L;
  	coul[m_z*(m_x+m_y)+i] = R;
  	i++;
  }
  while(i < m_x*m_y+m_x*m_z+m_y*m_z)
  {
  	coul[i] = F;
  	coul[m_z*(m_x+m_y)+i] = B;
  	i++;
  }                       // -----
  //coul[51]=U;          //Pour la vérification
  //coul[5]=R;
  i = 0;
  SDL_Rect rect;          // Initialisation du tableau des positions
  while(i < m_x*m_y)          // Face U
  {
    rect.x = m_y*(PIX+BORDURE) + (i%m_x)*(PIX+BORDURE);
    rect.y = (i / m_x)*(PIX+BORDURE);
    pos[i] = rect;
    i++;
  }
  int j = 0;
  while(i < m_y*(m_x+m_z))    // Face L
  {
    rect.x = (j%m_y)*(PIX+BORDURE);
    rect.y = m_y*(PIX+BORDURE)+(j / m_y)*(PIX+BORDURE);
    pos[i] = rect;
    j++;
    i++;
  }
  j = 0;
  while(i < m_x*m_y+m_x*m_z+m_y*m_z)  //Face F
  {
  	rect.x = m_y*(PIX+BORDURE) + (j%m_x)*(PIX+BORDURE);
    rect.y = m_y*(PIX+BORDURE) + (j / m_x)*(PIX+BORDURE);
    pos[i] = rect;
    i++;
    j++;
  }
  j = 0;
  while(i < m_x*m_y+m_x*m_z+m_y*m_z + m_y*m_z)  //Face R
  {
  	rect.x = (m_y+m_x)*(PIX+BORDURE) + (j%m_y)*(PIX+BORDURE);
    rect.y = m_y*(PIX+BORDURE) + (j / m_y)*(PIX+BORDURE);
    pos[i] = rect;
    i++;
    j++;
  }
  j = 0;
  while(i < m_x*m_y+m_x*m_z+m_y*m_z + (m_x+m_y)*m_z)  //Face B
  {
  	rect.x = (2*m_y+m_x)*(PIX+BORDURE) + (j%m_x)*(PIX+BORDURE);
    rect.y = m_y*(PIX+BORDURE) + (j / m_x)*(PIX+BORDURE);
    pos[i] = rect;
    i++;
    j++;
  }
  j = 0;
  while(i < tab.size())  //Face D
  {
  	rect.x = m_y*(PIX+BORDURE) + (j%m_x)*(PIX+BORDURE);
    rect.y = (m_y+m_z)*(PIX+BORDURE) + (j / m_x)*(PIX+BORDURE);
    pos[i] = rect;
    i++;
    j++;
  }                     // --------------
  
	this->reset();
}

