#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n;
		long long x;
		std::cin >> n >> x;
		long long a[n];
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		long long l = 0, h = 2000000000;
		while (l < h) {
			long long mid = l + (h - l + 1) / 2;
			long long level = 0;
			for (int i = 0; i < n; i++) {
				level += std::max(mid - a[i], 0LL);
			}
			if (level <= x) {
				l = mid;
			}
			else {
				h = mid - 1;
			}
		}
		std::cout << l << std::endl;

	}
	return 0;
}