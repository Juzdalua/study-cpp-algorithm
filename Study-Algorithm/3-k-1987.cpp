#include <bits/stdc++.h>
using namespace std;

/*
	R * C
	1,1 말
	각 칸은 알파벳 대문자
	말은 상하좌우 1칸 이동
	이동한 칸의 알파벳은 지금까지 알파벳과 달라야한다.
	말이 최대한 갈 수 있는 칸을 구하라
	시작칸도 카운트한다.
*/

int r, c;
char board[24][24];
int visited[24][24];
int visitedChar[30];
int result = 0;
int maxResult = INT_MIN;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Print()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}

void DFS(int y, int x)
{
	//cout << "DFS -> (" << y << ", " << x << ")" << '\n';
	if (visited[y][x] == 0)
		visited[y][x] = 1;

	maxResult = max(result, maxResult);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= r || nx >= c || ny < 0 || nx < 0)
			continue;
		if (visited[ny][nx] != 0)
			continue;
		if (visitedChar[board[ny][nx] - 'A'] != 0)
			continue;

		result++;
		visited[ny][nx] = 1;
		visitedChar[board[ny][nx] - 'A'] = 1;
		//cout << "Insert:" << board[ny][nx] << '\n';

		

		DFS(ny, nx);

		//cout << "Erase:" << board[ny][nx] << '\n';
		result--;
		visited[ny][nx] = 0;
		visitedChar[board[ny][nx] - 'A'] = 0;
	}
}

void Solution()
{
	//Print();

	visitedChar[board[0][0] - 'A'] = 1;
	visited[0][0] = 1;
	DFS(0, 0);
	cout << maxResult + 1 << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++)
		{
			board[i][j] = input[j];
		}
	}

	Solution();

	return 0;
}