#include <iostream>
#include <bitset>
using namespace std;

int main(void) {
    int input;
    bitset<32> b1((256 - 1) << 24); // 0xFF000000
    bitset<32> b2((256 - 1) << 16); // 0x00FF0000
    bitset<32> b3((256 - 1) << 8);  // 0x0000FF00
    bitset<32> b4(256 - 1);         // 0x000000FF
    while (cin >> input) {
        bitset<32> integer(input);
        bitset<32> other = ((integer & b1) >> 24 |
                            (integer & b4) << 24 |
                            (integer & b2) >> 8 |
                            (integer & b3) << 8);
        cout << input << " converts to " << (int)other.to_ulong() << endl;
    }
    return 0;
}
