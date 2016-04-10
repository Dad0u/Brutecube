#ifndef CUBE
#define CUBE
#define TAILLE_MAX 7
#define U 0
#define L 1
#define F 2
#define R 3
#define B 4
#define D 5
#define G 6
#define PIX 40
#define BORDURE 3
#include <vector>
#include <string>
#include <SDL/SDL.h>

class Cube
{
    public:
    Cube(int x,int y,int z);
    void move(std::vector<int>);
    void umove(std::vector<int>);
    int getx();
    int gety();
    int getz();
    std::vector<int> u(int i);
    std::vector<int> l(int i);
    std::vector<int> f(int i);
    std::vector<int> r(int i);
    std::vector<int> b(int i);
    std::vector<int> d(int i);
    void reset();
    void render(SDL_Surface *screen);
    private:
    const int m_x;
    const int m_y;
    const int m_z;
    std::vector<int> tab;
    std::vector<int> coul;
    const std::vector<std::vector<int>> m_u;
    const std::vector<std::vector<int>> m_l;
    const std::vector<std::vector<int>> m_f;
    const std::vector<std::vector<int>> m_r;
    const std::vector<std::vector<int>> m_b;
    const std::vector<std::vector<int>> m_d;
    std::vector<SDL_Rect> pos;
    
};


#endif  //ifndef CUBE
