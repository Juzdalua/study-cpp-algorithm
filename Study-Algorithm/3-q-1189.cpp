#include <bits/stdc++.h>
using namespace std;

/*
	집에 간다
	현재 왼쪽 아래 점, 집은 오른쪽 위 점
	지나친곳 다시 방문안한다.
	T는 가지 못한다.

		cdef  ...f  ..ef  ..gh  cdeh  cdej  ...f
		bT..  .T.e  .Td.  .Tfe  bTfg  bTfi  .Tde
		a...  abcd  abc.  abcd  a...  a.gh  abc.
거리 :  6     6     6     8     8    10    6

	R x C
	거리 K
	한수가 집까지도 도착하는 경우 중 거리가 K인 가짓수

	R(1 ≤ R ≤ 5),
	C(1 ≤ C ≤ 5),
	K(1 ≤ K ≤ R×C)
*/

int r, c, k;
char board[10][10];
int visited[10][10];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt = 1;
int result = 0;

void DFS(int y, int x)
{
	//cout << "DFS -> (" << y << ", " << x << ")" << '\n';
	if (y == 0 && x == c - 1)
	{
		if (cnt == k)
			result++;
		return;
	}
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= r || nx >= c || ny < 0 || nx < 0)
			continue;

		if (board[ny][nx] != '.')
			continue;

		if (visited[ny][nx] != 0)
			continue;

		visited[ny][nx] = 1;
		cnt++;

		DFS(ny, nx);

		visited[ny][nx] = 0;
		cnt--;
	}
}

void Solution()
{
	DFS(r - 1, 0);

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	Solution();

	return 0;
}