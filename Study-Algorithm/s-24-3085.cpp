#include <bits/stdc++.h>
using namespace std;

/*
	N * N
	������ ���� ��� ���� ���� �� �ִ�

	������ ���� �ٸ� ������ ��ĭ�� ����
	�� ĭ�� ������ ��ȯ�Ѵ�.
	��� ���� ������ �̷�����ִ� ���� �� �� �Ǵ� ���� ������ �� ������ ��� �Դ´�.

	����̰� ���� �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷�

	3 �� N �� 50
	�������� C, �Ķ����� P, �ʷϻ��� Z, ������� Y
	������ ���� �ٸ� ������ �� ĭ�� �����ϴ� �Է¸� �־�����.
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

	// ���� �� �� �̱�
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

	// ���� �� �� �̱�
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

		// ���� ��ȯ
		swap(board[y][x], board[ny][nx]);

		// Ž��
		Check(y, x, ny, nx);

		// ���� ����
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