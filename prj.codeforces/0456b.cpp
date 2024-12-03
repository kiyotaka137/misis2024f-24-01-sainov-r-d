#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
int main() {
	std::string n;
	std::cin >> n;
	int k = 0;
	if (size(n) > 3) {
		std::string substr = n.substr(size(n) - 2, 2);
		k = stoi(substr);
	}
	else {
		k = stoi(n);
	}
	if (k % 4 == 0) {
		std::cout << 4;
	}
	else {
		std::cout << 0;
	}
}