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
	vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (j < w[i])
				dp[i + 1][j] = dp[i][j];
			else
				dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= W; i++)
		ans = max(ans, dp[n][i]);
	cout << ans << endl;
}
