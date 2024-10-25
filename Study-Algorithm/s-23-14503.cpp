#include <bits/stdc++.h>
using namespace std;

/*
	로봇 청소기와 방의 상태가 주어졌을 때, 청소하는 영역의 개수를 구하는 프로그램을 작성하시오.

	N*M 직사각형
	1 벽, 0 빈칸
	청소기 바라보는방향 동서남북
	처음 빈칸은 모두 청소되지 않은 상태

	로봇 청소기는 다음과 같이 작동한다.

	1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
	2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
		바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
		바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
	3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
		반시계 방향으로 90도 회전한다.
		바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
		1번으로 돌아간다.

	3 <= N, M <= 50
	0 북, 1 동, 2 남, 3 서

	로봇 청소기가 작동을 시작한 후 작동을 멈출 때까지 청소하는 칸의 개수를 출력한다.
*/

struct robot
{
	int y, x, d;
};
int n, m;
int board[54][54];
robot r;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt;

void Clean(int y, int x)
{
	//cout << "Clean (" << y << ", " << x << ")" << '\n';
	cnt++;
	board[y][x] = -1;
}

void PrintBoard()
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

void Solution()
{
	int abcd = 2;
	while (true)
	//while (abcd--)
	{
		int y = r.y;
		int x = r.x;
		int d = r.d;
		//cout << '\n' << "Start -> " << cnt << ", (" << y << ", " << x << "), dir: " << d << '\n';
		//PrintBoard();

		// 1. 현재칸 청소
		if (board[y][x] == 0)
		{
			Clean(y, x);
		}

		// 주변 4방향 체크
		int check = 0;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (board[ny][nx] != 0)
				check++;
		}

		// 2. 모두 청소되어있는 경우
		if (check == 4)
		{
			int backDir = (d + 2) % 4;
			int ny = y + dy[backDir];
			int nx = x + dx[backDir];
			if (ny < n && nx < m && ny >= 0 && nx >= 0 && board[ny][nx] != 1)
			{
				r.y = ny;
				r.x = nx;
				continue;
			}
			else 
			{
				break;
			}
		}

		// 3. 청소하지 않은 칸이 있는 경우
		else
		{
			for (int i = 1; i <= 4; i++)
			{
				int dir = d - i;
				if (dir == -1)
					dir = 3;
				else if (dir == -2)
					dir = 2;
				else if (dir == -3)
					dir = 1;
				else if (dir == -4)
					dir = 0;

				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < n && nx < m && ny >= 0 && nx >= 0 && board[ny][nx] == 0)
				{
					r.y = ny;
					r.x = nx;
					r.d = dir;
					break;
				}
			}
		}
	}

	cout << cnt << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int y, x, d;
	cin >> y >> x >> d;
	r.y = y;
	r.x = x;
	r.d = d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	Solution();

	return 0;
}