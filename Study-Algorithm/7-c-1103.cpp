#include <bits/stdc++.h>
using namespace std;

/*
	1~9 숫자, 직사각형 보드
	(0,0) 동전을 올려놓고 시작

	1. 동전이 있는 곳에 쓰여 있는 숫자 X를 본다.
	2. 위, 아래, 왼쪽, 오른쪽 방향 중에 한가지를 고른다.
	3. 동전을 위에서 고른 방향으로 X만큼 움직인다. 이때, 중간에 있는 구멍은 무시한다.

	동전이 구멍에 빠지거나, 보드 밖으로 나가면 게임끝
	최대 몇 번 동전을 움직일 수 있는지 구하는 프로그램

	만약 형택이가 동전을 무한번 움직일 수 있다면 -1을 출력
*/

int n, m;
char arr[54][54];
int visited[54][54];
int dp[54][54];
int maxResult = INT_MIN;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void Print()
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

int Go(int y, int x)
{
	if (y >= n || x >= m || y < 0 || x < 0 || arr[y][x] == 'H')
	{
		//maxResult = max(maxResult, cnt);
		return 0;
	}

	if (visited[y][x] == 1)
	{
		cout << -1 << '\n';
		exit(0);
	}

	if (dp[y][x] != 0)
		return dp[y][x];

	visited[y][x] = 1;

	int next = arr[y][x] - '0';

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * next;
		int nx = x + dx[i] * next;

		dp[y][x] = max(dp[y][x], Go(ny, nx) + 1);
	}
	visited[y][x] = 0;

	return dp[y][x];
}

void Solution()
{
	//Print();

	int result = Go(0, 0);
	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	memset(arr, '0', sizeof(arr));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j];
		}
	}

	Solution();

	return 0;
}