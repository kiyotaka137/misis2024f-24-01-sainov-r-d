#include <iostream>
#include<cmath>
 
int main() {
	int n = 0;
	int a = 0, b = 0, c = 0;
	std::cin >> n;
	while (n--) {
		std::cin >> a >> b >> c;
		if (a - b == 0) {
			std::cout << 0 << std::endl;
			continue;
		if (c > abs(a - b)) {
			std::cout << 1 << std::endl;
			continue;
		}
		
		}
		std::cout << ceil((abs(b - a) / double(c))/2.) << std::endl;
	}
 
	
	return 0;
}
