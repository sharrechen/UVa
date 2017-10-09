#include <cmath>
#include <iostream>
using namespace std;

#define EPS 1e-7
int p, q, r, s, t, u;

float f(float x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

void bisection(float a, float b, float (*f)(float)) {
    float fa = f(a), fb = f(b), c, fc;
    if (fabs(fa) <= EPS) {
        cout << "0.0000" << endl;
    } else if (fabs(fb) <= EPS) {
        cout << "1.0000" << endl;
    } else if (fa * fb < 0) {
        while (b - a >= EPS) {
            c = (a + b) / 2.0;
            fc = f(c);
            if (fabs(fc) <= EPS) {
                break;
            } else if (fa * fc < 0) {
                b = c;
                fb = fc;
            } else {
                a = c;
                fa = fc;
            }
        }
        cout << c << endl;
    } else {
        cout << "No solution" << endl;
    }
}

int main(void) {
    cout.precision(4);
    cout.setf( ios::fixed, ios::floatfield );
    while (cin >> p >> q >> r >> s >> t >> u) {
        bisection(0.0, 1.0, f);
    }

    return 0;
}
