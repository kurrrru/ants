#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind{
    vector<int> p;
    vector<int> r;
    UnionFind(int n){
        p.resize(n,-1);
        r.resize(n,1);
    }

    int find(int x){
        if (p[x] == -1) return x;
        else return p[x] = find(p[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (r[x] > r[y]) swap(x, y);
        if (r[x] == r[y]) r[y]++;
        p[x] = y;
    }
};

int main()
{
	int N, K;
	cin >> N >> K;
	UnionFind uf(3 * N);
	int ans = 0;
	for (int i = 0; i < K; i++)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
		{
			if (uf.find(x) == uf.find(y + N) || uf.find(x) == uf.find(y + 2 * N))
			{
				ans++;
			}
			else
			{
				uf.unite(x, y);
				uf.unite(x + N, y + N);
				uf.unite(x + 2 * N, y + 2 * N);
			}
		}
		else if (t == 2)
		{
			if (uf.find(x) == uf.find(y) || uf.find(x) == uf.find(y + 2 * N))
			{
				ans++;
			}
			else
			{
				uf.unite(x, y + N);
				uf.unite(x + N, y + 2 * N);
				uf.unite(x + 2 * N, y);
			}
		}
	}
	cout << ans << endl;
}
