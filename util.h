#ifndef UTIL_H
#define UTIL_H

#include "const.h"

struct Case
{
    int x;
    int y;
    Case * nextCase;

    Case(int nx = 0, int ny = 0, Case * next = 0) : x(nx), y(ny), nextCase(next) {}
};

int ** copyMap(int ** map);
void deleteMap(int ** map);
void findPlayer(Player & player, int nPlayer, int ** map);
void afficheMap(int ** map);

void enfilerCase(int x, int y, Case* & fileCase);
bool defilerCase(int & x, int & y, Case * & fileCase);

#endif // UTIL_H
