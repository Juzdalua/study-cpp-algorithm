#include <bits/stdc++.h>
using namespace std;

/*
	이친수는 0으로 시작하지 않는다.
	이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.
	1, 10, 100, 101, 1000, 1001
	0010101, 101101

	1 ≤ N ≤ 90
	N자리 이친수의 개수를 구하는 프로그램
*/

int n;
long long dp[94][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[1][1] = 1;
	dp[2][0] = 1;

	for (int i = 3; i <= 90; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1] << '\n';

	return 0;
}