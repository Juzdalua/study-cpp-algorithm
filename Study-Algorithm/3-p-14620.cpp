#include <bits/stdc++.h>
using namespace std;

/*
	꽃을 심으면 1년 후 핀다
	씨앗이 3개밖에 없다

	N*N 꽃밭
	한칸에 심을 수 있다.
	1년 후, 상하좌우 1칸을 차지한다.

	밖으로 꽃이피면 꽃이 죽는다.
	꽃잎끼리 맞닿으면 꽃이 죽는다.

	꽃 하나당 5평을 대여해야한다.
	꽃을 심기 위한 최소비용

	N(6≤N≤10)
	화단의 지점당 가격(0≤G≤200)
*/

int n;
int board[14][14];
int visited[14][14];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int flowerCount = 0;
int flowerSum = 0;
int minResult = INT_MAX;

bool DFS(int y, int x)
{
	if (visited[y][x] != 0)
		return false;

	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;

		if (visited[ny][nx] != 0)
			continue;

		cnt++;
	}
	if (cnt != 4)
		return false;
	return true;
}

int LootFlower(int y, int x)
{
	visited[y][x] = 1;
	int sum = board[y][x];
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		visited[ny][nx] = 1;
		sum += board[ny][nx];
	}
	return sum;
}

int BackFlower(int y, int x)
{
	visited[y][x] = 0;
	int sum = board[y][x];
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		visited[ny][nx] = 0;
		sum += board[ny][nx];
	}
	return sum;
}

void Go()
{
	if (flowerCount == 3)
	{
		minResult = min(minResult, flowerSum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (DFS(i, j))
			{
				flowerCount++;
				flowerSum += LootFlower(i, j);

				Go();

				flowerCount--;
				flowerSum -= BackFlower(i, j);
			}
		}
	}
}

void Solution()
{
	Go();
	cout << minResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
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