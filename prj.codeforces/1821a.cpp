#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		std::string s;
		std::cin >> s;
		int count = std::count(s.begin(), s.end(), '?');
		if (std::count(s.begin(), s.end(), '?') > 0) {
			if (s[0] == '0') {
				std::cout << 0 << std::endl;
				continue;
			}
			if (s[0] == '?') {
				std::cout << 9 * pow(10, count - 1) << std::endl;
			}
			else {
				std::cout << pow(10, count) << std::endl;
			}
		}
		else {
			if (s[0] == '0') {
				std::cout << 0 << std::endl;
			}
			else {
				std::cout << 1 << std::endl;
			}
		}
	}
	return 0;
}