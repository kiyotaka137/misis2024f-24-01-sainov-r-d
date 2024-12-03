#include <iostream>
#include<vector>
#include <string>
int summacifr(int x) {
	int c = 0;
	while (x != 0) {
		c += x % 10;
		x /= 10;
	}
	return c;
}
int main() {
	int n;
	std::cin >> n;
	std::vector<int>a;
	for (int i = 0; i < 100; i++) {
		if (i == summacifr(n - i)) {
			a.push_back(n - i);
		}
	}
	std::cout << a.size() << std::endl;
	for (int i = a.size() - 1; i >= 0; i--) {
		std::cout << a[i] << std::endl;
	}
}