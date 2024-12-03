#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
int main() {
	int n, a, b, c;
	std::cin >> n;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (n == 1 || std::min(std::min(a, b), std::min(c, b)) == a || std::min(std::min(a, b), std::min(c, b)) == b) {
		std::cout << std::min(a, b) * (n - 1);
	}
	else {
		std::cout << std::min(a, b) + c * (n - 2);
	}
}