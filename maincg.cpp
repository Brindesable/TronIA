#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    vector<Player> players;

    int ** map;
    map = new int*[HEIGHT];
    for(int i = 0; i < HEIGHT; i++)
    {   map[i] = new int[WIDTH];
        for(int j = 0; j < WIDTH; j++)
        {   map[i][j] = 0;
        }
    }

    // game loop
    while (1) {
        newPos.clear();
        int N; // total number of players (2 to 4).
        int P; // your player number (0 to 3).
        cin >> N >> P; cin.ignore();

        //nouvelles positions
        vector<Pos> newPos;

        //init du num player
        SELF = P + 1;

        for (int i = 0; i < N; i++)
        {
            int X0; // starting X coordinate of lightcycle (or -1)
            int Y0; // starting Y coordinate of lightcycle (or -1)
            int X1; // starting X coordinate of lightcycle (can be the same as X0 if you play before this player)
            int Y1; // starting Y coordinate of lightcycle (can be the same as Y0 if you play before this player)
            cin >> X0 >> Y0 >> X1 >> Y1; cin.ignore();
            newPos.push_back(new Pos(X1, Y1));
        }

        //on remplis la premiere fois le tab de joueurs
        if(players.empty())
        {
            for(int i =0; i < N; i++)
            {
                player = new Player(i + 1, newPos.at(i).x);
                players.push_back()
            }
        }



        cout << "LEFT" << endl; // A single line with UP, DOWN, LEFT or RIGHT

    }
}
