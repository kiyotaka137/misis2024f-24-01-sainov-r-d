#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
int main() {
	int k2, k3, k5, k6;
	std::cin >> k2 >> k3 >> k5 >> k6;
	int summa = 0;
	summa += (std::min(std::min(k2, k5), std::min(k5, k6))) * 256;
	k2 -= std::min(std::min(k2, k5), std::min(k5, k6));
	k5 -= std::min(std::min(k2, k5), std::min(k5, k6));
	k6 -= std::min(std::min(k2, k5), std::min(k5, k6));
	summa += 32 * (std::min(k2, k3));
	std::cout << summa;
	return 0;
}