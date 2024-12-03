#include<iostream>
#include<vector>
int main() {
	int n = 0;
	int paket = 0;
	int summa = 0;
	int c = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> paket;
		if (paket % 2 == 1) {
			c++;
		}
		summa += paket;
	}
	if (summa % 2 == 1) {
		std::cout << c;
	}
	else {
		std::cout << n - c;
	}
	return 0;
}