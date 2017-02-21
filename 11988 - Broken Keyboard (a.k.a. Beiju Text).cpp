#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

int main(void) {
    string line;
    while (getline(cin, line)) {
        list<string> beiju;
        list<string>::iterator itr = beiju.begin();
        // can be simpler, but keep this one for faster
        size_t s = 0, i = 0;
        for (; i < line.length(); ++i) {
            if (line[i] == '[') { // press Home key
                beiju.insert(itr, line.substr(s, i - s));
                itr = beiju.begin();
                s = i + 1;
            } else if (line[i] == ']') { // press End key
                beiju.insert(itr, line.substr(s, i - s));
                itr = beiju.end();
                s = i + 1;
            }
        }
        beiju.insert(itr, line.substr(s, i - s));
        copy(beiju.begin(), beiju.end(), ostream_iterator<string>(cout, ""));
        cout << "\n";
    }
    return 0;
}
