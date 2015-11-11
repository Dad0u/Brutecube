#include "defalgs.h"
#include "debug.h"
#include <string>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> genU(int x,int y,int z,int rows)
{
  int len = 2*(x*y+x*z+y*z);
  vector<int> algo;
  int i,j;
  if(x == y) //Cas d'un mouvement d'1/4 de tour
  {
    for(i = 0; i < x; i++)      //Déplacement de la face elle même
    {
      for(j = 0; j < x; j++)
      {
        algo.push_back(i+x*(x-j-1));
      }
    }
  for(int f = 0;f < 3;f++)    //Déplacement des 3 premières rangées de la couronne
  {
    for(j = 0; j < z ; j++)
    {
      for(i = 0; i < x; i++)
      {
        if(j < rows)
        {
          algo.push_back(algo.size()+z*x);
        }
        else
        {algo.push_back(algo.size());}
      }
    }
  }
  for(j = 0; j < z ; j++)   //Déplacement de la dernière couronne
  {
    for(i = 0; i < x; i++)
    {
      if(j < rows)
      {
        algo.push_back(algo.size()-3*z*x);
      }
      else
      {algo.push_back(algo.size());}
    }
  }
}
  






  while(algo.size() < len)
  {algo.push_back(algo.size());}

  for(int i = 0; i < algo.size();i++)
  {cout << to_string(algo[i])+" " ;}
  cout << endl;
  return algo;
}
