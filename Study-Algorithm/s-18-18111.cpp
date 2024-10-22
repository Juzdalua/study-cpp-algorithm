#include <bits/stdc++.h>
using namespace std;

/*
	1 �� 1 �� 1(����, ����, ����) ũ���� ���
	���� ���̸� ��� �����ϰ� ����� ���� ���⡯ �۾�

	���� N, ���� M ũ���� ����
	���� �� ���� ���� ��ǥ�� (0, 0)
	�� ���� ���� ���� ���̸� �����ϰ� �ٲٴ� ��

	2�� ��� -> 1. ��ǥ (i, j)�� ���� ���� �ִ� ����� �����Ͽ� �κ��丮�� �ִ´�.
	1�� �ױ� -> 2. �κ��丮���� ��� �ϳ��� ������ ��ǥ (i, j)�� ���� ���� �ִ� ��� ���� ���´�.

	�� ���� �۾��� �ɸ��� �ּ� �ð��� �� ��� ���� ���̸� ���

	�۾��� ������ �� �κ��丮���� B���� ����� ��� �ִ�
	���� ���̴� 256����� �ʰ��� �� ������, ������ �� �� ����.

	1 �� M, N �� 500,
	0 �� B �� 64 �� 10^6
	���� ���̴� 256���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.
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

			// ���
			if (board[i][j] > num)
			{
				int next = board[i][j] - num;
				sum += next * 2;
				left += next;
			}

			// �ױ�
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