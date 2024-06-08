#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k;
	cin >> k;
	for (int i = 0; i < (1 << n); i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				sum += a[j];
		if (sum == k)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return (0);
}
