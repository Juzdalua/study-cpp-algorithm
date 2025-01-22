#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, r, c;
int cnt = -1;
int dy[3] = { 0, 1, 0 };
int dx[3] = { 1, -1, 1 };

pair<int, int> Z(int y, int x)
{
	int ny, nx = 0;

	for (int i = 0; i < 3; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		cnt++;
		if (ny == r && nx == c)
		{
			cout << cnt << '\n';
			exit(0);
		}
	}
	return { ny, nx };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> c;

	int end = pow(2, n) - 1;
	int mid = pow(2, n - 1) - 1;

	for (pair<int, int> pos : vector<pair<int, int>>{ {0,0}, {0,mid + 1}, {mid + 1, 0}, {mid + 1, mid + 1} })
	{
		cnt++;
		auto [y, x] = pos;
		auto [ny, nx] = Z(y, x);

		if (ny == mid && nx == mid) continue;
		if (ny == mid && nx == end) continue;
		if (ny == end && nx == mid) continue;
		if (ny == end && nx == end) continue;

		
	}

	return 0;
}