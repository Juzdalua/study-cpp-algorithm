#include <bits/stdc++.h>
using namespace std;

/*
	N*N
	전체 블록을 상하좌우 중 이동
	같은값의 블록이 충돌하면 합쳐진다
	한번 이동에서 한 번만 합쳐질 수 있다.
	이동하는쪽의 블록이 먼저 합쳐진다

	1 ≤ N ≤ 20
	1 <= a M <= 1024

	5번 이동 후 얻을 수 있는 가장 큰 블록
*/

int n;
int arr[24][24];
int visited[24][24];
int maxResult = INT_MIN;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void RotateRight90(int board[24][24])
{
	int temp[24][24] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = board[n - j - 1][i];
		}
	}
	memcpy(board, temp, sizeof(temp));
}

void MoveLeftBlock(int board[24][24])
{
	int temp[24][24] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0)
				continue;

			if (temp[i][count] == 0)
			{
				temp[i][count] = board[i][j];
			}
			else if (temp[i][count] == board[i][j])
			{
				temp[i][count] *= 2;
				count++;
			}
			else
			{
				count++;
				temp[i][count] = board[i][j];
			}
		}
	}
	memcpy(board, temp, sizeof(temp));
}

void Go(int count, int board[24][24])
{
	if (count == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maxResult = max(maxResult, board[i][j]);
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int temp[24][24];
		memcpy(temp, board, sizeof(temp));

		MoveLeftBlock(temp);
		Go(count + 1, temp);

		RotateRight90(board);
	}
}

void Solution()
{
	Go(0, arr);

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
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	Solution();

	return 0;
}