#include <iostream>
#include <regex>
using namespace std;

int main() {
    string hour = "03:09:56";
    if(regex_match (hour, regex("([0-1][0-9]|2[0-3]):[0-5][0-9](:[0-5][0-9])?")))
        cout << "Znaleziono!" <<endl;
    else
        cout << "Nie znaleziono!"<<endl;
    return 0;
}
