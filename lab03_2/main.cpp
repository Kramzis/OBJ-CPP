#include <iostream>
using namespace std;

template<typename tab>
tab FindMin(tab * arr, int size)
{ tab mini = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(mini > arr[i]){
            mini = arr[i];
        }
    }
    return mini;
}

int main() {
    int tabl[] = {2,5,6,1};
    cout << FindMin<int>(tabl, 4);
    return 0;
}
