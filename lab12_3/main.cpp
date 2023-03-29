#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

tuple<int,float,string> fun(vector<string> words){

    vector<int> wordsToInt;
    for_each(words.begin(),words.end(),[&wordsToInt](string el){
        wordsToInt.push_back(el.length());
    });
    auto maks = max_element(wordsToInt.begin(),wordsToInt.end());
    auto mini = min_element(words.begin(),words.end(),[](string a, string b){
        return a.length()<b.length();
    });

    float sum = 0;
    for_each(wordsToInt.begin(),wordsToInt.end(),[&sum](int el){
        sum+=el;
    });
    float avr = sum/(float)wordsToInt.size();

    tuple <int, float, string> t;
    t = make_tuple(*maks,avr,*mini);

    return t;
}

int main()
{
    vector<string> words;
    words.push_back("czerwony");
    words.push_back("niebieski");
    words.push_back("zolty");
    words.push_back("fioletowy");
    words.push_back("zielony");
    words.push_back("pomaranczowy");
    words.push_back("czarny");

    auto tup = fun(words);
    cout << "Dlugosc najdluzszego napisu: "<<get<0>(tup)<<endl;
    cout << "Srednia dlugosc napisu: "<<get<1>(tup)<<endl;
    cout << "Najkrotszy napis: "<<get<2>(tup)<<endl;
    return 0;
}
