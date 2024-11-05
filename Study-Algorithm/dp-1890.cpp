#include <bits/stdc++.h>
using namespace std;

/*
	N*N
	가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 점프를 해서 가는 것이다
	각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리를 의미한다.
	오른쪽이나 아래쪽으로만 이동해야 한다
	0은 더 이상 진행을 막는 종착점이며, 항상 현재 칸에 적혀있는 수만큼 오른쪽이나 아래로 가야 한다.
	규칙에 맞게 이동할 수 있는 경로의 개수를 구하는 프로그램

	4 ≤ N ≤ 100
	0 <= 칸 <= 9
	가장 오른쪽 아래 칸에는 항상 0이 주어진다

*/

int n;
int board[104][104];
int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };
long long dp[104][104];

long long Go(int y, int x)
{
	if (y == n - 1 && x == n - 1)
	{
		return 1;
	}
	else if (board[y][x] == 0)
	{
		return 0;
	}

	long long& res = dp[y][x];
	if (res != -1)
		return res;
	res = 0;

	for (int i = 0; i < 2; i++)
	{
		int ny = y + dy[i] * board[y][x];
		int nx = x + dx[i] * board[y][x];

		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;

		res += Go(ny, nx);
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	long long result = Go(0, 0);
	cout << result << '\n';

	return 0;
}