#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>
bool exists(std::string s, std::vector<std::string>b) {
	for (int i = 0; i < size(b); i++) {
		if (b[i] == s) {
			return true;
		}
	}
	return false;
}
int main() {
	std::string slovo;
	int k = 0;
	int n = 0, m = 0;
	std::cin >> n >> m;
	std::vector<std::string> a;
	for (int i = 0; i < n; i++) {
		std::cin >> slovo;
		a.push_back(slovo);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> slovo;
		if (exists(slovo, a)) {
			k++;
		}
	}
	if (k % 2 == 1 and n >= m) {
		std::cout << "YES";
	}
	else if (k % 2 == 1 and n < m) {
		std::cout << "NO";
	}
	else if (k % 2 == 0 and n > m) {
		std::cout << "YES";
	}
	else if (k % 2 == 0 and n <= m) {
		std::cout << "NO";
	}
}