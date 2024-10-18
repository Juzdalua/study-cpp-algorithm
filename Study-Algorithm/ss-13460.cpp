#include <bits/stdc++.h>
using namespace std;

/*
	N*M 직사각형보드
	빨간구슬, 파란구슬
	빨간구슬을 구멍을 통해 빼내는 게임
	구멍은 한개
	파랑구슬이 구멍에 들어가면 안된다
	동시에 빠져도 안된다

	상하좌우 판을 기울인다
	구슬은 동시에 움직인다
	두 구슬은 동시에 같은 칸에 있을 수 없다

	최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램
	10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력

	3 ≤ N, M ≤ 10
	. 빈칸
	# 장애물, 벽
	o 구멍
	R 빨간구슬
	B 파랑구슬
*/

int n, m;
char board[14][14];
int visitedR[14][14];
int visitedB[14][14];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int minResult = INT_MAX;
pair<int, int> r;
pair<int, int> b;

void Print(char arr[14][14])
{
	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void Go(int count, char arr[14][14], int vr[14][14], int vb[14][14])
{
	if (count > 10 || count > minResult)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		char tBoard[14][14] = { '0' };
		int tvr[14][14] = { 0 };
		int tvb[14][14] = { 0 };
		memcpy(tBoard, arr, sizeof(tBoard));
		memcpy(tvr, vr, sizeof(tvr));
		memcpy(tvb, vb, sizeof(tvb));

		pair<int, int> tempR = r;
		pair<int, int> tempB = b;

		queue<pair<int, int>> q;

		pair<int, int> next = r;
		q.push({ r.first , r.second });
		bool flag = false;
		bool isGoal = false;

		while (!q.empty())
		{
			int ny, nx;
			tie(ny, nx) = q.front();
			q.pop();
			ny += dy[i];
			nx += dx[i];

			if (tBoard[ny][nx] == '#')
				continue;
			if (tvr[ny][nx] != 0)
				continue;

			if (tBoard[ny][nx] == 'O')
			{
				isGoal = true;
				break;
			}

			if (tBoard[ny][nx] == 'B')
				flag = true;

			tvr[ny][nx] = 1;
			q.push({ ny ,nx });
			next = { ny,nx };
		}
		if (isGoal)
		{
			while (!q.empty())
				q.pop();
		}
		if (flag)
		{
			tvr[next.first][next.second] = 0;
			next.first -= dy[i];
			next.second -= dx[i];
		}
		if (r != next)
		{
			tBoard[next.first][next.second] = 'R';
			tBoard[r.first][r.second] = '.';
			r = next;
			//Print(tBoard);
		}

		next = b;
		flag = false;
		q.push({ b.first, b.second });
		while (!q.empty())
		{
			int ny, nx;
			tie(ny, nx) = q.front();
			q.pop();
			ny += dy[i];
			nx += dx[i];

			if (tBoard[ny][nx] == '#')
				continue;
			if (tvb[ny][nx] != 0)
				continue;

			if (tBoard[ny][nx] == 'O')
				return;

			if (tBoard[ny][nx] == 'R')
				flag = true;

			tvb[ny][nx] = 1;
			q.push({ ny ,nx });
			next = { ny,nx };
		}
		if (flag)
		{
			tvb[next.first][next.second] = 0;
			next.first -= dy[i];
			next.second -= dx[i];
		}
		if (b != next)
		{
			tBoard[next.first][next.second] = 'B';
			tBoard[b.first][b.second] = '.';
			b = next;
			Print(tBoard);
		}
		if (isGoal)
		{
			minResult = min(count, minResult);
			return;
		}

		Go(count + 1, tBoard, tvr, tvb);
		r = tempR;
		b = tempB;
	}
}

void Solution()
{
	//Print();
	visitedR[r.first][r.second] = 1;
	visitedB[b.first][b.second] = 1;
	Go(1, board, visitedR, visitedB);

	if (minResult == INT_MAX)
		minResult = -1;
	cout << minResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		string s;
		cin >> s;
		for (int j = 0;j < m;j++)
		{
			board[i][j] = s[j];

			if (s[j] == 'R')
				r = { i,j };
			else if (s[j] == 'B')
				b = { i,j };
		}
	}

	Solution();

	return 0;
}