#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> field(N, vector<int>(M, 0));
	string s;
	queue<pair<int, int>> q;
	pair<int, int> start, goal;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			if (s[j] == '#')
				field[i][j] = -1;
			else if (s[j] == 'S')
				start = make_pair(i, j);
			else if (s[j] == 'G')
				goal = make_pair(i, j);
		}
	}
	q.push(start);
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if (x == goal.first && y == goal.second)
		{
			cout << field[x][y] << endl;
			return 0;
		}
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if ((i == 0) ^ (j == 0))
				{
					if (x + i >= 0 && x + i < N && y + j >= 0 && y + j < M && field[x + i][y + j] == 0)
					{
						field[x + i][y + j] = field[x][y] + 1;
						q.push(make_pair(x + i, y + j));
					}
				}
			}
		}
	}
}
