#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	int t;
	string phrase, str;
	map<string, string> phrases;

	cin >> t;
	cin.ignore();
	cin.ignore();
	while (t--) {
		while (getline(cin, phrase) && phrase.length() > 0) {
			str = phrase;
			str.erase(remove(str.begin(), str.end(), ' '), str.end());
			sort(str.begin(), str.end());
			phrases.insert(pair<string, string>(phrase, str));
		}
		
		// output anagrams by lexicographic order.
		for (map<string, string>::iterator it = phrases.begin(); it != phrases.end(); ++it) {
			map<string, string>::iterator w = it;
			for (++w; w != phrases.end(); ++w) {
				if (w->second == it->second) {
					cout << it->first << " = " << w->first << endl;
				}
			}
		}

		if (t) cout << endl;

		phrases.clear();
	}

	return 0;
}