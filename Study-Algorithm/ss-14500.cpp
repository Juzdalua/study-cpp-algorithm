#include <bits/stdc++.h>
using namespace std;

/*
	N*M ũ��
	������ ĭ���� ������ �ϳ� ���� �ִ�.
	��Ʈ�ι̳� �ϳ��� ������ ���Ƽ� ��Ʈ�ι̳밡 ���� ĭ�� ���� �ִ� ������ ���� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
	ȸ���̳� ��Ī�� ���ѵ� �ȴ�.

	4 �� N, M �� 500
	�Է����� �־����� ���� 1,000�� ���� �ʴ� �ڿ����̴�.
*/

int n, m;
int board[504][504];
int maxResult = INT_MIN;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

// ----
void Check1(int y, int x)
{
	int cnt = 1;
	int sum = board[y][x];
	while (cnt < 4)
	{
		cnt++;
		int ny = y + dy[1];
		int nx = x + dx[1];
		if (ny >= n || nx >= m || ny < 0 || nx < 0)
			return;

		sum += board[ny][nx];
		y = ny;
		x = nx;
	}
	maxResult = max(sum, maxResult);
}

// ����
void Check2(int y, int x)
{
	int cnt = 1;
	int sum = board[y][x];
	while (cnt < 4)
	{
		cnt++;
		int ny = y + dy[2];
		int nx = x + dx[2];
		if (ny >= n || nx >= m || ny < 0 || nx < 0)
			return;

		sum += board[ny][nx];
		y = ny;
		x = nx;
	}
	maxResult = max(sum, maxResult);
}

// �簢��
void Check3(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[1];
	int nx = x + dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[3];
	nx += dx[3];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

// ��
void Check4(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[1];
	nx += dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[3] * 2;
	nx += dx[3] * 2;
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check5(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[0] + dy[1];
	nx += dx[0] + dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check6(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[0] + dy[1];
	nx += dx[0] + dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[3] * 2;
	nx += dx[3] * 2;
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check7(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[0] + dy[3];
	nx += dx[0] + dx[3];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

// 
void Check8(int y, int x)
{
	int sum = board[y][x];
	
	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[1];
	nx += dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check9(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[3];
	int nx = x + dx[3];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[3];
	nx += dx[3];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check10(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[1];
	int nx = x + dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[1];
	nx += dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check11(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[3];
	nx += dx[3];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

// ��
void Check12(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[1];
	nx += dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check13(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[3];
	nx += dx[3];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[3];
	nx += dx[3];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check14(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[1];
	int nx = x + dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check15(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[0];
	int nx = x + dx[0];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[1];
	nx += dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[1];
	nx += dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check16(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[3];
	nx += dx[3];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check17(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[2];
	int nx = x + dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[1];
	nx += dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[1];
	nx += dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check18(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[3];
	int nx = x + dx[3];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void Check19(int y, int x)
{
	int sum = board[y][x];

	int ny = y + dy[1];
	int nx = x + dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[1];
	nx += dx[1];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	ny += dy[2];
	nx += dx[2];
	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;
	sum += board[ny][nx];

	maxResult = max(sum, maxResult);
}

void DFS(int y, int x)
{
	Check1(y, x);
	Check2(y, x);
	Check3(y, x);
	Check4(y, x);
	Check5(y, x);
	Check6(y, x);
	Check7(y, x);
	Check8(y, x);
	Check9(y, x);
	Check10(y, x);
	Check11(y, x);
	Check12(y, x);
	Check13(y, x);
	Check14(y, x);
	Check15(y, x);
	Check16(y, x);
	Check17(y, x);
	Check18(y, x);
	Check19(y, x);
}

void Solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			DFS(i, j);
		}
	}
	cout << maxResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	Solution();

	return 0;
}