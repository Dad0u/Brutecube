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

void Cube::setx(int i)
{
  if(i>0 && i<TAILLE_MAX)
  {
	m_x = i;
	debug(3, "Changing x value to " + to_string(i));
	tab.resize(2*(m_x*m_y+m_x*m_z+m_y*m_z));
	debug(2, "Resizing vector to " + to_string(tab.size()));
  }
}

void Cube::sety(int i)
{
  if(i>0 && i<TAILLE_MAX)
  {
	m_y = i;
	debug(3, "Changing y value to " + to_string(i));
	tab.resize(2*(m_x*m_y+m_x*m_z+m_y*m_z));
	debug(2, "Resizing vector to " + to_string(tab.size()));
  }
}

void Cube::setz(int i)
{
  if(i>0 && i<TAILLE_MAX)
  {
	m_z = i;
	debug(3, "Changing z value to " + to_string(i));
	tab.resize(2*(m_x*m_y+m_x*m_z+m_y*m_z));
	debug(2, "Resizing vector to " + to_string(tab.size()));
  }
}

void Cube::reset()
{
  int i = 0;
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
}

