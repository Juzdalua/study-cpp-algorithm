#include <bits/stdc++.h>
using namespace std;

/*
	N * M ���簢��
	K���� CCTV
	���ù����� �ٸ� 5����
	1. ->
	2. <- -> �ݴ����
	3. ^ -> ��������
	4. <- ^ ->
	5. <- ^ �Ʒ� ->

	���ù��� ĭ�� ��ü ������ �� �ִ�.
	���� ����� �� ����.
	90�� ȸ�� �����ϴ�
	�簢���밡 �ִ�
	CCTV�� ����� �� �ִ�.

	0-��ĭ
	1~5- �� ��ȣ
	6-��

	�簢������ �ּ�ũ�⸦ ���϶�.

	1 �� N, M �� 8
*/

int n, m;
int board[10][10];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<pair<int, int>> cctv;
int minResult = INT_MAX;
int result;

void Print(int arr[10][10])
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void Check(int arr[10][10])
{
	// �簢���� Ȯ��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
				result++;
		}
	}
	minResult = min(minResult, result);
	result = 0;
}

// 0-�� 1-���� 2-�Ʒ� 3-��
void CCTV(int y, int x, int dir, int temp[10][10])
{
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty())
	{
		int ny, nx;
		tie(ny, nx) = q.front();
		q.pop();

		if (ny >= n || nx >= m || ny < 0 || nx < 0)
			continue;
		if (temp[ny][nx] == 6)
			continue;

		if (temp[ny][nx] == 0)
			temp[ny][nx] = -1;
		q.push({ ny + dy[dir], nx + dx[dir] });
	}
}

void Go(int count, int arr[10][10])
{
	// ����
	if (count == cctv.size())
	{
		Check(arr);
		return;
	}

	// CCTV ó��
	int y = cctv[count].first;
	int x = cctv[count].second;
	//cout << "Start -> (" << y << ", " << x << ")" << '\n';

	//int num = arr[y][x];
	

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		int temp[10][10] = { 0 };
		memcpy(temp, arr, sizeof(temp));
		if (temp[y][x] == 1)
		{
			CCTV(ny, nx, i, temp);
		}
		else if (temp[y][x] == 2)
		{
			CCTV(ny, nx, i, temp);
			CCTV(y + dy[(i + 2) % 4], x + dx[(i + 2) % 4], (i + 2) % 4, temp);
		}
		else if (temp[y][x] == 3)
		{
			CCTV(ny, nx, i, temp);
			CCTV(y + dy[(i + 1) % 4], x + dx[(i + 1) % 4], (i + 1) % 4, temp);
		}
		else if (temp[y][x] == 4)
		{
			CCTV(ny, nx, i, temp);
			CCTV(y + dy[(i + 1) % 4], x + dx[(i + 1) % 4], (i + 1) % 4, temp);
			if(i-1 < 0)
				CCTV(y + dy[3], x + dx[3], 3, temp);
			else
				CCTV(y + dy[(i - 1) % 4], x + dx[(i - 1) % 4], (i - 1) % 4, temp);
		}
		else if (temp[y][x] == 5)
		{
			CCTV(ny, nx, i, temp);
			CCTV(y + dy[(i + 1) % 4], x + dx[(i + 1) % 4], (i + 1) % 4, temp);
			CCTV(y + dy[(i + 2) % 4], x + dx[(i + 2) % 4], (i + 2) % 4, temp);
			if (i - 1 < 0)
				CCTV(y + dy[3], x + dx[3], 3, temp);
			else
				CCTV(y + dy[(i - 1) % 4], x + dx[(i - 1) % 4], (i - 1) % 4, temp);
		}
		//Print(temp);
		Go(count + 1, temp);
	}
}

void Solution()
{
	Go(0, board);
	cout << minResult << '\n';
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
			if (board[i][j] >= 1 && board[i][j] <= 5)
				cctv.push_back({ i,j });
		}
	}

	Solution();

	return 0;
}