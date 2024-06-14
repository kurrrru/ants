#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N, L, P;
	cin >> N >> L >> P;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	vector<int> B(N);
	for (int i = 0; i < N; i++)
		cin >> B[i];
	priority_queue<int, vector<int>, less<int>> que;
	int ans = 0;
	int fuel = P;
	int pos = 0;
	A.push_back(L);
	B.push_back(0);
	for (int i = 0; i <= N; i++)
	{
		while (!que.empty() && fuel < A[i] - pos)
		{
			fuel += que.top();
			que.pop();
			ans++;
		}
		if (fuel < A[i] - pos)
		{
			cout << -1 << endl;
			return 0;
		}
		fuel -= A[i] - pos;
		pos = A[i];
		que.push(B[i]);
	}
	cout << ans << endl;
	return (0);
}
