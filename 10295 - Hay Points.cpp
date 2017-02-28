#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main(void) {
    unsigned int m, n;
    map<string, unsigned int> dictionary;

    cin >> m >> n;
    while (m--) {
        string term;
        unsigned int dollar;
        cin >> term >> dollar;
        dictionary[term] = dollar;
    }

    getchar();
    while (n--) {
        string line;
        unsigned int sum = 0;
        while (getline(cin, line) && line[line.length() - 1] != '.') {
            string term;
            stringstream ss(line);
            while (getline(ss, term, ' ')) {
                sum += dictionary[term];
            }
        }
        cout << sum << endl;
    }

    return 0;
}