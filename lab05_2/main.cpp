#include <iostream>
#include <set>
using namespace std;

template<typename collectS>
void show(set <collectS> s)
{
    auto it = s.begin();
    while(it != s.end())
    {
        cout << *it<<" ";
        it++;
    }

    cout<<endl;
}
template<typename collect>
void alterXOR(set<collect> setA, set<collect> setB)
{
    set<collect> sDifferAB, sDifferBA, sUnionAB;
    set_difference(setA.begin(),setA.end(),setB.begin(),setB.end(),
                   insert_iterator(sDifferAB,sDifferAB.begin()));
    set_difference(setB.begin(),setB.end(),setA.begin(),setA.end(),
                   insert_iterator(sDifferBA,sDifferBA.begin()));
    set_union(sDifferAB.begin(),sDifferAB.end(),sDifferBA.begin(),sDifferBA.end(),
              insert_iterator(sUnionAB,sUnionAB.begin()));
    show(sUnionAB);
}

int main() {
    set<int> s1={1,2,3,7};
    set<int> s2={-2,4,1,7,6};
    alterXOR(s1,s2);
    return 0;
}
