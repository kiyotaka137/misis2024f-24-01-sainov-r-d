#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int answer = 0;
		int n, k;
		int ind, element;
		int mxind = -1;
		std::cin >> n >> k;
		std::vector<int>a(k + 1, 0);
		for (int i = 0; i < k; i++) {
			std::cin >> ind >> element;
			mxind = std::max(ind, mxind);
			a[ind] += element;
		}
		std::sort(a.begin(), a.end());
		if (n <= k) {
			for (int i = 0; i < n; i++) {
				answer += a[k - i];
			}
		}
		else {
			for (int i = 0; i < size(a); i++) {
				answer += a[i];
			}
		}
		std::cout << answer << std::endl;
	}
}