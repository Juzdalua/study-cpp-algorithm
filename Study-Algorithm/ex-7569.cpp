#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|

	1 : 익은 토마토
	0 : 익지 않은 토마토
	-1 : 빈칸
*/

int n, m, h;
int arr[104][104][104];
int visited[104][104][104];
long long day;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int totalTomato, remainTomato;

void Print(int board[104][104][104])
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cout << board[i][j][k] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

bool Check(int board[104][104][104], int flag)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (board[i][j][k] == flag) return true;
			}
		}
	}
	return false;
}

void BFS()
{
	remainTomato = totalTomato;
	queue<tuple<int, int, int>> q;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (arr[i][j][k] == 1 && visited[i][j][k] == 0)
				{
					q.push({ i, j, k });
					visited[i][j][k] = 1;
				}
			}
		}
	}

	while (!q.empty())
	{
		bool flag = false;
		int size = q.size();

		for (int j = 0; j < size; j++)
		{
			auto [height, y, x] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;
				if (arr[height][ny][nx] != 0) continue;
				if (visited[height][ny][nx] == 1) continue;
				//cout << "Same Floor -> (" << height << ", " << ny << ", " << nx << ")" << '\n';

				visited[height][ny][nx] = 1;
				arr[height][ny][nx] = 1;
				remainTomato--;
				flag = true;

				q.push({ height,ny,nx });
			}

			for (int nh : {height - 1, height + 1})
			{
				if (nh < 0 || nh >= h) continue;
				if (arr[nh][y][x] != 0) continue;
				if (visited[nh][y][x] == 1) continue;
				//cout << "Diff Floor -> (" << nh << ", " << y << ", " << x << ")" << '\n';

				visited[nh][y][x] = 1;
				arr[nh][y][x] = 1;
				remainTomato--;
				flag = true;

				q.push({ nh, y, x });
			}
		}

		if (flag)
		{
			day++;
			/*Print(arr);
			cout << "Day -> " << day << '\n' << '\n';*/
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 0) totalTomato++;
			}
		}
	}

	//Print(arr);

	if (totalTomato == 0)
	{
		cout << 0 << '\n';
		exit(0);
	}

	BFS();

	if (remainTomato == 0) cout << day << '\n';
	else cout << -1 << '\n';

	return 0;
}