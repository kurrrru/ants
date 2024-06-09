#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N;
	cin >> N;
	vector<int> L(N);
	for (int i = 0; i < N; i++)
		cin >> L[i];
	priority_queue<int, vector<int>, greater<int>> que(L.begin(), L.end());
	ll ans = 0;
	while (que.size() > 1)
	{
		int l1 = que.top();
		que.pop();
		int l2 = que.top();
		que.pop();
		ans += l1 + l2;
		que.push(l1 + l2);
	}
	cout << ans << endl;
}
