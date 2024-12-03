#include<iostream>
#include<sstream>
#include<algorithm>
int main() {
	int t = 0;
	std::cin >> t;
	int dab, dac, dbc;
	int xa, ya, xb, yb, xc, yc;
	while (t--) {
		std::cin >> xa >> ya;
		std::cin >> xb >> yb;
		std::cin >> xc >> yc;
		dab = abs(xa - xb) + abs(ya - yb);
		dac = abs(xa - xc) + abs(ya - yc);
		dbc = abs(xc - xb) + abs(yc - yb);
		std::cout << (dab + dac - dbc) / 2 + 1 << std::endl;
	}
}