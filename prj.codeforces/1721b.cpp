#include<iostream>
#include<vector>
int main() {
	int t = 0;
	std::cin >> t;
	int n = 0, m = 0, sx = 0, sy = 0, d = 0;
	while (t--) {
		std::cin >> n >> m >> sy >> sx >> d;
		if (!(sx - d <= 1 || sy + d >= n) || !(sx + d >= m || sy - d <= 1)) {
			std::cout << n + m - 2 << std::endl;
		}
		else {
			std::cout << -1 << std::endl;
		}
	}

}