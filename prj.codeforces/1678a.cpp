#include <iostream>
#include<vector>
#include<algorithm>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int c = 0;
		int n = 0;
		bool flag = false;
		std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		c = count(a.begin(), a.end(), 0);
		if (c > 0) {
			std::cout << n - c << std::endl;
		}
		else {
			for (int i = 1; i < n; i++) {
				if (a[i] == a[i - 1]) {
					flag = true;
				}
			}
			if (flag) {
				std::cout << n << std::endl;
			}
			else {
				std::cout << n + 1 << std::endl;
			}
		}


	}

}
