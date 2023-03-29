#include <iostream>
#include <regex>
using  namespace std;



int main() {
    string street = "Lipowa ";
    string postalCode = "24-350";
    string nrOfHouse = "32";
    string nrOfFlat = "2";

    //nazwa ulicy
    if(regex_match (street, regex("[A-Z][a-z ]+")))
        cout << "Znaleziono ulice!" <<endl;
    else
        cout << "Nie znaleziono ulicy!"<<endl;

    //kod pocztowy
    if(regex_match (postalCode, regex("[0-9]{2}-[0-9]{3}")))
        cout << "Znaleziono kod pocztowy!" <<endl;
    else
        cout << "Nie znaleziono kodu pocztowego!"<<endl;

    //numer domu
    if(regex_match (nrOfHouse, regex("([1-9][0-9]*|[1-9][0-9]*[A-Z])")))
        cout << "Znaleziono numer domu!" <<endl;
    else
        cout << "Nie znaleziono numeru domu!"<<endl;

    //numer mieszkania
    if(regex_match (nrOfFlat, regex("[1-9][0-9]*")))
        cout << "Znaleziono numer mieszkania!" <<endl;
    else
        cout << "Nie znaleziono numeru mieszkania!"<<endl;

    return 0;
}
