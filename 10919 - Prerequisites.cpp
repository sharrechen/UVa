#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	unsigned int ncourse, ncategories, cInc, min, lesson, have;
	vector<int> taken(100);
	bool pass;
	while (cin >> ncourse >> ncategories, ncourse) {
		pass = true;
		for (int i = 0; i < ncourse; i++) {
			cin >> taken[i];
		}
		sort(taken.begin(), taken.begin() + ncourse);
		while (ncategories--) {
			cin >> cInc >> min;
			have = 0;
			while (cInc--) {
				cin >> lesson;
				if (find(taken.begin(), taken.begin() + ncourse, lesson) != taken.begin() + ncourse)
					have++;
			}
			if (have < min) pass = false;
		}
		if (pass) cout << "yes"<<endl;
		else cout << "no" <<endl;
		taken.clear();
	}
}