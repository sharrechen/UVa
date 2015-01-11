#include <iostream>

using namespace std;

int main(void) {
	unsigned int participants, budget, hotels,
				 weeks, price, beds, min_money;

	while (cin >> participants >> budget >> hotels >> weeks) {
		min_money = budget + 1;
		while (hotels--) {
			cin >> price;
			for (int i = 0; i < weeks; i++) {
				cin >> beds;
				if (beds >= participants && participants * price < min_money) {
					min_money = participants * price;
				}
			}
		}
		if (min_money == budget + 1) cout << "stay home" <<endl;
		else cout << min_money <<endl;
	}

	return 0;
}