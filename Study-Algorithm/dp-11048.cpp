#include <bits/stdc++.h>
using namespace std;

/*
	N*M
	�� �濡�� ����
	���� (1,1) -> (N,M) �̵�

	�ر԰� (r, c)�� ������, (r+1, c), (r, c+1), (r+1, c+1)�� �̵��� �� �ְ�
	�� ���� �湮�� ������ �濡 �������ִ� ������ ��� ������ �� �ִ�

	������ �� �ִ� ���� ������ �ִ�
	1 �� N, M �� 1,000
	0 <= ���� <= 100
*/

int n, m;
int board[1004][1004];
int dy[3] = { 0, 1, 1 };
int dx[3] = { 1, 1, 0 };
int dp[1004][1004];

int Go(int y, int x)
{
	if (y == n - 1 && x == m - 1)
	{
		return board[y][x];
	}

	int& res = dp[y][x];
	if (res != -1)
		return res;

	res = board[y][x];

	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= m || ny < 0 || nx < 0)
			continue;

		res = max(res, board[y][x] + Go(ny, nx));
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	
	cout << Go(0, 0) << '\n';

	return 0;
}