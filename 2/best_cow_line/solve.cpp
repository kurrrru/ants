#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N;
	string S, T;
	cin >> N >> S;
	T = S;
	reverse(T.begin(), T.end());
	string ans;
	for (int i = 0, j = 0; i + j < N;)
	{
		if (S.substr(i) <= T.substr(j))
			ans += S[i++];
		else
			ans += T[j++];
	}
	cout << ans << endl;
}
