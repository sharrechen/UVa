#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	static const char keys[] = {'`', '1', '2', '3', '4', '5',
                				'6', '7', '8', '9', '0', '-',
                           		'=', 'Q', 'W', 'E', 'R', 'T', 
                           		'Y', 'U', 'I', 'O', 'P', '[',
                           		']', '\\', 'A', 'S', 'D', 'F',
                           		'G', 'H', 'J', 'K', 'L', ';',
                           		'\'', 'Z', 'X', 'C', 'V', 'B',
                           		'N', 'M', ',', '.', '/'};
  	vector<char> keyboard(keys, keys + sizeof(keys) / sizeof(keys[0]));
	vector<char>::iterator ctr;
	string line;
	while (getline(cin, line)) {
		for (size_t w = 0; w < line.size(); ++w) {
			if (line[w] == ' ') {
				cout << " ";
			} else {
				ctr = find(keyboard.begin(), keyboard.end(), line[w]);
				if (ctr != keyboard.end()) {
					cout << *(ctr - 1);
				}
			}
		}
		cout << endl;
	}
	
	return 0;
}