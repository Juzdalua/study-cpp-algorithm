#include <bits/stdc++.h>
using namespace std;

/*
	N * M 크기 교실
	파동은 칸마다 상하좌우 친구에게 맞을 떄까지 퍼진다
	주난 = *,
	초코바 = #,
	빈공간 = 0,
	친구들 = 1
	주난이의 최소점프범위

	1 ≤ N, M ≤ 300
	1 ≤ x1, x2 ≤ N, 1 ≤ y1, y2 ≤ M
*/

int n, m;
char board[304][304];
char temp[304][304];
int visited[304][304];
pair<int, int>junan;
pair<int, int>thief;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int result = 0;

void Print()
{
	cout << "\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}

void CopyTemp()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			board[i][j] = temp[i][j];
		}
	}
}

void DFS(int y, int x)
{
	//cout << "DFS -> (" << y << ", " << x << ")" << '\n';
	if (visited[y][x] == 0)
		visited[y][x] = 1;

	if (y == thief.first && x == thief.second)
	{
		cout << result << '\n';
		exit(0);
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny > n || nx > m || ny < 1 || nx < 1)
			continue;
		if (visited[ny][nx] != 0)
			continue;

		if (board[ny][nx] == '1')
			temp[ny][nx] = '0';

		else if (board[ny][nx] == '0' || board[ny][nx] == '#')
			DFS(ny, nx);

	}
}

void Solution()
{
	while (true)
	{
		result++;
		//Print();
		memset(visited, 0, sizeof(visited));
		DFS(junan.first, junan.second);
		CopyTemp();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	cin >> junan.first >> junan.second;
	cin >> thief.first >> thief.second;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
			temp[i][j] = board[i][j];
		}
	}

	Solution();

	return 0;
}