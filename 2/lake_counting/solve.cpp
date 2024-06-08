#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int x, int y, vector<string> &field)
{
	field[x][y] = '.';
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
		{
			int nx = x + dx, ny = y + dy;
			if (0 <= nx && nx < field.size() && 0 <= ny && ny < field[0].size() && field[nx][ny] == 'W')
				dfs(nx, ny, field);
		}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> field(N);
	for (int i = 0; i < N; i++)
		cin >> field[i];
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (field[i][j] == 'W')
			{
				dfs(i, j, field);
				ans++;
			}
	cout << ans << endl;
}
