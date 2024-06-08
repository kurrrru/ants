#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll L, n;
	cin >> L >> n;
	vector<ll> x(n);
	ll min_t = 0, max_t = 0;
	for (int i = 0; i < n; i++) 
	{
		cin >> x[i];
		min_t = max(min_t, min(x[i], L - x[i]));
		max_t = max(max_t, max(x[i], L - x[i]));
	}
	cout << min_t << " " << max_t << endl;
}
