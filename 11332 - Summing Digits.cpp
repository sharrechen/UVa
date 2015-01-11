#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string g(string n) {
	if (n.length() == 1) {
		return n;
	} else {
		stringstream ss;
		int digit, sum = 0;
		for (int i = 0; i < n.length(); i++) {
			ss << n[i];
			ss >> digit;
			sum += digit;
			ss.str("");
			ss.clear();
		}
		ss << sum;
		return g(ss.str());
	}
	
}
int main(void) {
	string n;
	while (cin >> n, n != "0") {
		cout << g(n) <<endl;
	}
	return 0;
}