#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

int main() {
    cout << "Losuje dodatnia liczbe calkowita... " <<endl;
    srand(time(NULL));
    int size = rand();
    cout << "Wylosowano: "<< size;
    list<int> myList;
    while(myList.size() != size)
    {
        int randomik = rand()%201-100;
        if(randomik >=0){
            myList.push_front(randomik);
        }
        else
        {
            myList.push_back(randomik);
        }
    }
    for(auto i: myList)
    {
        cout<<i<<endl;
    }

    return 0;
}
