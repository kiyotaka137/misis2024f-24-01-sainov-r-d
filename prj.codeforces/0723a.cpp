#include<iostream>
#include<sstream>
#include<algorithm>
int main() {
	int x1, x2, x3;
	std::cin >> x1 >> x2 >> x3;
	int m = x1 + x2 + x3 - std::min(std::min(x1, x2), std::min(x1, x3)) - std::max(std::max(x1, x2), std::max(x1, x3));
	std::cout << abs(x1 - m) + abs(x2 - m) + abs(x3 - m);

}