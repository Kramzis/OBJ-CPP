#include <iostream>
#include <regex>
using namespace std;

int main() {
    //zadanie nr 1
    string example = "-10.0";
    if(regex_match (example, regex("(\\+|-)[1-9][0-9]*\\.[0-9]+")))
        cout << "Znaleziono liczbe zmiennoprzecinkowa ze znakiem!" <<endl;
    else
        cout << "Nie znaleziono liczby zmiennoprzecinkowej ze znakiem"<<endl;

    //zadanie nr 2
    string hour = "03:09:56";
    if(regex_match (hour, regex("([0-1][0-9]|2[0-3]):[0-5][0-9](:[0-5][0-9])?")))
        cout << "Znaleziono!" <<endl;
    else
        cout << "Nie znaleziono!"<<endl;

    //zadanie nr 3
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
