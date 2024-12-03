#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int n = 0;
	int num;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		if (num == 1) {
			std::cout << 1 << std::endl;
			continue;
		}
		std::cout << 10 * (num % 10 - 1) + (ceil(log10(num)) * ceil((log10(num)) + 1)) / 2 << std::endl;
	}
}