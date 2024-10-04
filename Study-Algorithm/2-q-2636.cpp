#include <bits/stdc++.h>
using namespace std;

/*
	���簢�� ��
	�����ڸ��� ġ� ����.
	���� ġ�� ȸ��

	ġ��� �ϳ� �̻��� ������ ���� �� �ִ�.
	ġ��� ���⸦ ������ ��´�.
	����� ���˵� ġ��ĭ�� �ѽð� �� ��� ��������.

	ġ� ��� �������µ� �ɸ��� �ð�
	��� �� �ð� ��, �����ִ� ġ�� ������ ����
*/

int n, m;
int board[104][104];
int temp[104][104];
int visited[104][104];
int resultCount = 0;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void PrintTemp()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << temp[i][j] << " ";
		}
		cout << "\n";
	}
}

bool CheckEmpty()
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != 0)
			{
				flag = true;
				break;
			}
		}
	}
	if (flag)
		return false;
	return true;
}

bool CheckEmptyTemp()
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] != 0)
			{
				flag = true;
				break;
			}
		}
	}
	if (flag)
		return false;
	return true;
}

int CheckCheese()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != 0)
			{
				cnt++;
			}
		}
	}
	return cnt;
}

void CopyTemp()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && temp[i][j] == 0)
				board[i][j] = 0;
		}
	}
}

void DFS(int y, int x)
{
	//cout << "DFS -> (" << y << ", " << x << ")" << '\n';
	if (visited[y][x] == 0)
		visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= m || ny < 0 || nx < 0)
			continue;

		if (board[ny][nx] == 1)
		{
			temp[ny][nx] = 0;
			continue;
		}

		if (visited[ny][nx] != 0)
			continue;

		if (board[ny][nx] == 0)
			DFS(ny, nx);
	}
}

void Solution()
{
	while (true)
	{
		memset(visited, 0, sizeof(visited));
		DFS(0, 0);

		resultCount++;
		//PrintTemp();
		if (CheckEmptyTemp())
		{
			// ����
			int cheese = CheckCheese();
			cout << resultCount << '\n';
			cout << cheese << '\n';
			exit(0);
		}
		else
		{
			CopyTemp();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(board, -1, sizeof(board));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			temp[i][j] = board[i][j];
		}
	}

	Solution();

	return 0;
}