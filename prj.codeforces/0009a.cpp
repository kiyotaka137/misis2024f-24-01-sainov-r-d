#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int a, b;
	std::cin >> a >> b;
	int mx = -1;
	mx = std::max(a, b);
	if (mx == 1) {
		std::cout << 1 << "/" << 1;
		return 0;
	}
	int p = 6 - mx + 1;
	if (p % 3 == 0) {
		std::cout << p / 3 << "/" << 2;
		return 0;
	}
	if (p % 2 == 0) {
		std::cout << p / 2 << "/" << 3;
	}
	else {
		std::cout << p << "/" << 6;
	}
}
