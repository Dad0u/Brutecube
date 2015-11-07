#ifndef CUBE
#define CUBE
#define TAILLE_MAX 7
#define U 0
#define L 1
#define F 2
#define R 3
#define B 4
#define D 5
#include <vector>
#include <string>

class Cube
{
    public:
    Cube(int x,int y,int z);
    void move(int face, int rows=1);
    int getx();
    int gety();
    int getz();
    void reset();

    private:
    int m_x;
    int m_y;
    int m_z;
    std::vector<int> tab;
    
};


#endif
