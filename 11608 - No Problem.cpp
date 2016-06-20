#include <iostream>
using namespace std;

int main(void) {
  int nCase = 0;
  int problems[13];
  int requires[12];

  while (cin >> problems[0], problems[0] >= 0) {
      for (int m = 1; m < 13; m++) {
           cin >> problems[m];
      }
      for (int m = 0; m < 12; m++) {
           cin >> requires[m];
      }

      cout << "Case " << ++nCase << ":" << endl;
      for (int m = 0; m < 12; m++) {
           if (problems[m] >= requires[m]) {
               problems[m] -= requires[m];
               cout << "No problem! :D" << endl;
           } else {
               cout << "No problem. :(" << endl;
           }
           problems[m + 1] += problems[m];
      }
  }

  return 0;
}
