#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
int main() {
	long long int answer = 0;
	int n = 0, m = 0;
	int xd = 0;
	std::cin >> n >> m;
	std::vector<int> a;
	for (int i = 0; i < m; i++) {
		std::cin >> xd;
		a.push_back(xd);
	}
	answer += a[0] - 1;
	for (int i = 0; i < m - 1; i++) {
		if (a[i + 1] > a[i]) {
			answer += a[i + 1] - a[i];
		}
		if (a[i + 1] == a[i]) {
			answer += 0;
		}
		if (a[i + 1] < a[i]) {
			answer += ((n - a[i]) + (a[i + 1]));
		}
	}
	std::cout << answer;
	return 0;
}