#include <iostream>
#include <vector>
#include <algorithm>
#include "CompareSum.h"
#include "CompareHowMany.h"

using namespace std;

void print(int& el)
{
    cout<<el<<" ";
}

int main() {
    vector<int> wiktor = {3478,78,7,3,197,832,3982701,89172,36,831,872319,123,567,87,54};
    /*
    for_each(wiktor.begin(), wiktor.end(),print);
    cout << endl;
    sort(wiktor.begin(),wiktor.end(),CompareSum());
    cout << endl;
    for_each(wiktor.begin(), wiktor.end(),print);
    */
    for_each(wiktor.begin(), wiktor.end(),print);
    cout << endl;
    sort(wiktor.begin(),wiktor.end(),CompareHowMany());
    cout << endl;
    for_each(wiktor.begin(), wiktor.end(),print);
    return 0;
}
