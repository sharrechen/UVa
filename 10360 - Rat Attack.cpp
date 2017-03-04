#include <iostream>
#include <vector>
using namespace std;

struct Rat {
    int x;
    int y;
    int size;
};

int main(void) {
    int t, d, n;

    cin >> t;
    while (t--) {
        cin >> d >> n;
        vector<Rat> rats(n);
        vector<vector<int> > killed(1024, vector<int>(1024, 0)); // record number of killed rats 
        Rat max_killed = {1024, 1024, 0};
        for (size_t i = 0; i < n; ++i) {
            cin >> rats[i].x >> rats[i].y >> rats[i].size;
        }

        for (size_t i = 0; i < n; ++i) {
            for (int x = (rats[i].x - d > 0 ? rats[i].x - d : 0); x <= (rats[i].x + d < 1024 ? rats[i].x + d : 1023); ++x) {
                for (int y = (rats[i].y - d > 0 ? rats[i].y - d: 0); y <= (rats[i].y + d < 1024 ? rats[i].y + d : 1023); ++y) {
                    killed[x][y] += rats[i].size;
                    if (killed[x][y] > max_killed.size) {
                        max_killed.size = killed[x][y];
                        max_killed.x = x;
                        max_killed.y = y;
                    } else if (killed[x][y] == max_killed.size) {
                        if (x < max_killed.x) {
                            max_killed.x = x;
                            max_killed.y = y;
                        } else if (x == max_killed.x && y < max_killed.y) {
                            max_killed.y = y;
                        }
                    }
                }
            }
        }
        cout << max_killed.x << " " << max_killed.y << " " << max_killed.size << endl;
    }

    return 0;
}
