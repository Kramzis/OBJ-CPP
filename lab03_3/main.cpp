#include <iostream>
#include "Array.h"
using namespace std;

int main() {
    /*/Array<int> tab(4);
    tab.addEl(3);
    tab.addEl(2);
    tab.addEl(6);
    tab.addEl(8);
    tab.show();
    cout << endl;
    tab.sort();
    cout << endl;
    tab.show();
    cout << endl;
    cout << tab.findMax();
    cout << endl;
    cout << tab.returnEl(2);*/
    Array<string> tabS(4);
    tabS.addEl("Zaawansowane");
    tabS.addEl("programowanie");
    tabS.addEl("obiektowe");
    tabS.addEl("C++");
    tabS.show();
    cout << endl;
    tabS.sort();
    tabS.show();
    cout << endl;
    cout << tabS.findMax();
    return 0;
}
