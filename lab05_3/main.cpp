#include <iostream>
#include <map>
using namespace std;

char difference(string text1, string text2)
{
    map<bool, char> checkChar;
    bool check;
    for(auto s1: text2)
    {
        check = false;
        for(auto s2: text1)
        {
            if(s1 == s2)
            {
                check = true;
                break;
            }
        }
        checkChar.insert(pair<bool,char>(check,s1));
    }
    return checkChar[0];
}

int main() {
    string s1 = "abcdef";
    string s2 = "bdagcfe";
    char text = difference(s1,s2);
    cout << "Dodatkowym znakiem w ciagu jest: " << text <<endl;
    return 0;
}
