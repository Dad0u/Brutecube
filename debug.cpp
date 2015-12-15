#include "debug.h"
#include <iostream>
#include <string>
using namespace std;

void debug(int lvl, string msg)
{
    if(DEBUG >= lvl)
        {cout << msg << endl;}
}

void checkalg(std::vector<int> alg, bool disp)
{
  vector<int> tab(alg.size(),0);
  bool ok = true;
  for(int i = 0 ; i < alg.size() ; i++)
  {
    if(tab[alg[i]] == 0)
    {
      tab[alg[i]] = 1;
      if(disp)
      {cout << to_string(alg[i]) << " ";}
    }
    else
  {
    if(disp)
    {cout << "((" << to_string(alg[i]) << ")) ";}
    ok = false;
  }
    
  }
  if(disp)
  {cout << endl;}
  if(ok)
  {cout << "OK!" << endl;}
  else
  {cout << "/!\\ Algo incorrect !" << endl;}
  

}
