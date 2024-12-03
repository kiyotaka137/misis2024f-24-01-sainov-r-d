#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
int main() {
	int n, k, m;
	int p;
	std::cin >> n >> k >> m;
	std::vector<std::vector<int>>b(m);
	std::vector<int>a;
	for (int i = 0; i < n; i++) {
		std::cin >> p;
		a.push_back(p);
		b[p % m].push_back(p);
	}
	for (int i = 0; i < m; i++) {
		if (size(b[i]) >= k) {
			std::cout << "Yes" << std::endl;
			for (int j = 0; j < k; j++) {
				std::cout << b[i][j] << " ";
			}
			return 0;
		}
	}
	std::cout << "No";
	return 0;
}
