#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main(void) {
    map<int, int> deparments;
    queue<int> q;
    set<int> s; // keep queue elements unique
    int d;
    while (cin >> d) {
        deparments[d]++;
        if (s.find(d) == s.end()) {
            q.push(d);
            s.insert(d);
        }
    }
    while (!q.empty()) {
        cout << q.front() << " " << deparments[q.front()] << endl;
        q.pop();
    }

    return 0;
}
