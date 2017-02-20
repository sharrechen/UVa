#include <iostream>
#include <bitset>
using namespace std;

int main(void) {
    int n, // one-time task
        m; // repeating task
    while (cin >> n >> m, n || m) {
        bitset<1000000> slots;
        bool conflict = false;
        int start, end, interval;
        while (n--) {
            cin >> start >> end;
            for (int i = start; i < end; ++i) {
                if (slots.test(i)) {
                    conflict = true;
                    break;
                }
                slots.set(i);
            }
        }
        while (m--) {
            cin >> start >> end >> interval;
            if (conflict) { continue; }
            for (int i = start; i < 1000000; ) {
                if (i < end) {
                    if (slots.test(i)) {
                        conflict = true;
                        break;
                    }
                    slots.set(i++);
                } else {
                    start += interval;
                    end += interval;
                    i = start;
                }
            }
        }
        cout << (conflict ? "CONFLICT" : "NO CONFLICT") << endl;
    }
    return 0;
}
