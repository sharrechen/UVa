#include <stdio.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void) {

	int a, b, begin, end, maxclen, clength;
	unsigned long long n;
	int history[1000000] = {};
	while (scanf("%d %d", &a, &b)!= EOF) {
		begin = a;
		end = b;
		if (end < begin) swap(begin, end);
		maxclen = 0;
		for (int i = begin; i <= end; i++) {
			if (history[i]) {
				maxclen = max( maxclen, history[i]);
			} else {
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
				history[i] = clength;
				maxclen = max( maxclen, clength);
			}
		}
		printf("%d %d %d\n", a, b, maxclen); 
	}
}