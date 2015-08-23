#include <iostream>
#include <string>

using namespace std;

string sound(char c) {
    switch(c) {
        case 'B':
        case 'F':
        case 'P':
        case 'V':
            return "1";
        case 'C':
        case 'G':
        case 'J':
        case 'K':
        case 'Q':
        case 'S':
        case 'X':
        case 'Z':
            return "2";
        case 'D':
        case 'T':
            return "3";
        case 'L':
            return "4";
        case 'M':
        case 'N':
            return "5";
        case 'R':
            return "6";
        default:
            return "";
    }
}

int main(void) {
    string str;

    while (getline(cin, str)) {
        string soundex, last, current;
        last = sound(str[0]);
        soundex.append(last);
        for (size_t i = 1; i < str.size(); ++i) {
            if ((current = sound(str[i]))[0] != last[0]) {
            	soundex.append(current);
            }
            last = current;
        }
        cout << soundex << endl;
    }
    return 0;
}