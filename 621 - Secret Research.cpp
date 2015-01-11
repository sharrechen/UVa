#include <iostream>
#include <string>
#include <regex>
// #include <boost/regex.hpp>

// using namespace boost;
using namespace std;

int main(void) {
	unsigned T;
	string s;
	regex po("(1|4|78)");
	regex ne(".*35");
	regex fe("9.*4");
	regex ncom("^190.*");
	
	cin >> T;
	while (T--) {
		cin >> s;
		if (regex_match(s, po)) {
			cout << "+" <<endl;
		} else if (regex_match(s, ne)) {
			cout << "-" <<endl;
		} else if (regex_match(s, fe)) {
			cout << "*" <<endl;
		} else if (regex_match(s, ncom)) {
			cout << "?" <<endl;
		}
	}
	return 0;
}