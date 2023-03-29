//
// Created by ASUS on 22.11.2022.
//

#ifndef LAB06_2_CONTACT_H
#define LAB06_2_CONTACT_H
#include <iostream>
using namespace std;

class Contact {
public:
    string name, surname;
    int age;
    string phoneNumber;
    string street;
    Contact(string name, string surname, int age, string phoneNumber, string street);
    void show() const;
};


#endif//LAB06_2_CONTACT_H
