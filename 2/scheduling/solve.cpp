#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int> > task(N);
	for (int i = 0; i < N; i++)
		cin >> task[i].second >> task[i].first;
	sort(task.begin(), task.end());
	ll ans = 0;
	ll t = 0;
	for (int i = 0; i < N; i++)
	{
		if (t < task[i].second)
		{
			t = task[i].first;
			ans++;
		}
	}
	cout << ans << endl;
}
