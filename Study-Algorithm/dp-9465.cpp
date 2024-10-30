#include <bits/stdc++.h>
using namespace std;

/*
	스티커 2n개 구매
	2행 n열
	뗀 스티커의 4방향 스티커는 사용할 수 없다.
	점수의 합이 최대가 되게 스티커를 떼어내려고 한다
	상냥이가 뗄 수 있는 스티커의 점수의 최댓값을 구하는 프로그램을 작성하시오

	1 ≤ n ≤ 100,000
	0 <= 점수 <= 100
*/

int n, t;
int board[2][100'004];
long long dp[2][100'004];
vector<long long> result;

void Solution()
{
	dp[0][1] = board[0][0];
	dp[1][1] = board[1][0];

	for (int i = 2; i <= n; i++)
	{
		dp[0][i] = max(max(dp[1][i - 1] + board[0][i - 1], dp[0][i - 1]), max(dp[0][i - 2], dp[1][i - 2]) + board[0][i - 1]);
		dp[1][i] = max(max(dp[0][i - 1] + board[1][i - 1], dp[1][i - 1]), max(dp[0][i - 2], dp[1][i - 2]) + board[1][i - 1]);
	}
	result.push_back(max(dp[0][n], dp[1][n]));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		memset(board, 0, sizeof(board));
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> board[j][k];
			}
		}
		Solution();
	}

	for (long long& r : result)
		cout << r << '\n';

	return 0;
}