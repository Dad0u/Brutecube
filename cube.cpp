#include "cube.h"
#include "debug.h"
#include <string>
#include <iostream>

using namespace std;
void Cube::move(int face, int rows)
{
}

int Cube::getx()
{return m_x;}

int Cube::gety()
{return m_y;}

int Cube::getz()
{return m_z;}

void Cube::reset()
{
  int i = 0;
	debug(3, "Réinitialisation du cube (Taille:  " + to_string(tab.size()) + ")");
  while(i < m_x*m_y)
  {
  	tab[i] = U;
  	tab[tab.size()-i-1] = D;
  	i++;
  }
  while(i < m_y*(m_x+m_z))
  {
  	tab[i] = L;
  	tab[m_x*m_y+m_x*m_z+m_y*m_z+i] = R;
  	i++;
  }
  while(i < m_x*m_y+m_x*m_z+m_y*m_z)
  {
  	tab[i] = F;
  	tab[m_x*m_y+m_x*m_z+m_y*m_z+i] = B;
  	i++;
  }
  
}

Cube::Cube(int x,int y,int z):m_x(x),m_y(y),m_z(z), tab(2*(m_x*m_y+m_x*m_z+m_y*m_z))
{
	debug(3, "Création d'un cube de taille " + to_string(m_x) + " x " + to_string(m_y) + " x " + to_string(m_z));
	this->reset();
}

