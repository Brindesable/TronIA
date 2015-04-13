#ifndef CONST_H
#define CONST_H

#define WIDTH 30
#define HEIGHT 20

struct Player
{
    int n;
    int x;
    int y;
    int cases;
    bool enferme;

    Player(int nn = 0, int nx = 0, int ny = 0) : n(nn), x(nx), y(ny), cases(0), enferme(false)
    {}
};

enum Direction
{
    TOP, BOTTOM, LEFT, RIGHT
};

struct Pos
{
    int x;
    int y;

    Pos(int nx, int ny) : x(nx), y(ny)
    {}
};

#endif // CONST_H
