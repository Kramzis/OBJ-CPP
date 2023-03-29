//
// Created by ASUS on 15.11.2022.
//

#include "Dictionary.h"
#include <iostream>
#include <vector>

using namespace std;

Dictionary::Dictionary() {
}

void Dictionary::addWordTranslation(string newWord, string WordTranslation) {
    if(checkIfWordExist(newWord) == 0)
    {
        words.insert(pair<string,string> (newWord, WordTranslation));
    }
    else
    {
        cout << "Podane slowo juz istnieje!" <<endl;
    }

}

void Dictionary::delWordTranslation(string key) {
    if(checkIfWordExist(key) == 1)
    {
        words.erase(key);
        cout << "Slowo zostalo pomyslnie usuniete ze slownika!" << endl << endl;
    }
    else
        cout << "Podane slowo nie istnieje!" << endl;
}

void Dictionary::showDictionary() {
    cout << "Zawartosc slownika: " << endl;
    for(auto i: words)
    {
        cout << "Slowo: " << i.first << endl <<  "Tlumaczenie: "<< i.second << endl << endl;
    }
}

void Dictionary::showTransForWord(string word) {
    if(checkIfWordExist(word) == 1)
    {
        string tempTransl = words.find(word)->second;
        cout << "Zadane tlumaczenie: " << tempTransl << endl;
    }
    else
        cout << "Podane slowo nie istnieje!" << endl ;
}

void Dictionary::showFromZToA() {
    vector<string> wiktor;
    for(auto i: words)
    {
        wiktor.push_back(i.second);
    }
    sort(wiktor.begin(), wiktor.end(), less<string>());
    for(auto j: wiktor)
    {
        map<string, string>::iterator it = searchByValue(words, j);
        if(it != words.end())
            cout<<"Slowo: "<< it->first << endl << "Tlumaczenie: " << it->second << endl << endl;
        else
            cout<<"Brak elementu!" << endl;
    }
}

bool Dictionary::checkIfWordExist(string newWord) {
    if(words.count(newWord) == 1)
    {
        return true;
    }
    else
        return false;
}

map<string, string>::iterator Dictionary::searchByValue(map<string, string> &m, string val) {
    {
        map<string, string>::iterator it;
        for(it = m.begin(); it != m.end(); it++)
            if(it->second == val)
                break;
        return it;
    }
}
