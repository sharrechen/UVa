#include <iostream>

using namespace std;

int main(void) {
	unsigned int T, farmer, size, animals, envfriend, burden;

	cin >> T;
	while (T--) {
		burden = 0;
		cin >> farmer;
		while (farmer--) {
			cin >> size >> animals >> envfriend;
			burden += size * envfriend;
		}
		cout << burden <<endl;
	}

	return 0;
}