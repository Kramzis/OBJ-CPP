//
// Created by ASUS on 22.11.2022.
//

#include "Contact.h"
void Contact::show() const{
    cout<<"Imie: "<<name<<" nazwisko: "<<surname<<" wiek: "
         <<age<<" nr telefonu: "<<phoneNumber<<" ulica: "<<street<<endl;
}
Contact::Contact(string newName, string newSurname, int newAge, string newPhoneNumber, string newStreet) {
    this->name = newName;
    this->surname = newSurname;
    this->age = newAge;
    this->phoneNumber = newPhoneNumber;
    this->street = newStreet;
}
