#include "debug.h"
#include <iostream>
#include <string>
using namespace std;

void debug(int lvl, string msg)
{
    if(DEBUG >= lvl)
        {cout << msg << endl;}
}
