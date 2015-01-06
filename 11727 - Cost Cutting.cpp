#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int T;
    int i = 1;
    vector<int> salary(3, 0);

    cin >> T; 
    while (T--) {
        cin >> salary[0] >> salary[1] >> salary[2];
        sort(salary.begin(), salary.end());
        cout << "Case " << i++ << ": " << salary[1] <<endl;
    }
    return 0;
}