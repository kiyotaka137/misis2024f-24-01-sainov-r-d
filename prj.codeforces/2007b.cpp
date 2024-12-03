#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
int main() {
	int t = 0;
	int chislo = 0;
	int l = 0, r = 0;
	char sign;
	int n = 0, m = 0;
	int mx = -1000000;
	std::cin >> t;
	while (t--) {
		mx = 0;
		std::cin >> n >> m;
		for (int i = 0; i < n; i++) {
			std::cin >> chislo;
			if (mx < chislo) {
				mx = chislo;
			}
		}
		for (int i = 0; i < m; i++) {
			std::cin >> sign >> l >> r;
			if (sign == '+') {
				if (mx >= l and mx <= r) {
					mx += 1;
				}
			}
			if (sign == '-') {
				if (mx >= l and mx <= r) {
					mx -= 1;
				}
			}
			std::cout << mx << " ";
		}
		std::cout << std::endl;
	}
}