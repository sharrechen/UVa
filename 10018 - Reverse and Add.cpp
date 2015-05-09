#include <iostream>

using namespace std;

unsigned long rev(unsigned long n) {
	unsigned long r = 0;
	while (n != 0) {
		r = r * 10 + n % 10;
		n /= 10;
	}
	return r;
}

int main(void) {
	unsigned long t, iter, num;

	cin >> t;
	while (t--) {
		cin >> num;
		iter = 0;
		do {
			num += rev(num);
			iter++;
		} while ( num != rev(num) );
		cout << iter << " " << num <<endl;
	}

	return 0;
}