#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
int main() {
	int n = 0;
	int k = 0;
	std::string snew = "";
	std::cin >> n >> k;
	std::string s = "";
	std::cin >> s;
	int ended = 0;
	int i = 0;
	if (k == 0) {
		std::cout << s;
		return 0;
	}
	if (s.size() == 1) {
		std::cout << 0;
		return 0;
	}
	if (s[0] != '1') {
		snew += "1";//k=8 snew = 1
		k--;
	}
	else {
		snew += "1";
	}
	for (i=1; k > 0 && i < n; i++) {
		
		if (s[i] != '0') {
			snew += "0";
			k--;
		}
		else {
			snew += "0";
		}
		ended = i;
	}
	if (ended != n) {
		for (int j = ended+1; j < s.size(); j++) {
			snew += s[j];
		}
	}
	std::cout << snew;
	return 0;
}
