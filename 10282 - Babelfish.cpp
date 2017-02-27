#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main(void) {
    map<string, string> dictionary;
    map<string, string>::iterator itr;
    string s, en, fr;

    while (getline(cin, s) && !s.empty()) {
        istringstream iss(s);
        getline(iss, en, ' '); // read English
        getline(iss, fr);      // read foreign language
        dictionary[fr] = en;
    }

    while (cin >> fr) {
        itr = dictionary.find(fr);
        if (itr != dictionary.end()) {
            cout << itr->second << endl;
        } else {
            cout << "eh" << endl;
        }
    }

    return 0;
}