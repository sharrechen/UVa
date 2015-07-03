#include <iostream>
#include <algorithm>
#include <string>
#include <locale>

using namespace std;

struct comparator {
	bool operator () (const char& x, const char& y) {
		return toupper(x) != toupper(y) ? toupper(x) < toupper(y) : x < y;
	}
} cmp;

int main(void) {
	int t;
	string str;

	cin >> t;
	while (t--) {
		cin >> str;
		sort(str.begin(), str.end(), cmp);
		do {
			cout << str << endl;
		} while (next_permutation(str.begin(), str.end(), cmp));
	}

	return 0;
}