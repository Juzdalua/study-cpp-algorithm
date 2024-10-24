#include <bits/stdc++.h>
using namespace std;

/*
	N*N ü����
	���� ���� K��, 1~K��
	ĭ�� ���, ������, �Ķ��� �� �ϳ�
	�̵����� 4����
	���� ��ĥ���ִ�
	���� �̵��ϸ� ���� ���� ���� �̵��Ѵ�.

	�� 1��
	1������ K�� ������� �����δ�
	���� 4�� �̻� ���̸� ����ȴ�

	A�� ���� �̵��Ϸ��� ĭ��
	����� ��쿡�� �� ĭ���� �̵��Ѵ�. �̵��Ϸ��� ĭ�� ���� �̹� �ִ� ��쿡�� ���� ���� A�� ���� �÷����´�.
		A�� ���� ���� �ٸ� ���� �ִ� ��쿡�� A�� ���� ���� �ִ� ��� ���� �̵��Ѵ�.
		���� ���, A, B, C�� �׿��ְ�, �̵��Ϸ��� ĭ�� D, E�� �ִ� ��쿡�� A�� ���� �̵��� �Ŀ��� D, E, A, B, C�� �ȴ�.
	�������� ��쿡�� �̵��� �Ŀ� A�� ���� �� ���� �ִ� ��� ���� �׿��ִ� ������ �ݴ�� �ٲ۴�.
		A, B, C�� �̵��ϰ�, �̵��Ϸ��� ĭ�� ���� ���� ��쿡�� C, B, A�� �ȴ�.
		A, D, F, G�� �̵��ϰ�, �̵��Ϸ��� ĭ�� ���� E, C, B�� �ִ� ��쿡�� E, C, B, G, F, D, A�� �ȴ�.
	�Ķ����� ��쿡�� A�� ���� �̵� ������ �ݴ�� �ϰ� �� ĭ �̵��Ѵ�. ������ �ݴ�� �ٲ� �Ŀ� �̵��Ϸ��� ĭ�� �Ķ����� ��쿡�� �̵����� �ʰ� ������ �ִ´�.
	ü������ ����� ��쿡�� �Ķ����� ���� ����̴�.

	������ ����Ǵ� ���� ��ȣ

	0�� ���, 1�� ������, 2�� �Ķ���
	(1,1) ����
	1234 ��, ��, ��, ��
	1,000���� ũ�ų� ����� ������ ������� �ʴ� ��쿡�� -1�� ���

	4 �� N �� 12
	4 �� K �� 10
*/

struct malstruct
{
	int y, x, dir;
};

int n, k;
int board[16][16];
vector<int> arr[16][16];
malstruct mal[14];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int turn;

void Check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j].size() >= 4)
			{
				cout << turn << '\n';
				exit(0);
			}
		}
	}
}

void Print()
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j].size() == 0)
				cout << board[i][j] << " ";
			else
			{
				cout << "[";
				for (int l = 0; l < arr[i][j].size(); l++)
				{
					if (l == 0)
						cout << arr[i][j][l];
					else
						cout << " " << arr[i][j][l];
				}
				cout << "]";
			}
		}
		cout << '\n';
	}

	cout << '\n';
	for (int i = 0; i < k; i++)
	{
		malstruct m = mal[i];
		cout << "(" << m.y << ", " << m.x << "), dir: " << m.dir << " -> " << i << '\n';
	}
}

void Solution()
{
	while (true)
	{
		turn++;
		if (turn > 1000)
			break;

		//Print();
		for (int i = 0; i < k; i++)
		{
			malstruct& ma = mal[i];
			int ny = ma.y + dy[ma.dir];
			int nx = ma.x + dx[ma.dir];
			int dir = ma.dir;

			//cout << '\n' << "Mal -> " << i << ", (" << ny << ", " << nx << ")" << ", dir: " << dir << " -> " << i << '\n';
			//Print();

			// �Ķ�, ��� ��
			if (ny >= n || nx >= n || ny < 0 || nx < 0 || board[ny][nx] == 2)
			{
				if (dir == 0)
					dir = 1;
				else if (dir == 1)
					dir = 0;
				else if (dir == 2)
					dir = 3;
				else if (dir == 3)
					dir = 2;

				ma.dir = dir;
				ny = ma.y + dy[dir];
				nx = ma.x + dx[dir];
				if (ny >= n || nx >= n || ny < 0 || nx < 0 || board[ny][nx] == 2)
					continue;
			}

			vector<int> next;
			vector<int>& curBoard = arr[ma.y][ma.x];
			int size = 0;
			auto it = find(curBoard.begin(), curBoard.end(), i);
			if (it != curBoard.end())
			{
				while (it != curBoard.end())
				{
					next.push_back(*it);
					it++;
					size++;
				}
				while (size--)
				{
					curBoard.pop_back();
				}

				// ����
				if (board[ny][nx] == 1)
					reverse(next.begin(), next.end());

				for (int j = 0; j < next.size(); j++)
				{
					arr[ny][nx].push_back(next[j]);

					mal[next[j]].y = ny;
					mal[next[j]].x = nx;
				}

				ma.y = ny;
				ma.x = nx;
			}
			Check();
		}
	}

	if (turn > 1000)
		turn = -1;
	cout << turn << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		int y, x, dir;
		cin >> y >> x >> dir;
		mal[i].y = y - 1;
		mal[i].x = x - 1;
		mal[i].dir = dir - 1;

		arr[y - 1][x - 1].push_back(i);
	}

	Solution();

	return 0;
}