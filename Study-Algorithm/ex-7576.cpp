#include <bits/stdc++.h>
using namespace std;

/*
	1 ���� �丶��
	0 ���� ���� �丶��
	-1 �丶�� ����

	�Ϸ簡 ������ �����丶�� �����¿� ���� �丶�䰡 �ʹ´�
	��ĥ�� ������ �ʹ��� �ּ� �ϼ�
*/

int m, n;
int arr[1'004][1'004];
long long day;
int cnt, t;
queue<pair<int, int>> q;
queue<pair<int, int>> temp;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Print(int board[1'004][1'004])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}


void BFS()
{
	while (!q.empty())
	{
		int y = 0;
		int x = 0;
		tie(y, x) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= m || nx >= n || ny < 0 || nx < 0)
				continue;
			if (arr[ny][nx] != 0)
				continue;

			arr[ny][nx] = 1;
			temp.push({ ny, nx });
			cnt++;
		}
	}

	if (temp.empty())
	{
		if (t == cnt)
			return;
		else
		{
			cout << -1 << '\n';
			exit(0);
		}
	}

	day++;
	q = temp;
	while(!temp.empty())
		temp.pop();
	BFS();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				q.push({ i,j });
				cnt++;
			}

			if (arr[i][j] != -1)
				t++;
		}
	}
	BFS();
	cout << day << '\n';

	return 0;
}