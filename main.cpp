#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "const.h"
#include "test.h"

using namespace std;


int main()
{
    //cout << "Pile test 1 : " << (pileTest1() ? "OK" : "KO") << endl;
    cout << "Fermeture test 1 : " << (fermetureTest1() ? "OK" : "KO") << endl;
    //cout << "Fermeture test 2 : " << (fermetureTest2() ? "OK" : "KO") << endl;
    cout << "Territoire test 1 : " << (territoireTest1() ? "OK" : "KO") << endl;


    return 0;
}
