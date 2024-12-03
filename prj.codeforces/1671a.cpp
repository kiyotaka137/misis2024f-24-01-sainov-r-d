#include <iostream>
#include<vector>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		std::string s;
		std::cin >> s;
		int flag = 0;
		if (size(s) == 1) {
			std::cout << "NO" << std::endl;
			continue;
		}
		for (int i = 1; i < size(s) - 1; i++) {
			if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
				std::cout << "NO" << std::endl;
				flag = 1;
				break;
			}
		}
		if (((s[0] != s[1]) || (s[size(s) - 1] != s[size(s) - 2])) && flag != 1) {
			std::cout << "NO" << std::endl;
			continue;
		}
		if (flag == 0) {
			std::cout << "YES" << std::endl;
		}
	}
}
