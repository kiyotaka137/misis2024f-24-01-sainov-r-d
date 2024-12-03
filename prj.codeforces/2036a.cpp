#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>
bool proverka(int n, std::vector<int> a) {
	for (int i = 0; i < n - 1; i++) {
		if (abs(a[i] - a[i + 1]) != 5 && abs(a[i] - a[i + 1]) != 7) {
			return false;
		}
	}
	return true;
}
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		std::vector<int>a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		if (proverka(n, a)) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}