#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	long long int n = 0;
	long long int a, b;
	std::cin >> n;
	std::cin >> a;
	std::cin >> b;
	for (long long int x = 0; x <= n; x++) {
		if ((n - a * x) >= 0 && (n - a * x) % b == 0) {
			std::cout << "YES" << std::endl;
			std::cout << x << " " << (n - a * x) / b;
			return 0;
		}
	}
	std::cout << "NO";
}