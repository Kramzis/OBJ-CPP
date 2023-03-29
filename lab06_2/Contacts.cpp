//
// Created by ASUS on 22.11.2022.
//

#include "Contacts.h"
void Contacts::addContact(string newName, string newSurname, int newAge, string newPhoneNumber, string newStreet) {
    Contact kontakt(newName, newSurname, newAge, newPhoneNumber, newStreet);
    phoneBook.insert(kontakt);
}

void Contacts::delContact(string searchedNumber) {
    auto &phone_index = phoneBook.get<3>();
    auto it = phone_index.find(searchedNumber);
    phone_index.erase(it);
}

void Contacts::searchByStreet(string chosenStreet) {
    cout<< "Osoby mieszkajace na tej samej ulicy: " << endl << endl;
    for(auto it=phoneBook.get<4>().begin(); it!=phoneBook.get<4>().end(); it++){
        if(it->street == chosenStreet){
            it->show();
        }
    }
    cout << endl;
}

void Contacts::searchByAge(int beginRange, int endRange) {
    cout<< "Osoby z wybranego przedzialu wiekowego: " << endl << endl;
    for(auto it=phoneBook.get<2>().begin(); it!=phoneBook.get<2>().end(); it++){
        if(it->age > beginRange && it->age < endRange){
            it->show();
        }
    }
    cout << endl;
}
void Contacts::searchByPhone(string pickedNumber) {
    auto &phone_index = phoneBook.get<3>();
    cout<< "Zadany kontakt: " << endl << endl;
    auto it = phone_index.find(pickedNumber);
    it->show();
    cout << endl;
}
void Contacts::changeStreet(string oldStreet, string newStreet) {
    auto &street_index = phoneBook.get<4>();
    auto it = street_index.find(oldStreet);
    while(it!=street_index.end()){
        street_index.modify(it, [oldStreet, &newStreet](Contact &a) {a.street=newStreet;});
        it = street_index.find(oldStreet);
    }
}

int Contacts::HowManyOver18() {
    int legalPeople = 0;
    cout<< "Osoby pelnoletnie: ";
    for(auto it=phoneBook.get<2>().begin(); it!=phoneBook.get<2>().end(); it++){
        if(it->age >= 18){
            legalPeople++;
        }
    }
    return legalPeople;
}
int Contacts::HowManyUniqueSurnames() {
    set<string> uniqueSurnames;
    cout<< "Unikalne nazwiska: ";
    for(auto it=phoneBook.get<1>().begin(); it!=phoneBook.get<1>().end(); it++){
        uniqueSurnames.insert(it->surname);
    }
    return uniqueSurnames.size();
}
void Contacts::showContent() {
    for(auto it=phoneBook.get<0>().begin(); it!=phoneBook.get<0>().end(); it++){
        it->show();
    }
    cout << endl;
}
void Contacts::oldStreet2newStreet(Contact &x) {
    if(x.street == "Muzyczna")
        x.street = "Lipowa";
}
