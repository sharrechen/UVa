#include <iostream>

using namespace std;

int main(void) {
    int birthD, birthM, birthY, 
        curD, curM, curY;
    int t, years, n = 1;
    char c;

    cin >> t;
    while (t--) {
        cin >> curD >> c >> curM >> c >> curY;
        cin >> birthD >> c >> birthM >> c >> birthY;

        years = curY - birthY;
        if (curY >= birthY) {
            if (curM < birthM ||
                (curM == birthM && curD < birthD)) {
                years--;
            }
        }

        cout << "Case #" << n++;
        if (years < 0) {
            cout << ": Invalid birth date" << endl;
        } else if (years > 130) {
            cout << ": Check birth date" << endl;
        } else {
            cout << ": " << years << endl;
        }
    }

    return 0;
}