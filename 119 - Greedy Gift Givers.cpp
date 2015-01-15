#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main(void) {
	unsigned int p;
	char group[10][16], who[16], whom[16];
	int worth[10] = {}, money, n;
	map<string, int> people;
	bool line = 1;

	while (cin >> p) {
		for (int i = 0; i < p; i++) {
			cin >> group[i];
			people.insert(pair<string, int>(group[i], i));
		}
		for (int i = 0; i < p; i++) {
			cin >> who >> money >> n;
			
			if (n > 0) {
				worth[people[who]] -= money;
				worth[people[who]] += money%n;
			}
			for (int j = 0; j < n; j++) {
				cin >> whom;
				worth[people[whom]] += money/n;
			}
		}
		cout << (line ? "" : "\n");
		for (int i = 0; i < p; i++) {
			cout << group[i] << " " << worth[i] <<endl;
		}
		line = 0;
		memset(worth, 0, sizeof(worth));
		people.clear();
	}
	return 0;
}