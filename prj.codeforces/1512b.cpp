#include <iostream>
#include<vector>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		int c = 0;
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		std::cin >> n;
		std::vector<std::vector<char>> a(n, std::vector<char>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> a[i][j];
				if (a[i][j] == '*' and c == 0) {
					x1 = i;
					y1 = j;
					c++;
				}
				if (a[i][j] == '*' and c == 1) {
					x2 = i;
					y2 = j;
				}
			}
		}
		if (x1 == x2 and x1 != n - 1) {
			a[x1 + 1][y1] = '*';
			a[x2 + 1][y2] = '*';
		}
		else if (x1 == x2) {
			a[x1 - 1][y1] = '*';
			a[x2 - 1][y2] = '*';
		}
		if (y1 == y2 and y1 != n - 1) {
			a[x1][y1 + 1] = '*';
			a[x2][y2 + 1] = '*';
		}
		else if (y1 == y2) {
			a[x1][y1 - 1] = '*';
			a[x2][y2 - 1] = '*';
		}
		if (x1 != x2 and y1 != y2) {
			a[x1][y2] = '*';
			a[x2][y1] = '*';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << a[i][j];
			}
			std::cout << std::endl;
		}
		a.clear();
	}
}
