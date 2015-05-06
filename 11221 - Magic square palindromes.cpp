#include <iostream>
#include <regex>
#include <cmath>

using namespace std;

int main(void) {
	int t, r, len, c = 1;
	float root;
	bool pl;
	string str;
	regex e("[ .,!?():~]");

	cin >> t;
	getchar();
	while (c <= t) {
		getline(cin, str);
		str = regex_replace(str, e, "$1");
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		pl = true;
		len = str.length() / 2;
		root = sqrt(str.length());
		if (root == floor(root)) {
			r = int(root);
			for (size_t i = 0, n = str.length() - 1; i <= len; ++i) {
				if (str[i] != str[n - i]) {
					pl = false;
					break;
				}
			}
			for (size_t c = 0, p = 0, s = 0, i = s, e = str.length() - 1, n = e; c <= len; ++c) {
				if (str[i] != str[n - p]) {
					pl = false;
					break;
				}
				if ( (c + 1) % r == 0) {
					s++;
					e--;
					i = s;
					n = e;
					p = 0;
				} else {
					p += r;
					i += r;
				}
			}
		} else {
			pl = false;
		}
		cout << "Case #" << c++ << ":" <<endl;
		if (pl) {
			cout << r <<endl;
		} else {
			cout << "No magic :(" <<endl;
		}
		
	}

	return 0;
}