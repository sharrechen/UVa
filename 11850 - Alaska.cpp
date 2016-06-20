#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int nStation, dest = 1422;
  int stationLocations[1423];
  while (cin >> nStation, nStation) {
      bool isPossible = true;
      for (int i = 0; i < nStation; ++i) {
          cin >> stationLocations[i];
      }
      sort(stationLocations, stationLocations + nStation);
      for (int i = 1; i < nStation; ++i) {
          if ((stationLocations[i] - stationLocations[i-1]) > 200) {
              isPossible = false;
              break;
          }
      }
      if (isPossible && ((dest - stationLocations[nStation -1]) << 1) > 200) {
          isPossible = false;
      }
      cout << (isPossible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }

  return 0;
}
