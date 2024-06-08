#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int coin[6] = {1, 5, 10, 50, 100, 500};
	vector<int> C(6);
	for (int i = 0; i < 6; i++)
		cin >> C[i];
	int A;
	cin >> A;
	int ans = 0;
	for (int i = 5; i >= 0; i--)
	{
		int t = min(A / coin[i], C[i]);
		A -= t * coin[i];
		ans += t;
	}
	cout << ans << endl;
}
