#include "phase1.h"
#include "util.h"

#include <iostream>
using namespace std;

int SELF = 1;

int getCaseOwner(int val)
{
    if(val < 0)
        return -val;
    else
        return val % 10;
}

bool estEnferme(Player & player, int ** map)
{
    int ** newMap = copyMap(map);
    Case * file = NULL;
    bool trouve = false;
    int nbCases = 0;

    findPlayer(player, player.n, map);
    enfilerCase(player.x, player.y, file);

    while(file && !trouve)
    {
        int x, y;
        defilerCase(x, y, file);

        if(y > 0)
        {
            if(newMap[y-1][x] < 0)
                trouve = true;
            else if(newMap[y-1][x] == 0)
            {
                newMap[y-1][x] = 20 + player.n;
                enfilerCase(x, y-1, file);
            }
        }
        if(y < HEIGHT - 1)
        {
            if(newMap[y+1][x] < 0)
                trouve = true;
            else if(newMap[y+1][x] == 0)
            {
                newMap[y+1][x] = 20 + player.n;
                enfilerCase(x, y+1, file);
            }
        }
        if(x > 0)
        {
            if(newMap[y][x-1] < 0)
                trouve = true;
            else if(newMap[y][x-1] == 0)
            {
                newMap[y][x-1] = 20 + player.n;
                enfilerCase(x-1, y, file);
            }
        }
        if(x < WIDTH - 1)
        {
            if(newMap[y][x+1] < 0)
                trouve = true;
            else if(newMap[y][x+1] == 0)
            {
                newMap[y][x+1] = 20 + player.n;
                enfilerCase(x+1, y, file);
            }
        }
        newMap[y][x] = 10 + player.n;
        nbCases++;
    }

    if(!trouve)
        player.cases = nbCases - 1;

    player.enferme = !trouve;
    afficheMap(newMap);
    deleteMap(newMap);

    return !trouve;
}

//renvoie le joueur le plus pres
void verifieCaseTerritoire(bool & resteCases, Player & player, int & val, int & plusProche)
{
    if(val == 0)
    {
        val = player.n + 20;
        resteCases = true;
    }
    else if(player.n == 1 && val > 10 && val < 20 && val != 11)
    {
        plusProche = val - 10;
    }
}

//renvoie le joueur le plus pres
int compterTerritoire(vector<Player> & players, int ** map)
{
    int ** newMap = copyMap(map);
    Case * file = NULL;

    for(int i = 0; i < players.size(); i++)
    {
        players.at(i).cases = 0;
        enfilerCase(players.at(i).x, players.at(i).y, file);
    }

    int plusProche = 0;

    while(file)
    {
        int x, y;
        defilerCase(x, y, file);
        int nPlayer = 0;

        nPlayer = getCaseOwner(newMap[y][x]);

        if(y > 0)
        {
            if(newMap[y-1][x] && getCaseOwner(newMap[y-1][x]) != SELF && nPlayer == SELF && !plusProche)
            {
                plusProche = getCaseOwner(newMap[y-1][x]);
            }
            else if(newMap[y-1][x] == 0)
            {
                newMap[y-1][x] = 20 + nPlayer;
                enfilerCase(x, y-1, file);
            }
        }
        if(y < HEIGHT - 1)
        {
            if(newMap[y+1][x] && getCaseOwner(newMap[y+1][x]) != SELF && nPlayer == SELF && !plusProche)
            {
                plusProche = getCaseOwner(newMap[y+1][x]);
            }
            else if(newMap[y+1][x] == 0)
            {
                newMap[y+1][x] = 20 + nPlayer;
                enfilerCase(x, y+1, file);
            }
        }
        if(x > 0)
        {
            if(newMap[y][x-1] && getCaseOwner(newMap[y][x-1]) != SELF && nPlayer == SELF && !plusProche)
            {
                plusProche = getCaseOwner(newMap[y][x-1]);
            }
            else if(newMap[y][x-1] == 0)
            {
                newMap[y][x-1] = 20 + nPlayer;
                enfilerCase(x-1, y, file);
            }
        }
        if(x < WIDTH - 1)
        {
            if(newMap[y][x+1] && getCaseOwner(newMap[y][x+1]) != SELF && nPlayer == SELF && !plusProche)
            {
                plusProche = getCaseOwner(newMap[y][x+1]);
            }
            else if(newMap[y][x+1] == 0)
            {
                newMap[y][x+1] = 20 + nPlayer;
                enfilerCase(x+1, y, file);
            }
        }
        if(newMap[y][x] > 20)
        {
            newMap[y][x] -= 10;
            players.at(nPlayer - 1).cases++;
        }
    }

    //afficheMap(newMap);
    deleteMap(newMap);

    return plusProche;
}

int evaluateScore(vector<Player> players, int nPlayer, int ** map, Direction dir)
{
    int ** newMap = copyMap(map);
    Player player;

    player = players.at(nPlayer - 1);

    switch(dir)
    {
        case TOP :
            newMap[player.y - 1][player.x] = -nPlayer;
            break;
        case BOTTOM :
            newMap[player.y + 1][player.x] = -nPlayer;
            break;
        case LEFT :
            newMap[player.y][player.x - 1] = -nPlayer;
            break;
        case RIGHT :
            newMap[player.y][player.x + 1] = -nPlayer;
            break;
    }

    compterTerritoire(players, newMap);

    int score = player.cases;

    deleteMap(newMap);

    return score;
}

Direction choisirDir(vector<Player> players, int ** map)
{
    Player player = players.at(SELF - 1);

    int maxScore = 0;
    Direction dir;

    if(map[player.y - 1][player.x] == 0)
    {
        int score = evaluateScore(players, SELF, map, TOP);
        if(score > maxScore)
        {
            maxScore = score;
            dir = TOP;
        }
    }
    if(map[player.y + 1][player.x] == 0)
    {
        int score = evaluateScore(players, SELF, map, BOTTOM);
        if(score > maxScore)
        {
            maxScore = score;
            dir = BOTTOM;
        }
    }
    if(map[player.y][player.x - 1] == 0)
    {
        int score = evaluateScore(players, SELF, map, LEFT);
        if(score > maxScore)
        {
            maxScore = score;
            dir = LEFT;
        }
    }
    if(map[player.y][player.x + 1] == 0)
    {
        int score = evaluateScore(players, SELF, map, RIGHT);
        if(score > maxScore)
        {
            maxScore = score;
            dir = RIGHT;
        }
    }

    return dir;
}
