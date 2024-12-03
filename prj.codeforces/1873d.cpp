#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
int main() {
	int t = 0;
	int c = 0;
	std::cin >> t;
	std::string s;
	std::vector<int> white;
	std::vector<int> black;
	int argument = 0;
	int n = 0;
	int k = 0;
	int answer = 0;
	while (t--) {
		answer = 0;
		std::cin >> n >> k;
		std::cin >> s;
		for (int i = 0; i < size(s); i++) {
			if (s[i] == 'B') {
				answer += 1;
				i += k - 1;
			}

		}
		std::cout << answer << std::endl;
	}
	return 0;
}