//
// Created by ASUS on 14.12.2022.
//

#ifndef LAB09_2_GAME_H
#define LAB09_2_GAME_H

#include <iostream>
using namespace std;

class Game {
    int points;
    int numOfTry;
    int lastTry;

public:
    Game();
    bool readValue();
    bool checkResult();
    void newLastVal();
    void win();
    void lost();
    void rmvWrongValFromCin();
};


#endif//LAB09_2_GAME_H
