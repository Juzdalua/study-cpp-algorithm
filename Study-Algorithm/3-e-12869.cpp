#include <bits/stdc++.h>
using namespace std;

/*
	뮤탈1개, SCV N개
	공격을 받으면 각각 9 - 3 - 1 체력을 잃는다.
	체력이 0되면 파괴된다.
	같은 SCV를 공격할수는 없다.

	파괴하기위해 공격해야하는 최소값
	SCV의 수 N (1 ≤ N ≤ 3)
	1 <= 체력 <= 60
*/

int n;
vector<int> scv;
int result = INT_MAX;
int dp[64][64][64];
int visited[64][64][64];
int nextNode[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 3, 9},
	{1, 9, 3}
};

void BFS(tuple<int, int, int>& s)
{
	queue<tuple<int, int, int>> q;
	q.push(s);

	while (!q.empty())
	{
		int x, y, z;
		x = get<0>(q.front());
		y = get<1>(q.front());
		z = get<2>(q.front());
		q.pop();

		if (x == 0 && y == 0 && z == 0)
		{
			cout << visited[x][y][z] << '\n';
			exit(0);
		}

		for (int i = 0; i < 6; i++)
		{
			int nx = x - nextNode[i][0];
			int ny = y - nextNode[i][1];
			int nz = z - nextNode[i][2];

			nx = max(0, nx);
			ny = max(0, ny);
			nz = max(0, nz);

			if (visited[nx][ny][nz] != 0)
				continue;

			visited[nx][ny][nz] = visited[x][y][z] + 1;
			q.push({ nx, ny, nz });
		}
	}
}

void Solution()
{
	tuple<int, int, int> s;
	int x, y, z;
	x = scv[0];
	y = scv.size() > 1 ? scv[1] : 0;
	z = scv.size() > 2 ? scv[2] : 0;
	s = make_tuple(x, y, z);

	visited[x][y][x] = 0;
	BFS(s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	scv.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> scv[i];
	}

	Solution();

	return 0;
}