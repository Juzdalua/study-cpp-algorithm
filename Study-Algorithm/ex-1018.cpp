#include <bits/stdc++.h>
using namespace std;

/*

*/

int n, m;
char arr[54][54];
int result = INT_MAX;

void Print(char board[54][54])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}

void Check(int y, int x)
{
	//cout << '\n' << "Start -> (" << y << ", " << x << ")" << '\n';
	char temp[54][54] = { 0 };
	memcpy(temp, arr, sizeof(arr));

	char ex = temp[y][x];
	int cnt = 0;

	for (int row = 0; row < 8; row++)
	{
		if (result <= cnt) break;

		for (int col = 0; col < 8; col++)
		{
			if (result <= cnt) break;

			int ny = y + row;
			int nx = x + col;

			if (ny == y && nx == x) continue;

			if (temp[ny][nx] == ex)
			{
				//cout << "Change -> (" << ny << ", " << nx << "), ex: " << ex << ", now : " << temp[ny][nx] << '\n';

				if (ex == 'W')
				{
					temp[ny][nx] = 'B';
					cnt++;
				}
				else
				{
					temp[ny][nx] = 'W';
					cnt++;
				}
			}

			if (col == 7) ex = temp[ny][x];
			else ex = temp[ny][nx];
		}
	}
	result = min(result, cnt);
}

void CheckReverse(int y, int x)
{
	//cout << '\n' << "Start -> (" << y << ", " << x << ")" << '\n';
	char temp[54][54] = { 0 };
	memcpy(temp, arr, sizeof(arr));

	if (temp[y][x] == 'W') temp[y][x] = 'B';
	else if (temp[y][x] == 'B') temp[y][x] = 'W';
	char ex = temp[y][x];
	int cnt = 1;

	for (int row = 0; row < 8; row++)
	{
		if (result <= cnt) break;

		for (int col = 0; col < 8; col++)
		{
			if (result <= cnt) break;

			int ny = y + row;
			int nx = x + col;

			if (ny == y && nx == x) continue;

			if (temp[ny][nx] == ex)
			{
				//cout << "Change -> (" << ny << ", " << nx << "), ex: " << ex << ", now : " << temp[ny][nx] << '\n';

				if (ex == 'W')
				{
					temp[ny][nx] = 'B';
					cnt++;
				}
				else
				{
					temp[ny][nx] = 'W';
					cnt++;
				}
			}

			if (col == 7) ex = temp[ny][x];
			else ex = temp[ny][nx];
		}
	}
	result = min(result, cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j];
		}
	}

	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			Check(i, j);
			CheckReverse(i, j);
		}
	}

	cout << result << '\n';

	return 0;
}