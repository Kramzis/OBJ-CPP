//
// Created by ASUS on 08.11.2022.
//

#include "CompareSum.h"
bool CompareSum::operator()(int a, int b) {
    int sumA = 0;
    int sumB = 0;

    while(a > 0)
    {
        sumA += a%10;
        a = a/10;
    }

    while(b > 0)
    {
        sumB += b%10;
        b = b/10;
    }

    return (sumB > sumA);

}
