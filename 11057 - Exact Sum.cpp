#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int books, money, buy;

    while (cin >> books) {
        vector<int> price(books);
        for (int i = 0; i < books; ++i) {
            cin >> price[i];
        }
        sort(price.begin(), price.end());
        cin >> money;
        buy = 0;
        for (int i = 0; i < price.size(); ++i) {
            if (binary_search(price.begin() + i + 1, price.end(), money - price[i])) {
                if (money - (price[i] << 1) < money - (buy << 1)) {
                    buy = price[i];
                }
            }
        }

        cout << "Peter should buy books whose prices are " << buy << " and ";
        cout << money - buy << "." << endl << endl;
    }

    return 0;
}
