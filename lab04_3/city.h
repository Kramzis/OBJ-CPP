#ifndef CITY_H
#define CITY_H
#include <vector>
#include "citizen.h"

class City
{
private:
    vector<Citizen> citizens;
    string cityName;

    static bool ifWomen(Citizen cit);
    static bool ifAdults(Citizen cit);
    static string firstMode(vector<City> c);
    static string secondMode(vector<City> c);
public:
    City();
    City(string cName);
    void addCitizen(Citizen cit);
    void deleteCitizen(string surname, int age);
    void showCitizens();
    void showCity();
    int women();
    int cityCitizens();
    int adults();
    int postalCodes();
    const string &getCityName() const;

    static void showCities(vector<City> c);
    static void the_most(vector<City> c, int mode);
    static void statistic(vector <City> c);
    static void sort_cities(vector <City> &c);
};

#endif // CITY_H
