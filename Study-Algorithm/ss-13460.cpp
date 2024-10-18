#include <bits/stdc++.h>
using namespace std;

/*
	N*M ���簢������
	��������, �Ķ�����
	���������� ������ ���� ������ ����
	������ �Ѱ�
	�Ķ������� ���ۿ� ���� �ȵȴ�
	���ÿ� ������ �ȵȴ�

	�����¿� ���� ����δ�
	������ ���ÿ� �����δ�
	�� ������ ���ÿ� ���� ĭ�� ���� �� ����

	�ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ���ϴ� ���α׷�
	10�� ���Ϸ� �������� ���� ������ ������ ���� ���� �� ������ -1�� ���

	3 �� N, M �� 10
	. ��ĭ
	# ��ֹ�, ��
	o ����
	R ��������
	B �Ķ�����
*/

int n, m;
char board[14][14];
int visited[14][14][14][14];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int minResult = INT_MAX;
pair<int, int> red;
pair<int, int> blue;

struct goo
{
	int ry, rx, by, bx;
};

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

pair<int, int> Move(int y, int x, int dir)
{
	int ny = y;
	int nx = x;
	while (true)
	{
		ny += dy[dir];
		nx += dx[dir];

		if (board[ny][nx] == '#')
		{
			return { ny - dy[dir], nx - dx[dir] };
		}
		if (board[ny][nx] == 'O')
		{
			return { ny,nx };
		}
	}
}

void BFS()
{
	visited[red.first][red.second][blue.first][blue.second] = 1;
	queue<goo> q;
	q.push({ red.first, red.second, blue.first, blue.second });

	while (!q.empty())
	{
		int ry = q.front().ry;
		int rx = q.front().rx;
		int by = q.front().by;
		int bx = q.front().bx;
		q.pop();

		if (visited[ry][rx][by][bx] > 10)
		{
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nby = 0;
			int nbx = 0;
			tie(nby, nbx) = Move(by, bx, i);

			int nry = 0;
			int nrx = 0;
			tie(nry, nrx) = Move(ry, rx, i);

			//cout << "Start -> Red: (" << ry << ", " << rx << "), Blue: (" << by << ", " << bx << "), Dir: " << i << '\n';
			//cout << "End -> Red: (" << nry << ", " << nrx << "), Blue: (" << nby << ", " << nbx << "), Dir: " << i << '\n' << '\n';

			if (by == nby && bx == nbx && ry == nry && rx == nrx)
				continue;

			if (board[nby][nbx] == 'O')
				continue;

			if (visited[nry][nrx][nby][nbx] != 0)
				continue;

			/*if (visited[ry][rx][by][bx] > minResult)
				return;*/

			if (board[nry][nrx] == 'O')
			{
				minResult = min(minResult, visited[ry][rx][by][bx]);
				return;
			}

			// ���� ��ĥ ��
			if (nry == nby && nrx == nbx)
			{
				if (i == 0) ry < by ? nby++ : nry++;
				else if (i == 2) ry < by ? nry-- : nby--;
				else if (i == 1) rx < bx ? nrx-- : nbx--;
				else if (i == 3) rx < bx ? nbx++ : nrx++;
			}

			/*cout << "Count: " << visited[ry][rx][by][bx] << '\n';
			cout << "Start -> Red: (" << ry << ", " << rx << "), Blue: (" << by << ", " << bx << "), Dir: " << i << '\n';
			cout << "End -> Red: (" << nry << ", " << nrx << "), Blue: (" << nby << ", " << nbx << "), Dir: " << i << '\n' << '\n';*/

			if (visited[nry][nrx][nby][nbx] == 0)
			{
				visited[nry][nrx][nby][nbx] = visited[ry][rx][by][bx] + 1;
				q.push({ nry, nrx, nby, nbx });
			}
		}
	}
}

void Solution()
{
	//Print();
	BFS();
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
				red = { i,j };
			else if (s[j] == 'B')
				blue = { i,j };
		}
	}

	Solution();

	return 0;
}