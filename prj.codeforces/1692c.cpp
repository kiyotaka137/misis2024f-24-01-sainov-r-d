#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		char a[9][9];
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				std::cin >> a[i][j];
			}
		}
		for (int i = 2; i <= 7; i++) {
			for (int j = 2; j <= 7; j++) {
				if (a[i + 1][j + 1] == '#' and a[i - 1][j - 1] == '#' and a[i + 1][j - 1] == '#' and a[i - 1][j + 1] == '#') {
					std::cout << i << " " << j << std::endl;
					break;
				}
			}
		}
	}
}