#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind{
	vector<int> p;
	vector<int> r;
	UnionFind(int n){
		p.resize(n, -1);
		r.resize(n, 1);
	}

	int find(int x){
		if (p[x] == -1)
			return (x);
		else 
			return (p[x] = find(p[x]));
	}

	bool unite(int x, int y){
		x = find(x);
		y = find(y);
		if (x == y)
			return (false);
		if (r[x] > r[y])
			swap(x, y);
		if (r[x] == r[y])
			r[y]++;
		p[x] = y;
		return (true);
	}

	bool same(int x, int y){
		return (find(x) == find(y));
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	int s, t;
	UnionFind uf(2 * n);
	for (int i = 0; i < m; i++)
	{
		cin >> s >> t;
		if (uf.same(s, t))
		{
			cout << "No" << endl;
			return (0);
		}
		uf.unite(s, t + n);
		uf.unite(s + n, t);
	}
	cout << "Yes" << endl;
}

