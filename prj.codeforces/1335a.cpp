#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	long long int n = 0;
	long long int num = 0;
	std::cin >> n;
	for (long long int i = 0; i < n; i++) {
		std::cin >> num;
		std::cout << (num - 1) / 2 << std::endl;

	}
}