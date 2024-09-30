#include <bits/stdc++.h>
using namespace std;

/*
	N * N 행렬
	A의 B제곱을 구하라
	수가 클 수 있으니
	A^B % 1'000을 출력하라

	2 ≤ N ≤  5
	1 ≤ B ≤ 100,000,000,000 (천억)


*/

using uint64 = unsigned long long;

int n;
uint64 b;
uint64 a[10][10];
uint64 result[10][10];
uint64 temp[10][10];
const uint64 devider = 1'000;

uint64 Multiple(uint64 x, uint64 y, uint64(&board)[10][10])
{
	uint64 num = 0;
	for (int i = 0; i < n; i++)
	{
		num += board[x][i] * board[i][y] % devider;
	}
	return num;
}

uint64 MultipleOdd(uint64 x, uint64 y, uint64(&board)[10][10])
{
	uint64 num = 0;
	for (int i = 0; i < n; i++)
	{
		num += board[x][i] * a[i][y] % devider;
	}
	return num;
}

void UpdateResult()
{
	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j] = temp[i][j];
		}
	}
}

void Solution()
{
	map<uint64, uint64> bMap;
	while (b > 1)
	{
		if (b % 2 == 0)
		{
			bMap[b] = 0;
		}
		else
		{
			b -= 1;
			bMap[b] = 1;
			if (b == 2)
				break;
		}
		b /= 2;
	}

	for (auto& cnt : bMap)
	{
		for (int i = 0;i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp[i][j] = Multiple(i, j, result) % devider;
			}
		}
		UpdateResult();

		if (cnt.second == 1)
		{
			for (int i = 0;i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					temp[i][j] = MultipleOdd(i, j, result) % devider;
				}
			}
			UpdateResult();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			result[i][j] = a[i][j];
		}
	}

	Solution();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << result[i][j] % devider << " ";
		}
		cout << '\n';
	}

	return 0;
}