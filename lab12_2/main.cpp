#include <iostream>
#include "Car.h"
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<Car> cars;

    cars.push_back(Car("Toyota Corolla",2007,1399));
    cars.push_back(Car("Ford Mustang",2009,2700));
    cars.push_back(Car("BMW E46",1999,1800));
    cars.push_back(Car("Dacia Duster",2010,1461));
    cars.push_back(Car("Audi A8",2019,3000));


    sort(cars.begin(),cars.end(),[](Car a, Car b){return a.getYear()<b.getYear();});
    int cnt=1;
    for_each(cars.begin(),cars.end(),[&cnt](Car el){
        cout<<"Samochod "<<cnt<<": ";
        el.show();
        cnt++;
    });
    cout<<endl;
    sort(cars.begin(),cars.end(),[](Car a, Car b){return a.getCapacity()>b.getCapacity();});
    cnt=1;
    for_each(cars.begin(),cars.end(),[&cnt](Car el){
        cout<<"Samochod "<<cnt<<": ";
        el.show();
        cnt++;
    });
    return 0;
}
