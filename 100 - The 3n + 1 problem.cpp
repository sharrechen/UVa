#include <iostream>
#include <cstdlib>
using namespace std;

int n3_1(unsigned long long n) {
	int clength = 1;
	while (n != 1) {
		if (n & 1) {
			n = 3 * n + 1;
		}else{
			n >>= 1;
		}
		clength++;
	}
	return clength;
}

int main(void) {

	int a, b, begin, end, maxclen;
	int history[1000000]={};

	while (cin >> a >> b) {
		begin = a < b ? a : b;
		end = a > b ? a : b;
		maxclen = 0;
		for (int i = begin; i <= end; i++) {
			if (maxclen < history[i] ) {
				maxclen = history[i];
			}else if (maxclen < (history[i] = n3_1(i))) {
				maxclen = history[i];
			}
		}
		cout << a << " " << b << " " << maxclen <<endl; 
	}
}