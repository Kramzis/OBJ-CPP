//
// Created by ASUS on 24.10.2022.
//

#ifndef LAB03_3_ARRAY_H
#define LAB03_3_ARRAY_H
#include <iostream>
using namespace std;

template<typename T>
class Array
{
private:
    T * arr;
    int size{};
    int firstFree;
public:
    explicit Array(int size) {
        this->size = size;
        arr = new T[size];
        firstFree = 0;
    }
    Array() {
        this->size = 10;
        arr = new T[10];
        firstFree = 0;

    }
    ~Array() {
        delete [] arr;
    }
    void sort() {
        int temp, j;

        for(int i = 1; i < size; i++)
        {
            temp = arr[i];

            for(j = i-1; j >= 0 && arr[j] > temp; j-- )
                arr[j + 1] = arr[j];

            arr[j+1] = temp;
        }
    }
    T findMax(){
        T maxi = arr[0];
        for(int i = 1; i < size; i++)
        {
            if(maxi < arr[i]){
                maxi = arr[i];
            }
        }
        return maxi;
    };

    void show() {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;

        }
    }
    void addEl(T element) {
        arr[firstFree] = element;
        firstFree++;
    }
    T returnEl(int index){
            return arr[index];
    };
};

template<>
void Array<string>::sort() {
    for( int i = 0; i < size; i++ )
    {
        for( int j = 0; j < size - 1; j++ )
        {
            if( arr[j].length() > arr[j+1].length())
                swap(arr[j], arr[j+1]);
        }
    }
}

template<>
string Array<string>::findMax()
{
    int maxi = arr[0].length();
    int index;
    for(int i = 1; i < size; i++)
        {
            if(maxi < arr[i].length())
            {
                maxi = arr[i].length();
                index = i;
            }
        }

    return arr[index];
}


#endif//LAB03_3_ARRAY_H
