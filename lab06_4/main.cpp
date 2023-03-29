#include <iostream>
#include <map>
#include <boost/fusion/functional.hpp>
boost::fusion::vector<int,double,float,bool,char> vektor{10,5.0,4.5, false,'a'};
using namespace std;
//szkic zadania 4
map<string,int> result() {
    boost::fusion::for_each(vektor, [%result] (auto& v){

    }
}

int main() {
    return 0;
}