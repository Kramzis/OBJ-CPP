//
// Created by ASUS on 21.12.2022.
//

#ifndef LAB12_2_CAR_H
#define LAB12_2_CAR_H

#include <iostream>

using namespace std;

class Car
{
    string model;
    int year;
    int capacity;
public:
    Car();
    Car(const string &model, int year, int capacity);
    const string &getModel() const;
    void setModel(const string &newModel);
    int getYear() const;
    void setYear(int newYear);
    int getCapacity() const;
    void setCapacity(int newCapacity);

    void show();
};

#endif//LAB12_2_CAR_H
