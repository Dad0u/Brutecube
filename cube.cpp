#include "cube.h"
#include "debug.h"
#include <string>
#include <iostream>

using namespace std;
void Cube::U(int rows)
{
}
void Cube::L(int rows)
{
}
void Cube::F(int rows)
{
}
void Cube::R(int rows)
{
}
void Cube::B(int rows)
{
}
void Cube::D(int rows)
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


Cube::Cube(int x,int y,int z):m_x(x),m_y(y),m_z(z), tab(2*(m_x*m_y+m_x*m_z+m_y*m_z))
{
}

