#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N, R;
	cin >> N >> R;
	vector<int> X(N);
	for (int i = 0; i < N; i++)
		cin >> X[i];
	sort(X.begin(), X.end());
	int ans = 1, dot = X[0], left_most = X[0];
	for (int i = 1; i < N; i++)
	{
		if (left_most + R >= X[i])
			dot = X[i];
		else if (dot + R >= X[i])
			continue;
		else
		{
			ans++;
			left_most = X[i];
			dot = X[i];
		}
	}
	cout << ans << endl;
}
