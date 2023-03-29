#include <iostream>
#include "Adding.h"
#include "Student.h"

using namespace std;

int main() {
    Adding<int> a1(5);
    a1.add(6);
    a1.show();
    Adding<string> a2("Pro");
    a2.add("gramowanie");
    a2.show();

    Student<float> s(5,"Ala");
    s.showMark();
    Student<int> s1(5,"Ala");
    s1.showMark();
    Student<string> s2(5,"Ala");
    s2.showMark();
    return 0;
}
