#include <iostream>
#include<cmath>
int main() {
	long long n = 0, a = 0, b = 0;
	std::cin >> n;
	while (n--) {
		std::cin >> a >> b;
		long long s = (std::ceil(abs(a - b) / 10.));
		std::cout << s<< std::endl;
	}
	
	return 0;
}
