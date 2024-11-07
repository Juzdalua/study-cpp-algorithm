#include <bits/stdc++.h>
using namespace std;

/*
	2원 5원 거스름돈
	무한개
	동전의 갯수가 최소로 거슬러준다
	15 = 5*3 -> 3
	14 = 5*2 + 2*2 -> 4
	13 = 5*1 + 2*4 -> 5

	1 ≤ n ≤ 100,000
	만약 거슬러 줄 수 없으면 -1을 출력
*/

int n;
int dp[100004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[0] = -1;
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = dp[2] + 1;
	dp[5] = 1;

	for (int i = 6; i <= n; i++)
	{
		if (dp[i - 2] != -1)
			dp[i] = dp[i - 2] + 1;

		if (dp[i - 5] != -1)
			dp[i] = min(dp[i], dp[i - 5] + 1);
	}

	cout << dp[n] << '\n';

	return 0;
}