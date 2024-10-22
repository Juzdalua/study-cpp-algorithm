#include <bits/stdc++.h>
using namespace std;

/*
	1 × 1 × 1(세로, 가로, 높이) 크기의 블록
	땅의 높이를 모두 동일하게 만드는 ‘땅 고르기’ 작업

	세로 N, 가로 M 크기의 집터
	집터 맨 왼쪽 위의 좌표는 (0, 0)
	이 집터 내의 땅의 높이를 일정하게 바꾸는 것

	2초 깎기 -> 1. 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
	1초 쌓기 -> 2. 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.

	땅 고르기 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력

	작업을 시작할 때 인벤토리에는 B개의 블록이 들어 있다
	땅의 높이는 256블록을 초과할 수 없으며, 음수가 될 수 없다.

	1 ≤ M, N ≤ 500,
	0 ≤ B ≤ 64 × 10^6
	땅의 높이는 256보다 작거나 같은 자연수 또는 0이다.
*/

int n, m, b;
int board[504][504];
vector<int> block(257, INT_MAX);
int maxB = INT_MIN;
int minB = INT_MAX;
int height;
long long minResult = INT_MAX;

void Go(int num)
{
	int left = b;
	long long sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == num)
				continue;

			// 깎기
			if (board[i][j] > num)
			{
				int next = board[i][j] - num;
				sum += next * 2;
				left += next;
			}

			// 쌓기
			else
			{
				int next = num - board[i][j];
				sum += next;
				left -= next;
			}
		}
	}

	if (left >= 0)
	{
		block[num] = sum;
		minResult = min(minResult, sum);
		if (minResult == sum)
			height = num;
	}
}

void Solution()
{
	for (int i = 0; i <= 256; i++)
	{
		Go(i);
	}

	cout << minResult << " " << height << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			maxB = max(maxB, board[i][j]);
			minB = min(minB, board[i][j]);
		}
	}

	Solution();

	return 0;
}