#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	string str;
	map<string, string> dic;
	vector<string> ananagrams;
	vector<string>::iterator wit;

	while (getline(cin, str) && str != "#") {
		stringstream ss(str);
		while (ss >> str) {
			string w = str;
			transform(w.begin(), w.end(), w.begin(), ::tolower);
			sort(w.begin(), w.end());
			pair<map<string, string>::iterator, bool> ret = dic.insert(pair<string, string>(w, str));
			if (ret.second == false) {
				wit = find(ananagrams.begin(), ananagrams.end(), ret.first -> second);
				if ( wit != ananagrams.end()) {
					ananagrams.erase(wit);
				}
			} else {
				ananagrams.push_back(str);
			}
		}
	}

	sort(ananagrams.begin(), ananagrams.end());
	for (int i = 0; i < ananagrams.size(); ++i) {
		cout << ananagrams[i] << endl;
	}
	
	return 0;
}