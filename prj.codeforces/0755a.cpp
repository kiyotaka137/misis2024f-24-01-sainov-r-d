#include <iostream>
#include<vector>
#include <string>
#include<algorithm>
#include<cmath>
bool simplenum(int x) {
	for (int i = 2; i < int(sqrt(x)) + 1; i++) {
		if (x % i == 0) {
			return true;
		}
	}
	return false;
}
int main() {
	int n = 0;
	std::cin >> n;
	for (int m = 1; m <= 1000; m++) {
		if (simplenum(m * n + 1)) {
			std::cout << m;
			return 0;
		}
	}

}