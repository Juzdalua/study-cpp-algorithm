#include <bits/stdc++.h>
using namespace std;

/*

*/

int n;
char arr[104][104];
int r1, r2;
int visited[104][104];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void Check1(int startY, int startX)
{
	if (visited[startY][startX] == 1) return;

	queue<pair<int, int>> q;
	q.push({ startY, startX });
	visited[startY][startX] = 1;

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		//cout << "Check1 -> (" << y << ", " << x << ")" << '\n';

		char now = arr[y][x];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= n || nx >= n || ny < 0 || nx < 0) continue;
			if (visited[ny][nx] != 0) continue;
			if (arr[ny][nx] != now) continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	r1++;
}

void Check2(int startY, int startX)
{
	if (visited[startY][startX] == 1) return;

	queue<pair<int, int>> q;
	q.push({ startY, startX });
	visited[startY][startX] = 1;

	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();

		char now = arr[y][x];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= n || nx >= n || ny < 0 || nx < 0) continue;
			if (visited[ny][nx] != 0) continue;
			
			if (now == 'B' && arr[ny][nx] != now) continue;
			if ((now == 'R' || now == 'G') && arr[ny][nx] == 'B') continue;

			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	r2++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = s[j];
		}
	}

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Check1(i, j);
		}
	}
	
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Check2(i, j);
		}
	}

	cout << r1 << " " << r2 << '\n';

	return 0;
}