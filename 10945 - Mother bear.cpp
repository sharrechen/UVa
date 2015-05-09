#include <algorithm>
#include <iostream>
#include <regex>

using namespace std;

int main(void) {
	int len;
	bool pl;
	string s;
	regex e("[ .,!?]");
	getline(cin, s);
	while (!(s == "DONE")) {
		s = regex_replace(s, e, "$1");
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		len = s.length() / 2;
		pl = true;
		for (size_t i = 0, n = s.length() - 1; i <= len; ++i, --n) {
			if (s[i] != s[n]) {
				pl = false;
				break;
			}
		}
		if (pl) {
			cout << "You won't be eaten!" <<endl;
		} else {
			cout << "Uh oh.." <<endl;
		}
		getline(cin, s);
	}

	return 0;
}