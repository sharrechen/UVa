#include <iostream>
#include <queue>
using namespace std;

int main(void) {

    int n;
    while (cin >> n, n) {
        queue<int> cards;
        queue<int> discarded_cards;
        for (int i = 1; i <= n; ++i) {
            cards.push(i);
        }
        while (cards.size() > 1) {
            discarded_cards.push(cards.front());
            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }
        cout << "Discarded cards:";
        if (discarded_cards.size()) {
            cout << " " << discarded_cards.front();
            discarded_cards.pop();
        }
        while (!discarded_cards.empty()) {
            cout << ", " << discarded_cards.front();
            discarded_cards.pop();
        }
        cout << endl << "Remaining card: " << cards.front() << endl;
    }

    return 0;
}
