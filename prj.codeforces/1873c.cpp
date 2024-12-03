#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
int main() {
	int t = 0;
	int c = 0;
	int i1 = 0, j1 = 0;
	std::cin >> t;
	char n;
	while (t--) {
		c = 0;
		for (int i = 1; i < 11; i++) {
			for (int j = 1; j < 11; j++) {
				std::cin >> n;
				if (n == 'X') {
					if (i > 5) {
						i1 = 11 - i;
					}
					else {
						i1 = i;
					}
					if (j > 5) {
						j1 = 11 - j;
					}
					else {
						j1 = j;
					}
					c += std::min(i1, j1);

				}
			}
		}
		std::cout << c << std::endl;
	}
	return 0;
}