#include <bits/stdc++.h>
using namespace std;

/*
	1집 0빈
	상하좌우 연결된 집 - 단지

*/

int n;
int arr[29][29];
int danzi;
vector<int> result;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void Print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

void BFS(int startY, int startX)
{
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	arr[startY][startX] = 2;

	//cout << '\n' << "Start -> (" << startY << ", " << startX << ")" << '\n';

	int cnt = 1;
	while (!q.empty())
	{
		auto [y, x] = q.front();
		q.pop();
		//cout << "BFS -> (" << y << ", " << x << ")" << '\n';

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= n || nx >= n || ny < 0 || nx < 0)
				continue;
			if (arr[ny][nx] != 1)
				continue;

			arr[ny][nx] = 2;
			cnt++;
			q.push({ ny,nx });
		}
	}

	danzi++;
	result.push_back(cnt);
	//Print();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < n; j++)
		{
			arr[i][j] = input[j] - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
				BFS(i, j);
		}
	}

	cout << danzi << '\n';
	sort(result.begin(), result.end());
	for (int& i : result)
		cout << i << '\n';

	return 0;
}