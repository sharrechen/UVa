#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

struct Car {
    unsigned int id,
                 arrival_time;
    string bank_side;
};

int n, // number of cars a ferry can carry
    t, // time for a ferry to across river
    m; // number of cars need to be carried

bool computeUnloadTime(queue<Car> & cars, queue<Car> & others, vector<int> & unload_time, int & current) {
    if (cars.size() && (cars.front().arrival_time <= current || current == -1)) {
        if (current < 0) {
            current = cars.front().arrival_time + t;
        }
        for (int cnt = 0; !cars.empty() &&
                          cars.front().arrival_time <= current &&
                          cnt < n; ++cnt) {
            unload_time[cars.front().id] = current + t;
            cars.pop();
        }
        current += t; // update time
        return true;
    } else if (others.size() && others.front().arrival_time <= current){
        current += t; // across river
        return true;
    } else if (cars.size() && cars.front().arrival_time <= (others.size() ? others.front().arrival_time : INT_MAX)){ // wait at the same side
        current = cars.front().arrival_time; // waiting at same side
        return false;
    } else {
        current = -1; // wait at opposite side
        return true;
    }
}

int main(void) {
    unsigned int c; // number of test cases

    cin >> c;
    while (c--) {
        cin >> n >> t >> m;
        queue<Car> left_cars;
        queue<Car> right_cars;
        vector<int> unload_time(m);
        for (size_t i = 0; i < m; ++i) {
            string bank_side;
            Car car;
            cin >> car.arrival_time >> car.bank_side;
            car.id = i;
            if (car.bank_side[0] == 'l') {
                left_cars.push(car);
            } else {
                right_cars.push(car);
            }
        }
        bool side = 1; // 1: left, 0: right
        int current =
        min(left_cars.size() ? left_cars.front().arrival_time : INT_MAX,
            right_cars.size() ? right_cars.front().arrival_time: INT_MAX);
        while (!left_cars.empty() || !right_cars.empty()) {
            if (side) {
                side ^= computeUnloadTime(left_cars, right_cars, unload_time, current);
            } else { // at right bank side
                side ^= computeUnloadTime(right_cars, left_cars, unload_time, current);
            }
        }

        for (size_t i = 0; i < unload_time.size(); ++i) {
            cout << unload_time[i] << endl;
        }
        if (c) cout << endl;
    }
    return 0;
}
