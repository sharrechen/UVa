#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<string, int> PAIR;

int main(void) {
	unsigned int T, rel, max, c=1;
	string url;
	vector<PAIR> rank(10);
	vector<PAIR>::iterator it;
	
	cin >> T;
	while (T--) {
		max = 0;
		for (int i = 0; i < 10; i++) {
			cin >> url >> rel;
			rank.push_back(make_pair(url, rel));
			if (max < rel) max = rel;
		}
		
		cout << "Case #" << c++ << ":" <<endl;
		for (it = rank.begin(); it != rank.end(); ++it) {
			if (it->second == max)
				cout << it->first <<endl;
		}
		rank.clear();
	}
	
	return 0;
}