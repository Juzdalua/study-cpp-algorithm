#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int w, h, n;
vector<pair<int, int>> v;
int result;
int visited[10'004][10'004];

int dy[6] = { -1, -1, 0, 1, 1, 0 };
int dx[6] = { 0, 1, 1, 0, -1, -1 };

void BFS(int startIdx, int destinationIdx)
{
	//cout << "Start -> (" << v[startIdx].second << ", " << v[startIdx].first << "), Destination -> (" << v[destinationIdx].second << ", " << v[destinationIdx].first << ")" << '\n';
	queue<pair<int, int>> q;
	q.push({ v[startIdx].second, v[startIdx].first });

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		//cout << "(" << y << ", " << x << ")" << '\n';

		if (y == v[destinationIdx].second && x == v[destinationIdx].first)
		{
			result += visited[y][x];
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= h || nx >= w || ny < 0 || nx < 0) continue;
			if (visited[ny][nx] != 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> w >> h >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x - 1,h - y });
	}

	for (int i = 1; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		BFS(i-1, i);
	}

	cout << result << '\n';

	return 0;
}