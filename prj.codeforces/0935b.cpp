#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int n = 0;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int answer = 0;
	int c = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'R') {
			c--;
		}
		if (s[i] == 'U') {
			c++;
		}
		if (c == 0 and s[i] == s[i + 1]) {
			answer++;
		}
	}
	std::cout << answer;
}