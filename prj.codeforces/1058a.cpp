#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int n = 0;
	std::cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		if (num == 1) {
			std::cout << "HARD";
			return 0;
		}
	}
	std::cout << "EASY";
}