#include <iostream>
#include "Dictionary.h"
using namespace std;

int main() {
    Dictionary slownik;
    slownik.addWordTranslation("piesek", "najbardziej urocze stworzenie na swiecie");
    slownik.addWordTranslation("czlowiek", "organizm");
    slownik.addWordTranslation("kotek", "zwierzak");
    //slownik.showTransForWord("piesek");
    //slownik.delWordTranslation("kotek");
    //slownik.showDictionary();
    slownik.showFromZToA();
    return 0;
}
