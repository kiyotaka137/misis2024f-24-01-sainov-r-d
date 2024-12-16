#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int n;
	std::string last;
	std::string num;
	std::cin >> n;
	int c = 0;
	std::cin >> last;
	for (int i = 1; i < n; i++) {
		std::cin >> num;
		if (num[0] == last[1]) {
			c++;
		}
		last = num;
	}
	std::cout << c + 1;
}