#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

#include "const.h"
#include "util.h"
#include "test.h"
#include "phase1.h"

bool readMap(int ** map, string file)
{
    std::ifstream ifs (file);
    int i = 0;

    while(ifs)
    {
        string line;
        getline(ifs, line);
        stringstream sline(line);
        if(ifs)
        {
            int nb;
            int j = 0;
            while(sline >> nb)
            {
                map[i][j] = nb;
                j++;
            }
        }
        i++;
    }
}

bool pileTest1()
{
    Case * file = NULL;
    enfilerCase(1, 2, file);
    enfilerCase(3, 4, file);
    enfilerCase(5, 6, file);

    int x = 0, y = 0;

    while(defilerCase(x, y, file))
    {
        cout << x << ":" << y << endl;
    }

    return true;
}

bool fermetureTest1()
{
    int ** map;
    map = new int*[HEIGHT];
    for(int i = 0; i < HEIGHT; i++)
    {   map[i] = new int[WIDTH];
    }

    string file("tests/enferme/test1.csv");
    readMap(map, file);

    Player player(2);
    findPlayer(player, player.n, map);

    return (estEnferme(player, map) && player.cases == 55);
}

bool fermetureTest2()
{
    int ** map;
    map = new int*[HEIGHT];
    for(int i = 0; i < HEIGHT; i++)
    {   map[i] = new int[WIDTH];
    }

    string file("tests/enferme/test2.csv");
    readMap(map, file);

    Player player(2);
    findPlayer(player, player.n, map);

    return !estEnferme(player, map);
}

bool territoireTest1()
{
    int ** map;
    map = new int*[HEIGHT];
    for(int i = 0; i < HEIGHT; i++)
    {   map[i] = new int[WIDTH];
    }

    string file("tests/territoire/test1.csv");
    readMap(map, file);

    Player player1(1), player2(2), player3(3), player4(4);
    vector<Player> players;
    findPlayer(player1, player1.n, map);
    findPlayer(player2, player2.n, map);
    findPlayer(player3, player3.n, map);
    findPlayer(player4, player4.n, map);

    players.push_back(player1);
    players.push_back(player2);
    players.push_back(player3);
    players.push_back(player4);

    cout << "Plus proche " << compterTerritoire(players, map) << endl;

    return true;
}
