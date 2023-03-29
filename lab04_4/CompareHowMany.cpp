//
// Created by ASUS on 08.11.2022.
//

#include "CompareHowMany.h"
bool CompareHowMany::operator()(int a, int b) {
    int howManyA = 0;
    int howManyB = 0;

    while(a > 0)
    {
        howManyA += 1;
        a = a/10;
    }

    while(b > 0)
    {
        howManyB += 1;
        b = b/10;
    }

    return(howManyA > howManyB);
}
