#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int n, k;
	std::cin >> n >> k;
	int mainpers = 0;
	int c = 0;
	int num;
	std::vector<int> a;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		if (i == k - 1) {
			mainpers = num;
		}
		a.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] >= mainpers and a[i] != 0) {
			c++;
		}
	}
	std::cout << c;
}