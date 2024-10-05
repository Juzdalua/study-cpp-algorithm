#include <bits/stdc++.h>
using namespace std;

/*
	미로에서 탈출
	불에 타기 전 탈출할 수 있는지 여부
	얼마나 빨리 탈출할 수 있는지 결정

	지훈이와 불은 매 분 마다 한칸씩 수평, 수직으로 이동한다.
	불은 각 지점에서 네방향으로 확산된다.
	지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
	지훈이와 불은 벽을 통과할 수 없다.

	R은 미로 행의 개수, C는 열의 개수
	1 ≤ R, C ≤ 1000

	#: 벽
	.: 지나갈 수 있는 공간
	J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
	F: 불이 난 공간
*/

int r, c;
char board[1'004][1'004];
int visited[1'004][1'004];
int fireIdx[1'004][1'004];
const string NO = "IMPOSSIBLE";
pair<int, int> startPos;
vector<pair<int, int>> firePos;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int minResult = INT_MAX;

void PrintFire()
{
	for (int i = 0; i < r; i++)
	{
		cout << "\n";
		for (int j = 0; j < c; j++)
		{
			cout << fireIdx[i][j] << " ";
		}
	}
	cout << "\n";
}

void PrintVisited()
{
	for (int i = 0; i < r; i++)
	{
		cout << "\n";
		for (int j = 0; j < c; j++)
		{
			cout << visited[i][j] << " ";
		}
	}
	cout << "\n";
}

void PrintBoard()
{
	for (int i = 0; i < r; i++)
	{
		cout << "\n";
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j] << " ";
		}
	}
	cout << "\n";
}

void MoveFire()
{
	queue<pair<int, int>> q;

	for (pair<int, int>& fp : firePos)
	{
		/*q.push({ fp.second, fp.first });
		fireIdx[fp.second][fp.first] = 0;*/
		q.push({ fp.first, fp.second });
		fireIdx[fp.first][fp.second] = 0;
	}

	while (!q.empty())
	{
		int x, y;
		tie(y, x) = q.front();
		q.pop();
		//cout << "Fire -> (" << y << ", " << x << "), Idx -> " << fireIdx[y][x] << '\n';

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= r || nx >= c || ny < 0 || nx < 0)
				continue;

			if (board[ny][nx] != '.' && board[ny][nx] != 'J')
				continue;

			if (fireIdx[ny][nx] != -1)
				continue;

			fireIdx[ny][nx] = fireIdx[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

void BFS()
{
	queue<pair<int, int>> q;
	/*q.push({ startPos.second, startPos.first });
	visited[startPos.second][startPos.first] = 0;*/
	q.push({ startPos.first, startPos.second });
	visited[startPos.first][startPos.second] = 0;

	while (!q.empty())
	{
		int x, y;
		tie(y, x) = q.front();
		q.pop();
		//cout << "BFS -> (" << y << ", " << x << "), Cost: " << visited[y][x] << '\n';

		// 탈출조건
		if (y == 0 || y == r - 1 || x == 0 || x == c - 1)
		{
			//cout << "BREAK -> (" << y << ", " << x << "), Cost: " << visited[y][x] << '\n';
			minResult = min(minResult, visited[y][x]);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= r || nx >= c || ny < 0 || nx < 0)
				continue;
			if (visited[ny][nx] != 0)
				continue;
			if (board[ny][nx] != '.')
				continue;

			// 불 체크
			if (firePos.size() > 0)
			{
				if (fireIdx[ny][nx] <= visited[y][x] + 1)
					continue;
			}

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

void Solution()
{
	MoveFire();
	BFS();
	//PrintFire();
	//PrintVisited();

	if (minResult != INT_MAX)
		cout << minResult + 1 << '\n';
	else
		cout << NO << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(fireIdx, -1, sizeof(fireIdx));
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 'J')
			{
				startPos = { i, j };
			}

			else if (board[i][j] == 'F')
			{
				firePos.push_back({ i, j });
			}
		}
	}

	Solution();

	return 0;
}