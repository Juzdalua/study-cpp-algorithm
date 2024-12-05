#include <bits/stdc++.h>
using namespace std;

/*
	1 익은 토마토
	0 익지 않은 토마도
	-1 토마도 없음

	하루가 지나면 익은토마토 상하좌우 인접 토마토가 익는다
	며칠이 지나면 익는지 최소 일수
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