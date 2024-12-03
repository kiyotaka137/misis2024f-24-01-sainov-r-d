#include<iostream>
#include<vector>
int main() {
	int x;
	int y = 0;
	std::cin >> x >> y;
	int value = abs(x) + abs(y);
	if (x > 0 && y > 0) {
		std::cout << 0 << " " << value << " " << value << " " << 0;
	}
	if (x < 0 && y>0) {
		std::cout << -value << " " << 0 << " " << 0 << " " << value;
	}
	if (x < 0 && y < 0) {
		std::cout << -value << " " << 0 << " " << 0 << " " << -value;
	}
	if (x > 0 && y < 0) {
		std::cout << 0 << " " << -value << " " << value << " " << 0;
	}
	return 0;
}