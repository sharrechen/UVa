#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int up,
		down,
		north,
		south,
		west,
		east;
} Die;

Die d;

int main(void) {
	int ncommand;
	char command[16];

	while (cin >> ncommand, ncommand) {
		d.up = 1,
		d.north = 2,
		d.west = 3,
		d.east = 4,
		d.south = 5,
		d.down = 6;
		while (ncommand--) {
			cin >> command;
			if (command[0] == 'n') {
				swap(d.north, d.up);
				swap(d.up, d.south);
				swap(d.south, d.down);
			} else if (command[0] == 's') {
				swap(d.south, d.up);
				swap(d.up, d.north);
				swap(d.north, d.down);
			} else if (command[0] == 'w') {
				swap(d.west, d.up);
				swap(d.up, d.east);
				swap(d.east, d.down);
			} else if (command[0] == 'e') {
				swap(d.east, d.up);
				swap(d.up, d.west);
				swap(d.west, d.down);
			}
		}
		cout << d.up <<endl;
	}

	return 0;
}