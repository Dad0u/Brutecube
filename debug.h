#ifndef DEBUG
#define DEBUG 2
#include "defalgs.h"
#include <string>
#include <vector>
#include <iostream>

void checkalg(std::vector<int> alg, bool disp = false);
template <unsigned int lvl> void debug(std::string msg)
{
  if(DEBUG >= lvl)
    {std::cout << msg << std::endl;}
}
#endif
