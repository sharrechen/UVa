#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    string code;
    while(getline(cin, code), code != "#") {
        if (next_permutation(code.begin(), code.end())) {
            cout << code << endl;
        } else {
            cout << "No Successor" << endl;
        }
    }

    return 0;
}
