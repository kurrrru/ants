#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i + 1][j + 1] = max(dp[i][j] + (s[i] == t[j]), max(dp[i][j + 1], dp[i + 1][j]));
		}
	}
	cout << dp[n][m] << endl;
}
