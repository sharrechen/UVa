#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
	string hello;
	unordered_map<string, string> language = {
		{"HELLO", "ENGLISH"},
		{"HOLA", "SPANISH"},
		{"HALLO", "GERMAN"},
		{"BONJOUR", "FRENCH"},
		{"CIAO", "ITALIAN"},
		{"ZDRAVSTVUJTE", "RUSSIAN"}
	};
	unordered_map<string, string>::const_iterator it;
	
	int i = 1;
	while (cin >> hello && hello.compare("#")) {
		it = language.find(hello);
		if (it != language.end()) {
			cout << "Case " << i++ << ": " << it->second <<endl;
		} else {
			cout << "Case " << i++ << ": UNKNOWN" <<endl; 
		}
	}
	return 0;
}