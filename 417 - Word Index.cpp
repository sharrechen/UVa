#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void combination(vector<char> & alphabet, map<string, int> & words, int m, int n) {
    string charmask(n, 1); // set leading n to 1
    charmask.resize(m, 0); // set rest n+1 ~ m to 0
    do {
        string s;
        for (size_t i = 0; i < m; ++i) {
            if (charmask[i]) {
                s.push_back(alphabet[i]);
            }
        }
        words.insert(pair<string, int>(s, words.size() + 1));
    } while (prev_permutation(charmask.begin(), charmask.end()));
}

int main(void) {
    vector<char> alphabet;
    map<string, int> words;
    
    for (char c = 'a'; c <= 'z'; ++c) {
        alphabet.push_back(c);
    }

    // generate words position index
    for (int i = 1; i <= 5; ++i) {
        combination(alphabet, words, 26, i);
    }

    string s;
    while (cin >> s) {
        cout << words[s] << endl;
    }

    return 0;
}
