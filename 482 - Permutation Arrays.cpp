#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef struct {
    int order;
    string data;
} P;

struct comparator {
    bool operator () (const P& x, const P& y) {
        return x.order < y.order ? true : false;
    }
} cmp;

void strToVector(string str1, string str2, vector<P> & v) {
    int i;
    string num;

    stringstream ss(str1);
    stringstream dd(str2);
    while (ss >> i) {
        dd >> num;
        P one;
        one.order = i;
        one.data = num;
        v.push_back(one);
    }

    return;
}

int main(void) {
    bool isNotFirst = false;
    int t;
    string index, content;

    cin >> t;
    cin.ignore();
    while (t--) {
        cin.ignore();
        getline(cin, index);
        getline(cin, content);

        vector<P> reorder;
        strToVector(index, content, reorder);
        sort(reorder.begin(), reorder.end(), cmp);

        if (isNotFirst) cout << endl;
        isNotFirst = true;
        for (int i = 0; i < reorder.size(); ++i) {
            cout << reorder[i].data << endl;
        }
    }

    return 0;
}