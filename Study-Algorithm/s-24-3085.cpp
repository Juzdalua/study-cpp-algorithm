#include <bits/stdc++.h>
using namespace std;

/*
	N * N
	사탕의 색은 모두 같지 않을 수 있다

	사탕의 색이 다른 인접한 두칸을 고른다
	두 칸의 사탕을 교환한다.
	모두 같은 색으로 이루어져있는 가장 긴 행 또는 열을 고른다음 그 사탕을 모두 먹는다.

	상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램

	3 ≤ N ≤ 50
	빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y
	사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.
*/

int n;
char board[54][54];
int visited[54][54][54][54];
int maxResult = INT_MIN;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void Print(char temp[54][54])
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << temp[i][j] << " ";
		}
		cout << '\n';
	}
}

void Check(int y, int x, int ny, int nx)
{
	//cout << "Check -> (" << y << ", " << x << ") - (" << ny << ", " << nx << ")" << '\n';
	//visited[y][x][ny][nx] = 1;

	// 가장 긴 행 뽑기
	for (int i = 0; i < n; i++)
	{
		int maxCnt = 1;
		for (int j = 1; j < n; j++)
		{
			if (board[i][j] == board[i][j - 1])
				maxCnt++;
			else
				maxCnt = 1;
			maxResult = max(maxResult, maxCnt);
		}
	}

	// 가장 긴 열 뽑기
	for (int i = 0; i < n; i++)
	{
		int maxCnt = 1;
		for (int j = 1; j < n; j++)
		{
			if (board[j][i] == board[j-1][i])
				maxCnt++;
			else
				maxCnt = 1;
			maxResult = max(maxResult, maxCnt);
		}
	}
}

void Go(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;

		if (board[y][x] == board[ny][nx])
			continue;

		if (visited[y][x][ny][nx] == 1)
			continue;

		// 사탕 교환
		swap(board[y][x], board[ny][nx]);

		// 탐색
		Check(y, x, ny, nx);

		// 사탕 원복
		swap(board[y][x], board[ny][nx]);
	}
}

void Solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Go(i, j);
		}
	}
	cout << maxResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			board[i][j] = s[j];
		}
	}

	Solution();

	return 0;
}