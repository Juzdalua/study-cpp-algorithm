#include <bits/stdc++.h>
using namespace std;

/*
	R * C
	공기청정기는 1번 열
	크기는 두 행
	공기청정기가 없는곳은 미세먼지, 양은 (r,c)

	미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
		(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
		인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
		확산되는 양은 (r,c)/5이고 소수점은 버린다. 즉, ⌊(r,c)/5⌋이다.
		(r, c)에 남은 미세먼지의 양은 (r,c) - ⌊(r,c)/5⌋×(확산된 방향의 개수) 이다.

	공기청정기가 작동한다.
		공기청정기에서는 바람이 나온다.
		위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
		바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
		공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.

	6 ≤ R, C ≤ 50,
	1 ≤ T ≤ 1,000
	-1 ≤ (r,c) ≤ 1,000

*/

int r, c, t;
int board[54][54];
int temp[54][54];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
pair<int, int> airHead; // tail -> (airHead.first+1, airHead.second)
int nowTime = 0;

int Check(int y, int x)
{
	int canGoCount = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= r || nx >= c || ny < 0 || nx < 0)
			continue;

		if (board[ny][nx] == -1)
			continue;

		canGoCount++;
	}

	return canGoCount;
}

void DFS(int y, int x, int count)
{
	int munji = board[y][x] / 5;
	temp[y][x] += board[y][x] - (munji * count);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= r || nx >= c || ny < 0 || nx < 0)
			continue;

		if (board[ny][nx] == -1)
			continue;

		temp[ny][nx] += munji;
	}
}

void SetBoard()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			board[i][j] = temp[i][j];
		}
	}
}

void PrintBoard()
{
	cout << '\n';
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}

void DoAir()
{
	memset(temp, 0, sizeof(temp));

	// 0행 좌로 이동
	for (int i = 0; i < c - 1; i++)
	{
		temp[0][i] = board[0][i + 1];
	}
	temp[0][c - 1] = board[1][c - 1];

	// 머리행 우로 이동
	temp[airHead.first][1] = 0;
	for (int i = 2; i < c; i++)
	{
		temp[airHead.first][i] = board[airHead.first][i - 1];

	}

	// 꼬리행 우로 이동
	temp[airHead.first + 1][1] = 0;
	for (int i = 2; i < c; i++)
	{
		temp[airHead.first + 1][i] = board[airHead.first + 1][i - 1];

	}

	// r행 좌로 이동
	for (int i = 0; i < c - 1; i++)
	{
		temp[r - 1][i] = board[r - 1][i + 1];
	}
	temp[r - 1][c - 1] = board[r - 2][c - 1];

	// 0행~머리행 0열 아래로 이동
	for (int i = 1; i < airHead.first; i++)
	{
		temp[i][0] = board[i - 1][0];
	}

	// 0행~머리행 c열 위로 이동
	for (int i = 1; i < airHead.first; i++)
	{
		temp[i][c - 1] = board[i + 1][c - 1];
	}

	// 꼬리행~r행 0열 위로 이동
	for (int i = airHead.first + 1; i < r - 1; i++)
	{
		temp[i][0] = board[i + 1][0];
	}

	// 꼬리행~r행 c열 아래로 이동
	for (int i = airHead.first + 2; i < r; i++)
	{
		temp[i][c - 1] = board[i - 1][c - 1];
	}

	// 청소기 위부분 복사
	for (int i = 1; i < airHead.first; i++)
	{
		for (int j = 1; j < c - 1; j++)
		{
			temp[i][j] = board[i][j];
		}
	}

	// 청소기 아래부분 복사
	for (int i = airHead.first + 2; i < r - 1; i++)
	{
		for (int j = 1; j < c - 1; j++)
		{
			temp[i][j] = board[i][j];
		}
	}

	temp[airHead.first][airHead.second] = -1;
	temp[airHead.first + 1][airHead.second] = -1;

	// 동기화
	SetBoard();
}

void Solution()
{
	while (t--)
	{
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (board[i][j] >= 5)
				{
					int count = Check(i, j);
					if (count > 0)
					{
						DFS(i, j, count);
					}
				}
				else
				{
					temp[i][j] += board[i][j];
				}
			}
		}
		SetBoard();
		//PrintBoard();
		DoAir();
		//PrintBoard();
	}
	//PrintBoard();

	long long sum = 2;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			sum += board[i][j];
		}
	}
	cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == -1)
			{
				if (airHead.first == 0 && airHead.second == 0)
				{
					airHead.first = i;
					airHead.second = j;
				}
			}
		}
	}

	Solution();

	return 0;
}