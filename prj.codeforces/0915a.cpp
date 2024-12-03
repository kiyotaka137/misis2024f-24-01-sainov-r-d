#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int n, k;
	std::cin >> n >> k;
	int num;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		if (k % num == 0 and num > mx) {
			mx = num;
		}
	}
	std::cout << k / mx;

}