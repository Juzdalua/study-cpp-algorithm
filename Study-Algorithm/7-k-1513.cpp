#include <bits/stdc++.h>
using namespace std;

/*
	N*M
	집 (1,1), 학원 (N,M), 오락실 C개
	세준이의 현재 위치가 (r, c) 일 때, (r+1, c) 또는 (r, c+1)로만 이동할 수 있다.
	오락실 번호가 증가하는 순서대로 가야한다는 것
	2번 오락실을 가려면, 그 전에 아무 오락실도 가지 않거나, 1번 오락실을 방문했을 때만 가능하다.

	오락실을 K번 방문해서 학원에서 도착하는 경로의 경우의 수
	오락실을 0개 방문했을 때부터, C개 방문했을 때 까지 경우의 수를 출력

	N과 M은 50보다 작거나 같은 자연수
	C는 50보다 작거나 같은 자연수 또는 0

	경로의 개수는 1,000,007로 나눈 나머지를 출력
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