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
	vector<vector<int>> dp(n + 1, vector<int>(n * 100 + 1, 1 << 30));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 100 + 1; j++)
		{
			if (j < v[i])
				dp[i + 1][j] = dp[i][j];
			else
				dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
		}
	}
	int ans = upper_bound(dp[n].begin(), dp[n].end(), W) - dp[n].begin() - 1;
	cout << ans << endl;
}
