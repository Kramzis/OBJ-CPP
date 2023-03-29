//
// Created by ASUS on 15.11.2022.
//

#ifndef LAB05_4_DICTIONARY_H
#define LAB05_4_DICTIONARY_H
#include <iostream>
#include <map>
using namespace std;

class Dictionary {
private:
    map<string, string> words;
public:
    Dictionary();
    void addWordTranslation(string newWord, string WordTranslation);
    bool checkIfWordExist(string newWord);
    void delWordTranslation(string key);
    void showDictionary();
    void showTransForWord(string word);
    void showFromZToA();
    map<string, string>::iterator searchByValue(map<string, string>& m, string val);

};


#endif//LAB05_4_DICTIONARY_H
