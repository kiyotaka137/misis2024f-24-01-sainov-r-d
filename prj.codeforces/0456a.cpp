#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
int main() {
	int n = 0;
	std::cin >> n;
	int indexn, kachestvo;
	int mx = 0;
	std::vector<int>a(n + 1);
	for (int i = 0; i < n; i++) {
		std::cin >> indexn >> kachestvo;
		a[indexn] = kachestvo;
	}
	mx = a[0];
	for (int j = 1; j < n + 1; j++) {
		if (a[j] < mx) {
			std::cout << "Happy Alex";
			return 0;
		}
		else {
			mx = a[j];
		}
	}
	std::cout << "Poor Alex";
}