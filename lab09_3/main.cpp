#include <iostream>
#include <fstream>

using namespace std;
int main() {
    string path;
jump:
    cout << "Podaj sciezke do pliku:" << endl;
    cin >> path;
    bool tempe = filesystem::exists(path);
    if (!tempe) {
        cout << "Zla sciezka!" << endl;
        goto jump;
    }
    ifstream file(path);
    string line1;
    stringstream temp;
    string forward;
    vector<Student> dane;
    vector<string> doZapisu;
    string noweImie;
    string noweNazwisko;
    string nowaPlec;
    string nowaOcena;
    string nowyEmail;
    string nazwiskoDoZnalezienia;
    vector<char> alfabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                            'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                            'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    bool checker = true;
    while (getline(file, line1)) {
        std::istringstream iss(line1);
        std::vector<std::string> results((std::istream_iterator<WordDelimitedByCommas>(iss)),
                                         std::istream_iterator<WordDelimitedByCommas>());
        if (results.size() == 5) {
            dane.push_back(*zapisz(results[0], results[1], results[2], results[3], results[4]));
        } else {
            dane.push_back(*zapisz(results[0], results[1], results[2], results[3], ""));
        }

    }
    string wybor;
    while (true) {
    jump2:
        cout << "Wybor:" << endl;
        cin >> wybor;
        if (!(wybor == "1" || wybor == "2" || wybor == "3" || wybor == "4" || wybor == "5" || wybor == "6" ||
              wybor == "7")) {
            cout << "Zly wybor!" << endl;
            goto jump2;
        }
        if (wybor == "1") {
            for (auto i: dane) {
                cout << setw(20) << left << setfill('_') << i.imie << " " <<
                        setw(20) << left << setfill('_') << i.nazwisko << " " <<
                        setw(20) << left << setfill('_') << i.plec << " " <<
                        setw(20) << left << setfill('_') << i.ocena << " " <<
                        setw(20) << left << setfill('_') << i.email << " " << endl;
            }
        } else if (wybor == "2") {
            while (true) {
                cout << "Podaj imie:" << endl;
                cin >> noweImie;
                cout << "Podaj nazwisko:" << endl;
                cin >> noweNazwisko;
                cout << "Podaj plec:" << endl;
                cin >> nowaPlec;
            jump3:
                cout << "Podaj ocene:" << endl;
                cin >> nowaOcena;
                for (auto a: nowaOcena) {
                    if (!isdigit(a)) {
                        cout << "Ocena musi byc liczba!";
                        goto jump3;
                    }
                }
                cout << "Podaj email:" << endl;
                cin >> nowyEmail;
                for (auto i: noweImie) {
                    if (count(alfabet.begin(), alfabet.end(), i)) {

                    } else {
                        checker = false;
                    }
                }
                for (auto i: noweNazwisko) {
                    if (count(alfabet.begin(), alfabet.end(), i)) {

                    } else {
                        checker = false;
                    }
                }
                if (isupper(noweImie[0]) && isupper(noweNazwisko[0]) && checker &&
                    (nowaPlec == "K" || nowaPlec == "M") && (nowyEmail.find('@') != string::npos)) {
                    break;
                } else {
                    cout << "Zle dane!" << endl;
                }
            }
            dane.push_back(*zapisz(noweImie, noweNazwisko, nowaPlec, nowaOcena, nowyEmail));
        } else if (wybor == "3") {
            cout << "Podaj nazwisko:" << endl;
            cin >> nazwiskoDoZnalezienia;
            bool aba = true;
            for (auto i: dane) {
                if (i.nazwisko == nazwiskoDoZnalezienia) {
                    cout << setw(20) << left << setfill('_') << i.imie << " " <<
                            setw(20) << left << setfill('_') << i.nazwisko << " " <<
                            setw(20) << left << setfill('_') << i.plec << " " <<
                            setw(20) << left << setfill('_') << i.ocena << " " <<
                            setw(20) << left << setfill('_') << i.email << " " << endl;
                    aba = false;
                }

            }
            if (aba) {
                cout << "Nie znaleziono osoby z takim nazwiskiem!" << endl;
            }
        } else if (wybor == "4") {
            ofstream outfile("C:\\Users\\ASUS\\ClionProjects\\lab09_3\\dane.csv");
            int trash = 1;
            for (auto i: dane) {
                string str = i.imie + ";" + i.nazwisko + ";" + i.plec + ";" + i.ocena + ";" + i.email;
                if (trash == dane.size() && (i.plec == "plec" || i.plec == "K")) {
                    outfile << str;
                } else if (i.plec == "plec" || i.plec == "K") {
                    outfile << str << endl;
                }
                trash++;
            }
            outfile.close();
            ofstream outfile2("C:\\Users\\ASUS\\ClionProjects\\lab09_3\\dane.csv");
            int trash2 = 1;
            for (auto i: dane) {
                string str = i.imie + ";" + i.nazwisko + ";" + i.plec + ";" + i.ocena + ";" + i.email;
                if (trash2 == dane.size() && (i.plec == "plec" || i.plec == "M")) {
                    outfile2 << str;
                } else if (i.plec == "plec" || i.plec == "M") {
                    outfile2 << str << endl;
                }
                trash2++;
            }
            outfile.close();
        } else if (wybor == "5") {
            string ilosc;
        jump4:
            cout << "Podaj ilosc rekordow:" << endl;
            cin >> ilosc;
            for (auto b: ilosc) {
                if (!isdigit(b)) {
                    cout << "Ilosc rekordow musi byc liczba!" << endl;
                    goto jump4;
                }
            }
            if (stoi(ilosc) + 1 == dane.size()) {
                for (auto i: dane) {
                    cout << setw(20) << left << setfill('_') << i.imie << " " <<
                            setw(20) << left << setfill('_') << i.nazwisko << " " <<
                            setw(20) << left << setfill('_') << i.plec << " " <<
                            setw(20) << left << setfill('_') << i.ocena << " " <<
                            setw(20) << left << setfill('_') << i.email << " " << endl;
                }
            } else if (stoi(ilosc) + 1 >= dane.size()) {
                for (auto i: dane) {
                    cout << setw(20) << left << setfill('_') << i.imie << " " <<
                            setw(20) << left << setfill('_') << i.nazwisko << " " <<
                            setw(20) << left << setfill('_') << i.plec << " " <<
                            setw(20) << left << setfill('_') << i.ocena << " " <<
                            setw(20) << left << setfill('_') << i.email << " " << endl;
                }
                for (int i = 0; i < stoi(ilosc) + 1 - dane.size(); i++) {
                    cout << setw(20) << left << setfill('') << "" << " " <<
                            setw(20) << left << setfill('') << "" << " " <<
                            setw(20) << left << setfill('') << "" << " " <<
                            setw(20) << left << setfill('') << "" << " " <<
                            setw(20) << left << setfill('') << "" << " " << endl;
                }
            } else {
                for (int i = 0; i < stoi(ilosc) + 1; i++) {
                    cout << setw(20) << left << setfill('_') << dane[i].imie << " " <<
                            setw(20) << left << setfill('_') << dane[i].nazwisko << " " <<
                            setw(20) << left << setfill('_') << dane[i].plec << " " <<
                            setw(20) << left << setfill('_') << dane[i].ocena << " " <<
                            setw(20) << left << setfill('_') << dane[i].email << " " << endl;
                }
            }
        } else if (wybor == "6") {
            sort(dane.begin() + 1, dane.end(), myCmp);
        } else if (wybor == "7") {
            break;
        }
    }
    string str;
    file.close();
    ofstream file2(path);
    int trash = 1;
    for (auto i: dane) {
        str = i.imie + ";" + i.nazwisko + ";" + i.plec + ";" + i.ocena + ";" + i.email;
        if (trash == dane.size()) {
            file2 << str;
        } else {
            file2 << str << endl;
        }
        trash++;
    }
    file2.close();
    return 0;
}
