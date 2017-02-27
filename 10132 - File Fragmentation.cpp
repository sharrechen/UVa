#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int> & a, const pair<string, int> & b) {
  return a.second < b.second; 
}

int main(void) {
	int c;
	string s;

	cin >> c;
	getchar();
	getline(cin, s);
	while (c--) {
		int b = 0; // original file length
		map<string, int> files;
		vector<string> fragments;
		
		while (getline(cin, s), s != "") {
			b += s.length();
			fragments.push_back(s);
		}
		b /= (fragments.size() >> 1); // total fragments bits / file number
		for (size_t i = 0; i < fragments.size(); ++i) {
			for (size_t j = 0; j < fragments.size(); ++j) {
				if (i != j && fragments[i].length() + fragments[j].length() == b) {
					files[fragments[i] + fragments[j]]++;
					files[fragments[j] + fragments[i]]++;
				}
			}
		}

		cout << max_element(files.begin(), files.end(), cmp)->first << endl;
		if (c) cout << endl;
	}

	return 0;
}