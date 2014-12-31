#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void) {

	int a, b, begin, end, maxclen, clength;
	unsigned long long n;

	while (cin >> a >> b) {
		begin = a;
		end = b;
		if (end < begin) swap(begin, end);
		maxclen = 0;
		for (int i = begin; i <= end; i++) {
			clength = 1;
			n = i;
			while (n != 1) {
				if (n & 1) {
					n = 3 * n + 1;
				}else{
					n >>= 1;
				}
				clength++;
			}
			maxclen = max( maxclen, clength);
			
		}
		cout << a << " " << b << " " << maxclen <<endl; 
	}
}