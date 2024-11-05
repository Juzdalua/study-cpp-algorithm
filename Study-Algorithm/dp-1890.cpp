#include <bits/stdc++.h>
using namespace std;

/*
	N*N
	���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ��Ģ�� �°� ������ �ؼ� ���� ���̴�
	�� ĭ�� �����ִ� ���� ���� ĭ���� �� �� �ִ� �Ÿ��� �ǹ��Ѵ�.
	�������̳� �Ʒ������θ� �̵��ؾ� �Ѵ�
	0�� �� �̻� ������ ���� �������̸�, �׻� ���� ĭ�� �����ִ� ����ŭ �������̳� �Ʒ��� ���� �Ѵ�.
	��Ģ�� �°� �̵��� �� �ִ� ����� ������ ���ϴ� ���α׷�

	4 �� N �� 100
	0 <= ĭ <= 9
	���� ������ �Ʒ� ĭ���� �׻� 0�� �־�����

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