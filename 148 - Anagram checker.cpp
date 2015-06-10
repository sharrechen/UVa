#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

map<string, string> dic;

void showAnagrams(const map<string, string>::iterator &dicIter,
                  const vector<string> &phrases,
                  const string &input, 
                  vector<string> &anagrams,
                  int &used) {

	if (used == ((1 << input.size()) - 1)) {
		copy(phrases.begin(), phrases.end(), ostream_iterator<string>(cout, " "));
		cout << "=";
		for (vector<string>::size_type i = 0; i < anagrams.size(); ++i) {
			cout << ' ' << anagrams[i];
		}
		cout << endl;
		return;
	}

	map<string, string>::iterator dt = dicIter;
	for (; dt != dic.end(); ++dt) {
		int mark = 0;
		for (size_t i = 0, k = 0; i < input.size(); ++i) {
			// check if bit i is used or not
			int bitI = used & ( 1 << i);
			if (bitI == 0 && input[i] == dt->second[k]) {
				// mark bit i to on
				mark |= 1 << i;
				if (k == dt->second.size() - 1 && 
					find(phrases.begin(), phrases.end(), dt->first) == phrases.end()) {
					// mark used bits
					used |= mark;
					anagrams.push_back(dt->first);
					showAnagrams(dt, phrases, input, anagrams, used);
					anagrams.pop_back();
					// unmark used bits for pop
					used &= ~mark;
					break;
				} else {
					++k;
				}
			} 
		}	
	}
}

int main(void) {
	string str;

	while (getline(cin, str) && str != "#") {
		string w = str;
		sort(str.begin(), str.end());
		dic[w] = str;
	}

	while (getline(cin, str) && str != "#") {
		string input = str;
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		sort(input.begin(), input.end());
		vector<string> phrases;
		stringstream ss(str);
		while (ss >> str) {
			phrases.push_back(str);
		}
		
		int used = 0;
		vector<string> anagrams;
		showAnagrams(dic.begin(), phrases, input, anagrams, used);
	}

	return 0;
}