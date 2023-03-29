#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main() {
    string name, surname, age, telephone, email;
    bool ifCorrect = true;
    ofstream save("dane.txt", ios_base::app);
    cout << "Podaj imie (moze skladac sie tylko z liter alfabetu lacinskiego): " << endl;
    cin >> name;
    if(regex_match (name, regex("[A-Z][a-z]+"))){
        cout << "Poprawne imie!" << endl;
    } else {
        cout << "Niepoprawne imie!" <<endl;
        ifCorrect = false;
    }

    cout << "Podaj nazwisko (moze skladac sie tylko z liter alfabetu lacinskiego oraz myslnika przy laczonych nazwiskach): " << endl;
    cin >> surname;
    if(regex_match (surname, regex("([A-Z][a-z]+|[A-Z][a-z]+-[A-Z][a-z]+)"))){
        cout << "Poprawne nazwisko!" << endl;
    } else {
        cout << "Niepoprawne nazwisko!" <<endl;
        ifCorrect = false;
    }

    cout << "Podaj wiek (od 0 do 99): " << endl;
    cin >> age;
    if(regex_match (age, regex("[1-9][0-9]?"))){
        cout << "Poprawny wiek!" << endl;
    } else {
        cout << "Niepoprawny wiek!" <<endl;
        ifCorrect = false;
    }

    cout << "Podaj numer tel (9 cyfr, nie moze zaczynac sie zerem): " << endl;
    cin >> telephone;
    if(regex_match (telephone, regex("[1-9]{1}[0-9]{8}"))){
        cout << "Poprawny nr telefonu!" << endl;
    } else{
        cout << "Niepoprawny nr telefonu!" <<endl;
        ifCorrect = false;
    }

    cout << "Podaj adres email (u@x.y): " << endl;
    cin >> email;
    if(regex_match (email, regex("[A-Za-z0-9_\\-.]+@[A-Za-z0-9]+\\.[A-Za-z0-9]+"))){
        cout << "Poprawny adres email!" << endl;
    } else {
        cout << "Niepoprawny adres email!" <<endl;
        ifCorrect = false;
    }

    if(ifCorrect){
        save<<name<<";"<<surname<<";"<<age<<";"<<telephone<<";"<<email << endl;
        save.close();
    } else
        cout << "Wprowadzone dane nie byly poprawne, wiec nie zostaly zapisane!"<<endl;

    return 0;
}
