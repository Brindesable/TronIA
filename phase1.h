#ifndef PHASE1_H
#define PHASE1_H

#include <vector>
#include "const.h"

int getCaseOwner(int val);
void verifieCaseEnferme(bool & ferme, bool & trouve, int & val, int nPlayer);
bool estEnferme(Player & player, int ** map);
void verifieCaseTerritoire(bool & resteCases, Player & player, int & val, int & plusProche);
int compterTerritoire(std::vector<Player> & players, int ** map);


#endif // PHASE1_H
