#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int t, n;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cout << abs(((n*567/9+7492)*235/47-498)/10%10) <<endl;
	}
	
	return 0;
}