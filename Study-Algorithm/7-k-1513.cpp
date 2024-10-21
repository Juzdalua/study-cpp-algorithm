#include <bits/stdc++.h>
using namespace std;

/*
	N*M
	�� (1,1), �п� (N,M), ������ C��
	�������� ���� ��ġ�� (r, c) �� ��, (r+1, c) �Ǵ� (r, c+1)�θ� �̵��� �� �ִ�.
	������ ��ȣ�� �����ϴ� ������� �����Ѵٴ� ��
	2�� �������� ������, �� ���� �ƹ� �����ǵ� ���� �ʰų�, 1�� �������� �湮���� ���� �����ϴ�.

	�������� K�� �湮�ؼ� �п����� �����ϴ� ����� ����� ��
	�������� 0�� �湮���� ������, C�� �湮���� �� ���� ����� ���� ���

	N�� M�� 50���� �۰ų� ���� �ڿ���
	C�� 50���� �۰ų� ���� �ڿ��� �Ǵ� 0

	����� ������ 1,000,007�� ���� �������� ���
*/

int n, m, c;
int board[54][54];
vector<pair<int, int>> oraksil;
int dy[2] = { 1,0 };
int dx[2] = { 0,1 };
const int devider = 1'000'007;
int dp[54][54][54][54]; // y, x, prev, dest

int Go(int y, int x, int cnt, int last)
{
	if (y >= n || x >= m || cnt < 0)
		return 0;

	if (y == n - 1 && x == m - 1)
	{
		if (cnt == 0 && board[y][x] == 0)
			return 1;
		else if (cnt == 1 && board[y][x] > last)
			return 1;

		return 0;
	}

	int& res = dp[y][x][cnt][last];
	if (res != -1)
		return res;
	res = 0;

	if (board[y][x] == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			res += Go(ny, nx, cnt, last);
		}
	}
	else if(board[y][x] > last)
	{
		last = board[y][x];
		cnt--;

		for (int i = 0; i < 2; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			res += Go(ny, nx, cnt, last);
		}
	}

	return res % devider;
}

void Solution()
{
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= c; i++)
	{
		int res = Go(0, 0, i, 0);
		cout << res << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		board[in1 - 1][in2 - 1] = i;
		oraksil.push_back({ in1 - 1, in2 - 1 });
	}

	Solution();

	return 0;
}