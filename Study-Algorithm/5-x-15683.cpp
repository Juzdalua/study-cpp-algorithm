#include <bits/stdc++.h>
using namespace std;

/*
	N * M 직사각형
	K개의 CCTV
	감시방향이 다른 5종류
	1. ->
	2. <- -> 반대방향
	3. ^ -> 직각방향
	4. <- ^ ->
	5. <- ^ 아래 ->

	감시방향 칸을 전체 감시할 수 있다.
	벽을 통과할 수 없다.
	90도 회전 가능하다
	사각지대가 있다
	CCTV를 통과할 수 있다.

	0-빈칸
	1~5- 각 번호
	6-벽

	사각지대의 최소크기를 구하라.

	1 ≤ N, M ≤ 8
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
	// 사각지대 확인
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

// 0-위 1-오른 2-아래 3-왼
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
	// 종료
	if (count == cctv.size())
	{
		Check(arr);
		return;
	}

	// CCTV 처리
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