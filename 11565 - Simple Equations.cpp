#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int N, A, B, C;

    cin >> N;
    while (N--) {
        cin >> A >> B >> C;
        
        bool solved = false;
        for (int x = -22; !solved && x <= 22; ++x) if (x * x < C)
            for (int y = -100; !solved && y <= 100; ++y) if (x != y && x * x + y * y < C)
                for (int z = -100; !solved && z <= 100; ++z)
                    if (y != z && z != x && x + y + z == A && x * y * z == B && x * x + y * y + z * z == C) {
                            cout << min(x, y) << " " << max(x, y) << " " << z << endl;
                            solved = true;
                    }

        if (!solved) cout << "No solution." << endl;
    }

    return 0;
}