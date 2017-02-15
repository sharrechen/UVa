#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    unsigned int d;
    vector<unsigned int> numbers;
    vector<unsigned int>::iterator m1;

    while (cin >> d) {
        numbers.push_back(d);
        m1 = numbers.begin() + (numbers.size() >> 1);
        nth_element(numbers.begin(), m1, numbers.end());

        int md = *m1;
        if (numbers.size() & 1) {
            cout << md << endl;
        } else {
            // get one more median for even size array
            nth_element(numbers.begin(), --m1, numbers.end());
            cout << ((md + *m1) >> 1) << endl;
        }
    }
    return 0;
}
