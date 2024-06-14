#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int M;
	cin >> M;
	vector<vector<int> > dp(n + 1, vector<int>(M + 1, 0));
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j - a[i] > 0)
				dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j] - dp[i][j - a[i] - 1];
			else
				dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j];
			dp[i + 1][j] %= M;
		}
	}
	cout << dp[n][m] << endl;
}
