#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; i++)
		cin >> w[i] >> v[i];
	int W;
	cin >> W;
	vector<int> dp(W + 1, 0);
	for (int i = 0; i < n; i++)
		for (int j = w[i]; j <= W; j++)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[W] << endl;
}
