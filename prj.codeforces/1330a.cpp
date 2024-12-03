#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> res(500);
	for (int i = 0; i < n; ++i)
		res[a[i] - 1] = 1;
	for (int i = 0; i < res.size() && x > 0; ++i)
		if (!res[i]) {
			res[i] = 1;
			--x;
		}
	for (int i = 0; i < res.size(); ++i)
		if (!res[i]) {
			cout << i << endl;
			return;
		}
	cout << res.size() << endl;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
	return 0;
}