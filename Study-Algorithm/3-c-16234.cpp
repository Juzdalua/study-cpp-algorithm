#include <bits/stdc++.h>
using namespace std;

/*
	N * N ��
	��� ������ ũ��� 1 * 1
	��� ���漱�� ���簢��
	A[r][c] = r�� c���� ����ִ� ����� ��

	�α��̵�
	1. ���漱�� �����ϴ� �� ������ �α� ���̰� L�� �̻�, R�� ���϶��, �� ���� �����ϴ� ���漱�� ���� �Ϸ� ���� ����.
	2. ���� ���ǿ� ���� ������ϴ� ���漱�� ��� ���ȴٸ�, �α� �̵��� �����Ѵ�.
	3. ���漱�� �����־� ������ ĭ���� �̿��� �̵��� �� ������, �� ���� ���� �Ϸ� ������ �����̶�� �Ѵ�.
	4. ������ �̷�� �ִ� �� ĭ�� �α����� (������ �α���) / (������ �̷�� �ִ� ĭ�� ����)�� �ȴ�. ���ǻ� �Ҽ����� ������.
	5. ������ ��ü�ϰ�, ��� ���漱�� �ݴ´�.

	�α��̵��� ���� �߻��ϴ��� ���
	1 �� N �� 50,
	1 �� L �� R �� 100
	0 �� A[r][c] �� 100
*/

int n, l, r;
int board[54][54];
int visited[54][54];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
map<pair<int, int>, tuple<int, int, vector<pair<int, int>>>> bm; // bm[����x,����y] = (sum, count, [(����x,����y), ...])

void PrintVisited()
{
	cout << "\n" << "Print Visited" << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

void PrintBoard()
{
	cout << "\n" << "Print Board" << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

bool CheckDone()
{
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (!flag)
			break;
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				flag = false;
				break;
			}
		}
	}
	return flag;
}

void DFS(int y, int x, int startX, int startY)
{
	//cout << "DFS -> (" << y << ", " << x << "), START -> (" << startX << ", " << startY << ")" << '\n';
	if (visited[y][x] == 0)
		visited[y][x] = 1;

	get<0>(bm[{startX, startY}]) += board[y][x];
	get<1>(bm[{startX, startY}])++;
	get<2>(bm[{startX, startY}]).push_back({ y, x });

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;
		if (visited[ny][nx] != 0)
			continue;
		if (abs(board[y][x] - board[ny][nx]) >= l && abs(board[y][x] - board[ny][nx]) <= r)
			DFS(ny, nx, startX, startY);
	}
}

void Solution()
{
	int resultCount = 0;
	while (true)
	{
		memset(visited, 0, sizeof(visited));
		bm.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				DFS(i, j, i, j);
			}
		}

		int breakCount = 0;
		bool flag = false;
		for (auto& m : bm)
		{
			//cout << "SUM: " << get<0>(m.second) << ", Count: " << get<1>(m.second) << '\n';
			if (get<1>(m.second) == 1)
				breakCount++;

			if (breakCount == bm.size())
			{
				//PrintBoard();
				cout << resultCount << '\n';
				exit(0);
			}

			if (get<1>(m.second) > 1)
			{
				int avg = get<0>(m.second) / get<1>(m.second);
				for (auto& v : get<2>(m.second))
				{
					flag = true;
					board[v.first][v.second] = avg;
				}
			}
		}
		if (flag)
			resultCount++;

		/*if (resultCount == 1)
			break;*/
	}

	PrintBoard();
	//PrintVisited();

	cout << resultCount << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	Solution();

	return 0;
}