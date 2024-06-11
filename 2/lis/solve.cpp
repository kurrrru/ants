#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x: a)
		cin >> x;
	const int inf = 1 << 30;
	vector<int> dp(n, inf);
	for (auto x: a)
		*lower_bound(dp.begin(), dp.end(), x) = x;
	cout << lower_bound(dp.begin(), dp.end(), inf) - dp.begin() << endl;
}
