#include <bits/stdc++.h>
using namespace std;

/*
	N*N
	(x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램

	1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000
*/

struct XY
{
	int x1, y1, x2, y2;
};

int n, m;
int board[1027][1027];
vector<XY> v;
int psum[1027][1027];

void Solution() 
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			psum[i][j] = psum[i][j-1] + board[i][j];
		}
	}

	for (XY& xy : v)
	{
		int x1 = xy.x1;
		int y1 = xy.y1;
		int x2 = xy.x2;
		int y2 = xy.y2;

		long long sum = 0;
		for (int i = x1; i <= x2; i++)
		{
			sum += psum[i][y2] - psum[i][y1 - 1];
		}
		cout << sum << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ x1, y1, x2, y2 });
	}

	Solution();

	return 0;
}