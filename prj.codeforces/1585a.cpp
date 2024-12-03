#include <iostream>
#include<vector>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		int num = 0;
		std::cin >> n;
		if (n == 1) {
			std::cin >> num;
			std::cout << num + 1 << std::endl;
			continue;
		}
		std::vector<int>a(n);
		int flag = 0;
		int flower = 1;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			if (flag != 1 && i != 0 && a[i - 1] == 0 && a[i] == 0) {
				std::cout << -1 << std::endl;
				flag = 1;
			}
			if (i != 0 && a[i] == 1 && a[i - 1] != 1) {
				flower += 1;
			}
			if (i == 0 && a[i] == 1) {
				flower += 1;
			}
			if (i != 0 && a[i - 1] == 1 && a[i] == 1) {
				flower += 5;
			}
		}
		if (flag == 0) {
			std::cout << flower << std::endl;
		}
	}
}
