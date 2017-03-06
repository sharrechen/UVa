#include <iostream>
#include <queue>
using namespace std;

/* 
*  if x != y:
*    1/x + 1/y = 1/k
*    1/y = 1/k - 1/x
*    1/y = (x - k)/(x * k)
*    y = (x * k)/(x - k)
*  if x == y:
*    1/x + 1/x = 1/k
*    2/x = 1/k
*    x = 2*k  
*/
int main(void) {
    int k;
    queue<int> ys;

    while (cin >> k) {
        for (int x = k + 1; x <= 2 * k; ++x) {
            if ((x * k) % (x - k) == 0) {
                ys.push(x);
            }
        }
        cout << ys.size() << endl;
        while (!ys.empty()) {
            cout << "1/" << k << " = 1/" << ys.front() * k / (ys.front() - k) << " + 1/" << ys.front() << endl;
            ys.pop();
        }
    }

    return 0;
}