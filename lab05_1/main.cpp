#include <iostream>
#include <vector>
#include <set>
using namespace std;

pair<int, int> duplicate(vector<int> wktr)
{
    int dupli = 0;
    int sum = 0;
    set<int> zbior;
    pair <set<int>::iterator, bool> check;
    for(int i: wktr)
    {
        check = zbior.insert(i);
        if(check.second)
        {
            sum += i;
        }
        else
        {
            dupli = i;
        }
    }
    pair <int, int> zwr;
    zwr.first = sum;
    zwr.second = dupli;
    return zwr;

}

int main() {
    vector<int> wiktor = {34, 5,44,78,88,90,44};
    pair<int, int> duplik;
    duplik = duplicate(wiktor);
    cout << "Suma unikatow wynosi: " << duplik.first << endl << "Duplikat stanowi: " << duplik.second;
    return 0;
}
