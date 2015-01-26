#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main(void) {
	char digits[1048576];
	int x1, x2, i, sum, n;
	stringstream ss;

	while (gets(digits), digits[0] != 'E') {
		i = 1;
		ss << digits;
		ss >> x1;
		sum = x2 = strlen(digits);
		while ( x2 != x1) {
			for (n = 0; sum != 0; n++) {
				sum /= 10;
			}
			x1 = x2;
			sum = x2 = n;
			i++;
		}
		cout << i <<endl;
		ss.str("");
		ss.clear();
	}
	return 0;
}