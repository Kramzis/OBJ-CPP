//
// Created by ASUS on 14.12.2022.
//

#ifndef LAB09_3_ADDRESSBOOK_H
#define LAB09_3_ADDRESSBOOK_H

#include <iostream>
using namespace std;

class AddressBook {
protected:
    string name;
    string surname;
    string sex;
    int grade;
public:
    AddressBook();
    void showAddressBook();
    void saveNewStudent(string newName, string newSurname, string newSex, int newGrade);
    void showChosenStudent(string chosenSurname);
    void createClassification();
    void showXStudents(int x);
    void sortAscending();

};


#endif//LAB09_3_ADDRESSBOOK_H
