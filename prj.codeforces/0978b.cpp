#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
int main() {
	int n = 0;
	int c = 0;
	int answer = 0;
	std::string s = "";
	std::cin >> n;
	std::cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') {
			c++;
		}
		else {
			if (c >= 3) {
				answer += c - 2;
			}
			c = 0;
		}
	}
	if (c >= 3) {
		answer += c - 2;
	}
	std::cout << answer;
	return 0;
}
