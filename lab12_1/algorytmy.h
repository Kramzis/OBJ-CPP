//
// Created by ASUS on 21.12.2022.
//

#ifndef LAB12_1_ALGORYTMY_H
#define LAB12_1_ALGORYTMY_H

#include <vector>
#include <iostream>

using namespace std;

class Algorytmy
{
    vector<float> wektor;
    int n;
public:
    Algorytmy();
    Algorytmy(int newN);
    void show();
    float average();
    int countPositives();
    void delNegatives();
    void sortPosNeg();
    void neg();
    int countIfSmaller(float nb);
    const vector<float> &getWektor() const;
};


#endif//LAB12_1_ALGORYTMY_H
