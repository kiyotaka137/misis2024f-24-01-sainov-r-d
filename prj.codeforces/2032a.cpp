#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int n = 0;
	int t = 0;
	int num = 0;
	int count = 0;
	int c = 0;
	std::cin >> t;
	while (t--) {
		c = 0;
		count = 0;
		std::cin >> n;
		for (int i = 0; i < 2 * n; i++) {
			std::cin >> num;
			if (num == 1) {
				count++;
			}
			else { c++; }
		}
		if (count % 2 == 1) {
			std::cout << 1 << " " << std::min(count, c) << std::endl;
		}
		else {
			std::cout << 0 << " " << std::min(count, c) << std::endl;
		}
	}
}