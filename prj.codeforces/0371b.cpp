#include<iostream>
#include<sstream>
#include<algorithm>
int main() {
	int a, b;
	std::cin >> a >> b;
	int a2 = 0, a3 = 0, a5 = 0;
	int b2 = 0, b3 = 0, b5 = 0;
	if (a == b) {
		std::cout << 0;
		return 0;
	}
	while (a % 2 == 0) {
		a2++;
		a /= 2;
	}
	while (a % 3 == 0) {
		a3++;
		a /= 3;
	}
	while (a % 5 == 0) {
		a5++;
		a /= 5;
	}
	while (b % 2 == 0) {
		b2++;
		b /= 2;
	}
	while (b % 3 == 0) {
		b3++;
		b /= 3;
	}
	while (b % 5 == 0) {
		b5++;
		b /= 5;
	}
	if (a != b) {
		std::cout << -1;
		return 0;
	}
	std::cout << abs(a2 - b2) + abs(a3 - b3) + abs(a5 - b5);
}