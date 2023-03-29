#include <iostream>
#include "citizen.h"
#include "city.h"

using namespace std;

int main()
{
    City m("Markow");
    City l("Lublin");
    City r("Radawiec");


    Citizen obywatel1("Magdalena","Kramek",21,'M',"08-307");
    m.addCitizen(obywatel1);
    Citizen obywatel2("Mateusz","Kowal",33,'M',"08-306");
    m.addCitizen(obywatel2);
    Citizen obywatel3("Anna","Kowalska",45,'K',"08-307");
    m.addCitizen(obywatel3);
    Citizen obywatel4("Joanna","Rok",17,'K',"08-309");
    m.addCitizen(obywatel4);
    Citizen obywatel5("Malwina","Semeniuk",14,'K',"08-309");
    m.addCitizen(obywatel5);
    Citizen obywatel6("Jerzy","Pak",25,'M',"08-309");
    m.addCitizen(obywatel6);

    Citizen obywatel7("Łukasz","Krakowski",18,'M',"20-140");
    l.addCitizen(obywatel7);
    Citizen obywatel8("Marek","Bizon",15,'M',"20-141");
    l.addCitizen(obywatel8);
    Citizen obywatel9("Anna","Zawadzka",45,'K',"20-140");
    l.addCitizen(obywatel9);
    Citizen obywatel10("Magda","Kowalska",22,'K',"20-140");
    l.addCitizen(obywatel10);
    Citizen obywatel11("Joanna","Dobrowolska",14,'K',"20-141");
    l.addCitizen(obywatel11);
    Citizen obywatel12("Jerzy","Kowalski",25,'M',"20-141");
    l.addCitizen(obywatel12);
    Citizen obywatel13("Karol","Krok",26,'M',"20-141");
    l.addCitizen(obywatel13);

    Citizen obywatel14("Paweł","Żuk",33,'M',"12-541");
    r.addCitizen(obywatel14);
    Citizen obywatel15("Anna","Zdroinska",16,'K',"12-542");
    r.addCitizen(obywatel15);
    Citizen obywatel16("Magda","Raba",17,'K',"12-543");
    r.addCitizen(obywatel16);
    Citizen obywatel17("Janina","Podlaska",22,'K',"12-543");
    r.addCitizen(obywatel17);
    Citizen obywatel18("Adam","Para",25,'M',"12-544");
    r.addCitizen(obywatel18);

   // m.showCitizens();
    //cout<<"Po usunieciu"<<endl;
    //cout<<endl;
    //m.deleteCitien("Kramek",21);
    //cout<<endl;
    //m.showCitizens();

    //m.showCity();
    vector<City> miasta;
    miasta.push_back(m);
    miasta.push_back(r);
    miasta.push_back(l);

    City::showCities(miasta);
    cout<<endl;
    cout<<"Po posortowaniu:"<<endl<<endl;
    City::sort_cities(miasta);
    City::showCities(miasta);
    //City::the_most(miasta,1);

    //City::statistic(miasta);
    //cout<<"Liczba kobiet: "<<m.women()<<endl;
    //cout<<"Liczba pelnoletnich obywateli: "<<m.adults()<<endl;

    //m.postalCodes();


    return 0;
}
