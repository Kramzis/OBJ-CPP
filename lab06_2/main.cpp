#include <iostream>
#include "Contact.h"
#include "Contacts.h"
using namespace std;

int main() {
    Contacts kontakty;
    kontakty.addContact("Karolina", "Kowal", 21, "123456789", "Nadbystrzycka");
    kontakty.addContact("Krzysztof", "Kowalski", 19, "456789432", "Muzyczna");
    kontakty.addContact("Alicja", "Plis", 18, "456789431", "Muzyczna");
    kontakty.addContact("Urszula", "Krach", 20, "456783431", "Muzyczna");
    kontakty.showContent();
    //kontakty.delContact("456789432");
    kontakty.searchByStreet("Muzyczna");
    kontakty.searchByAge(18,22);
    kontakty.searchByPhone("123456789");
    cout << kontakty.HowManyOver18()<< endl;
    cout << kontakty.HowManyUniqueSurnames()<<endl;
    kontakty.changeStreet("Muzyczna", "Lipowa");
    kontakty.showContent();
    return 0;
}
