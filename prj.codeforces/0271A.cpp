#include <iostream>
bool nice(int a) {
	int b = a % 10, c = (a % 100) / 10, d = (a % 1000) / 100, f = (a % 10000) / 1000;
	if (b != c && b != d && b != f && c != d && c != f && d != f) {
		return true;
	}
	return false;

}

int main()
{
	int x;
	std::cin >> x;
	for (int i = x + 1; i < 1000000; i++) {
		if (nice(i)) {
			std::cout << i;
			break;
		}

	}





}