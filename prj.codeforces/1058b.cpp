#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int n = 0;
	int d = 0;
	int t = 0;
	int x = 0, y = 0;
	std::cin >> n >> d;
	std::cin >> t;
	int num;
	for (int i = 0; i < t; i++) {
		std::cin >> x >> y;
		if (x - y >= -d and x - y <= d and x + y <= 2 * n - d and x + y >= d) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}

}