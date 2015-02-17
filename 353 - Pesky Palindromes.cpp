#include <iostream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

bool pl(string s, int len) {
	int mid = len / 2;
	for (size_t f = 0, e = len -1; f < mid; ++f, --e) {
		if (s[f] != s[e]) return 0;
	}
	return 1;
}

int main(void) {
	string str, check;
	set<string> uniStr;
	int len;
	
	while (cin >> str) {
		uniStr.clear();
		len = str.length();
		for (size_t i = 0; i < len; ++i) {
			for (size_t t = 1; t <= len - i; ++t) {
				check = str.substr(i, t);
				if (pl(check, check.length())) {
					uniStr.insert(check);
				}
			}
		}
		cout << "The string '" << str << "' contains " << uniStr.size() << " palindromes." <<endl;
	}

	return 0;
}