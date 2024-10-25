#include <bits/stdc++.h>
using namespace std;

/*
	�κ� û�ұ�� ���� ���°� �־����� ��, û���ϴ� ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

	N*M ���簢��
	1 ��, 0 ��ĭ
	û�ұ� �ٶ󺸴¹��� ��������
	ó�� ��ĭ�� ��� û�ҵ��� ���� ����

	�κ� û�ұ�� ������ ���� �۵��Ѵ�.

	1. ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�.
	2. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���,
		�ٶ󺸴� ������ ������ ä�� �� ĭ ������ �� �ִٸ� �� ĭ �����ϰ� 1������ ���ư���.
		�ٶ󺸴� ������ ���� ĭ�� ���̶� ������ �� ���ٸ� �۵��� �����.
	3. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ���,
		�ݽð� �������� 90�� ȸ���Ѵ�.
		�ٶ󺸴� ������ �������� ���� ĭ�� û�ҵ��� ���� �� ĭ�� ��� �� ĭ �����Ѵ�.
		1������ ���ư���.

	3 <= N, M <= 50
	0 ��, 1 ��, 2 ��, 3 ��

	�κ� û�ұⰡ �۵��� ������ �� �۵��� ���� ������ û���ϴ� ĭ�� ������ ����Ѵ�.
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

		// 1. ����ĭ û��
		if (board[y][x] == 0)
		{
			Clean(y, x);
		}

		// �ֺ� 4���� üũ
		int check = 0;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (board[ny][nx] != 0)
				check++;
		}

		// 2. ��� û�ҵǾ��ִ� ���
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

		// 3. û������ ���� ĭ�� �ִ� ���
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