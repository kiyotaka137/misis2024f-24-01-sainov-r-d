#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>
int main() {
	int n = 0;
	std::cin >> n;
	if (n % 2 == 0) {
		std::cout << pow(n, 2) / 2 << std::endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 2 == 0) {
					std::cout << "C";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << (pow(n, 2) + 1) / 2 << std::endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 2 == 0) {
					std::cout << "C";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}
	}
}