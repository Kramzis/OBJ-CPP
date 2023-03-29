//
// Created by ASUS on 22.11.2022.
//

#ifndef LAB06_2_CONTACTS_H
#define LAB06_2_CONTACTS_H
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <set>
#include "Contact.h"
using namespace boost::multi_index;
using namespace std;

typedef multi_index_container<Contact, indexed_by<hashed_non_unique<member<Contact, string, &Contact::name>>,
                                                  hashed_non_unique<member<Contact, string, &Contact::surname>>,
                                                  hashed_non_unique<member<Contact, int, &Contact::age>>,
                                                  hashed_unique<member<Contact, string, &Contact::phoneNumber>>,
                                                  hashed_non_unique<member<Contact, string, &Contact::street>>
                                                  >> multi_contacts;

typedef multi_contacts ::nth_index<4>::type street_type;

class Contacts {
public:
    multi_contacts phoneBook;
    void addContact(string newName, string newSurname, int newAge, string newPhoneNumber, string newStreet);
    void delContact(string searchedNumber);
    void searchByStreet(string chosenStreet);
    void searchByAge(int beginRange, int endRange);
    void searchByPhone(string pickedNumber);
    void changeStreet(string oldStreet, string newStreet);
    int HowManyOver18();
    int HowManyUniqueSurnames();
    void showContent();
    static void oldStreet2newStreet(Contact &x);
};


#endif//LAB06_2_CONTACTS_H
