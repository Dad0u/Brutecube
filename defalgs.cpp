#include "defalgs.h"
#include "debug.h"
#include <string>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> genU(int x,int y,int z)
{
  int len = 2*(x*y+x*z+y*z);
  int i,j;
  vector<vector<int>> res;

  for(int row = 1; row <= z / 2; row++)
  {
    vector<int> algo;


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
          if(j < row)
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
        if(j < row)
        {
          algo.push_back(algo.size()-3*z*x);
        }
        else
        {algo.push_back(algo.size());}
      }
    }
    while(algo.size() < len)      // Finir de compléter l'algo
    {algo.push_back(algo.size());}
    cout << "U:" << endl;
    for(i = 0; i < algo.size();i++) //Afficher pour la debug
    {cout << to_string(algo[i])+" " ;}
    cout << endl;
    res.push_back(algo);        // Ajout de l'algo au vecteur
     
  }



  else          // Si x != y: demi-tour
  {
    for(i = 0; i < x*y; i++)    //Inversion de la face elle même
    {
      algo.push_back(x*y - i - 1);
    }
    for(i = 0; i < z*y; i++)    // Déplacement de la couronne, face L
    {
      if(i / y < row)
      {algo.push_back(i+len/2);}
      else {algo.push_back(i+x*y);}
    }
    for(i = 0; i < z*x; i++)    // Déplacement de la couronne, face F
    {
      if(i / x < row)
      {algo.push_back(i+len/2+y*z);}
      else {algo.push_back(i+(x+z)*y);}
    }
    for(i = 0; i < z*y; i++)    // Déplacement de la couronne, face R
    {
      if(i / y < row)
      {algo.push_back(i+x*y);}
      else {algo.push_back(i+len/2);}
    }
    for(i = 0; i < z*x; i++)    // Déplacement de la couronne, face B
    {
      if(i / x < row)
      {algo.push_back(i+y*(x+z));}
      else {algo.push_back(i+len/2+y*z);}
    }

    while(algo.size() < len)      // Finir de compléter l'algo
    {algo.push_back(algo.size());}
    
    cout << "U2:" << endl;
    for(i = 0; i < algo.size();i++) //Afficher pour la debug
    {cout << to_string(algo[i])+" " ;}
    cout << endl;

    res.push_back(algo);        // Ajout de l'algo au vecteur
  }
}

  return res;
}



vector<vector<int>> genL(int x,int y,int z)
{
int len = 2*(x*y+x*z+y*z);
  int i,j;
  vector<vector<int>> res;

  for(int row = 1; row <= z / 2; row++)
  {
    vector<int> algo;


    if(z == y) //Cas d'un mouvement d'1/4 de tour
    {


    for(j = 0; j < y ; j++)     // Déplacement de la première face
      {
        for(i = 0; i < x; i++)
        {
          if(i < row)
          {
            algo.push_back(len-x*y-1-i-x*j);
          }
          else
          {algo.push_back(algo.size());}
        }
      }


      for(i = 0; i < y; i++)      //Déplacement de la face L elle même
      {
        for(j = 0; j < y; j++)  //Rappel: y==z
        {
          algo.push_back(x*y+i+y*(y-j-1));
        }
      }

    for(j = 0; j < z ; j++)   //Déplacement de F
    {
      for(i = 0; i < x; i++)
      {
        if(i < row)
        {
          algo.push_back(algo.size()-y*(x+z));
        }
        else
        {algo.push_back(algo.size());}
      }
    }
    for(i = 0; i < y*z; i++)    //Remplissage de R (ne bouge pas)
      {
        algo.push_back(algo.size());
      }

    for(j = 0; j < z ; j++)   //Déplacement de B
    {
      for(i = 0; i < x; i++)
      {
        if(x-i-1 < row)
        {
          algo.push_back(len-1-i-x*j);
        }
        else
        {algo.push_back(algo.size());}
      }
    }
      
    for(j = 0; j < y ; j++)   //Déplacement de F
    {
      for(i = 0; i < x; i++)
      {
        if(i < row)
        {
          algo.push_back(algo.size()-len/2);
        }
        else
        {algo.push_back(algo.size());}
      }
    }

    while(algo.size() < len)      // Finir de compléter l'algo
    {algo.push_back(algo.size());}
    cout << "L:" << endl;
    for(i = 0; i < algo.size();i++) //Afficher pour la debug
    {cout << to_string(algo[i])+" " ;}
    cout << endl;
    res.push_back(algo);        // Ajout de l'algo au vecteur
     
  }



  else          // Si x != y: demi-tour
  {
    for(i = 0; i < x*y; i++)    //Inversion de la face elle même
    {
      algo.push_back(x*y - i - 1);
    }
    for(i = 0; i < z*y; i++)    // Déplacement de la couronne, face L
    {
      if(i / y < row)
      {algo.push_back(i+len/2);}
      else {algo.push_back(i+x*y);}
    }
    for(i = 0; i < z*x; i++)    // Déplacement de la couronne, face F
    {
      if(i / x < row)
      {algo.push_back(i+len/2+y*z);}
      else {algo.push_back(i+(x+z)*y);}
    }
    for(i = 0; i < z*y; i++)    // Déplacement de la couronne, face R
    {
      if(i / y < row)
      {algo.push_back(i+x*y);}
      else {algo.push_back(i+len/2);}
    }
    for(i = 0; i < z*x; i++)    // Déplacement de la couronne, face B
    {
      if(i / x < row)
      {algo.push_back(i+y*(x+z));}
      else {algo.push_back(i+len/2+y*z);}
    }

    while(algo.size() < len)      // Finir de compléter l'algo
    {algo.push_back(algo.size());}
    
    cout << "U2:" << endl;
    for(i = 0; i < algo.size();i++) //Afficher pour la debug
    {cout << to_string(algo[i])+" " ;}
    cout << endl;

    res.push_back(algo);        // Ajout de l'algo au vecteur
  }
}

  return res;
}
