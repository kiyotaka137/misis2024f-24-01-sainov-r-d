#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int n = 0;
	std::cin >> n;
	int a = (n / 10) * 10;
	int b = a + 10;
	if (n - a > b - n) {
		std::cout << b;
	}
	else {
		std::cout << a;
	}
}