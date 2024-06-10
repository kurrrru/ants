#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), m(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> m[i];
	int K;
	cin >> K;
	vector<vector<int>> dp(n + 1, vector<int>(K + 1, -1));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (dp[i][j] != -1)
				dp[i + 1][j] = m[i];
			else if (j >= a[i] && dp[i + 1][j - a[i]] > 0)
				dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
			else
				dp[i + 1][j] = -1;
		}
	}
	if (dp[n][K] >= 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
