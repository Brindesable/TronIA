#include <fstream>
#include <iostream>
using namespace std;

#include "util.h"
#include "const.h"


int ** copyMap(int ** map)
{
    int ** newMap;
    newMap = new int*[HEIGHT];
    for(int i = 0; i < HEIGHT; i++)
    {
        newMap[i] = new int[WIDTH];
        for(int j = 0; j < WIDTH; j++)
        {
            newMap[i][j] = map[i][j];
        }
    }

    return newMap;
}

void deleteMap(int ** map)
{
    for(int i = 0; i < HEIGHT; i++)
    {
        delete[] map[i];
    }
    delete[] map;
}

void findPlayer(Player & player, int nPlayer, int ** map)
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            if(map[i][j] == -nPlayer)
            {
                player.x = j;
                player.y = i;
            }
        }
    }
}

void afficheMap(int ** map)
{
    ofstream ofs("map.csv");
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            cout << map[i][j] << " ";
            ofs << map[i][j] << " ";
        }
        cout << endl;
        ofs << endl;
    }
    cout << endl;
}

void enfilerCase(int x, int y, Case* & fileCase)
{
    Case * newCase = new Case(x, y, fileCase);
    fileCase = newCase;
}

bool defilerCase(int & x, int & y, Case * & fileCase)
{
    if(fileCase != NULL)
    {
        //ici derniere case
        if(fileCase->nextCase == NULL)
        {
            x = fileCase->x;
            y = fileCase->y;
            delete fileCase;
            fileCase = NULL;
        }
        //ici avant derniere case
        else
        {
            Case * avDerniereCase = fileCase;
            while(avDerniereCase->nextCase->nextCase != NULL)
            {
                avDerniereCase = avDerniereCase->nextCase;
            }
            x = avDerniereCase->nextCase->x;
            y = avDerniereCase->nextCase->y;

            delete avDerniereCase->nextCase;
            avDerniereCase->nextCase = NULL;
        }
    }
    else
    {
        return false;
    }


    return true;
}
