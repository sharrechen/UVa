#include <iostream>
#include <queue>
using namespace std;

bool crossRiver(queue<int> & cars, queue<int> & others, int & crossCnt, int l) {
    bool cross = 0;
    while (!cars.empty() && cars.front() <= l) {
        l -= cars.front();
        cars.pop();
        cross = 1;
    }
    if (cross || others.size()) { // need cross or has opposite waiting cars
        ++crossCnt;
        return true;
    }
    return false;
}

int main(void) {
    int c;
    cin >> c;
    while (c--) {
        int l, m;
        cin >> l >> m;
        l *= 100; // transfer m to cm
        queue<int> left_cars;
        queue<int> right_cars;
        for (size_t i = 0; i < m; ++i) {
            int length;
            string bank;
            cin >> length >> bank;
            if (bank[0] == 'l') {
                left_cars.push(length);
            } else {
                right_cars.push(length);
            }
        }

        bool bank = 1; // 1: left, 0: right
        int crossCnt = 0;
        while (!left_cars.empty() || !right_cars.empty()) {
            if (bank) { // at left bank
                bank ^= crossRiver(left_cars, right_cars, crossCnt, l);
            } else {   // at right bank
                bank ^= crossRiver(right_cars, left_cars, crossCnt, l);
            }
        }
        cout << crossCnt << endl;
    }

    return 0;
}
