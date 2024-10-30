#include <bits/stdc++.h>
using namespace std;

/*
	N * N
	각 칸에는 높이
	길이란 한 행 또는 한 열 전부를 나타내며

	길에 속한 모든칸의 높이가 같아야한다.
	경사로를 놓아서 길을 만들 수 있다.
	경사로 높이는 1, 길이는 L
	경사로 갯수는 무한
		경사로는 낮은 칸에 놓으며, L개의 연속된 칸에 경사로의 바닥이 모두 접해야 한다.
		낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
		경사로를 놓을 낮은 칸의 높이는 모두 같아야 하고, L개의 칸이 연속되어 있어야 한다.

	아래와 같은 경우에는 경사로를 놓을 수 없다.
		경사로를 놓은 곳에 또 경사로를 놓는 경우
		낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우
		낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
		경사로를 놓다가 범위를 벗어나는 경우

	지나갈 수 있는 길의 개수를 구하는 프로그램
	2 ≤ N ≤ 100
	1 ≤ L ≤ N
	각 칸의 높이는 10보다 작거나 같은 자연수
*/

int n, l;
int board[104][104];
int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };
int result;

void CheckRow(int y)
{
	int cnt = 1;
	int start = board[y][0];
	int num = start;
	//cout << '\n' << "Check Row -> Y: " << y << ", start: " << start << '\n';

	for (int i = 1; i < n; i++)
	{
		int now = board[y][i];
		//cout << "i: " << i << ", num: " << num << ", now: " << now << '\n';
		if (now == num)
		{
			cnt++;
		}
		else
		{
			if (abs(now - num) > 1)
				break;
			if (now > num && cnt < l)
				break;
			if (now < num && n - i < l)
				break;

			if (now > num)
			{
				cnt = 1;
			}
			if (now < num)
			{
				cnt = 0;
				for (int j = i; j < i + l; j++)
				{
					if (board[y][j] == now)
					{
						cnt++;
						//cout << "j: " << j << ", cnt: " << cnt << ", num: " << now << '\n';
					}
					else
					{
						break;
					}
				}
				if (cnt != l)
					break;

				cnt = 0;
				i += l - 1;
			}
			num = now;
		}

		if (i >= n - 1)
		{
			//cout << "Plus! -> y: " << y << ", start -> " << board[y][0] << '\n';
			result++;
		}
	}
}

void CheckColumn(int x)
{
	int cnt = 1;
	int start = board[0][x];
	int num = start;

	//cout << '\n' << "Check Column -> X: " << x << ", start: " << start << '\n';

	for (int i = 1; i < n; i++)
	{
		//cout << "i: " << i << ", now: " << board[i][x] << '\n';
		int now = board[i][x];
		if (now == num)
		{
			cnt++;
		}
		else
		{
			if (abs(now - num) > 1)
				break;
			if (now > num && cnt < l)
				break;
			if (now < num && n - i < l)
				break;

			if (now > num)
			{
				cnt = 1;
			}
			if (now < num)
			{
				cnt = 0;
				for (int j = i; j < i + l; j++)
				{
					if (board[j][x] == now)
					{
						cnt++;
						//cout << "j: " << j << ", cnt: " << cnt << ", num: " << now << '\n';
					}
					else
					{
						break;
					}
				}
				if (cnt != l)
					break;

				cnt = 0;
				i += l - 1;
			}
			num = now;
		}

		if (i >= n - 1)
		{
			result++;
			//cout << "Plus! -> x: " << x << ", start -> " << board[0][x] << '\n';
		}
	}
}

void Solution()
{
	// 행 탐색
	for (int i = 0; i < n; i++)
	{
		CheckRow(i);
	}

	// 열 탐색
	for (int i = 0; i < n; i++)
	{
		CheckColumn(i);
	}

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	Solution();

	return 0;
}