#include <bits/stdc++.h>
using namespace std;

/*
	1~9 ����, ���簢�� ����
	(0,0) ������ �÷����� ����

	1. ������ �ִ� ���� ���� �ִ� ���� X�� ����.
	2. ��, �Ʒ�, ����, ������ ���� �߿� �Ѱ����� ����.
	3. ������ ������ �� �������� X��ŭ �����δ�. �̶�, �߰��� �ִ� ������ �����Ѵ�.

	������ ���ۿ� �����ų�, ���� ������ ������ ���ӳ�
	�ִ� �� �� ������ ������ �� �ִ��� ���ϴ� ���α׷�

	���� �����̰� ������ ���ѹ� ������ �� �ִٸ� -1�� ���
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