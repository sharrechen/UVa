#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int k;
    
    cin >> k;
    while (k) {
        vector<int> S(k);
        for (size_t i = 0; i < k; ++i) {
            cin >> S[i];
        }

        for (size_t a = 0; a < k - 5; ++a)
            for (size_t b = a + 1; b < k - 4; ++b)
                for (size_t c = b + 1; c < k - 3; ++c)
                    for (size_t d = c + 1; d < k - 2; ++d)
                        for (size_t e = d + 1; e < k - 1; ++e)
                            for (size_t f = e + 1; f < k; ++f)
                                cout << S[a] << " " << S[b] << " " << S[c] << " " << S[d] << " " << S[e] << " " << S[f] << endl;

        cin >> k;
        if (k) cout << endl;
    }

    return 0;
}