#ifndef CUBE
#define CUBE
#define TAILLE_MAX 7
#include <vector>
#include <string>

class Cube
{
    public:
    Cube(int x,int y,int z);
    void U(int rows=1);
    void L(int rows=1);
    void F(int rows=1);
    void R(int rows=1);
    void B(int rows=1);
    void D(int rows=1);
    int getx();
    int gety();
    int getz();
    void setx(int i);
    void sety(int i);
    void setz(int i);

    private:
    int m_x;
    int m_y;
    int m_z;
    std::vector<int> tab;
    
};


#endif
