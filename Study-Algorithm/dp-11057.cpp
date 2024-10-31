#include <bits/stdc++.h>
using namespace std;

/*
	오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.
	2234와 3678, 11119는 오르막 수
	2232, 3676, 91111은 오르막 수가 아니다
	오르막 수의 개수를 구하는 프로그램
	수는 0으로 시작할 수 있다.

	수의 길이 N
	1 ≤ N ≤ 1,000
*/

int n;
const int devider = 10'007;
int dp[1'004][10];
int psum[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= 10; i++)
	{
		psum[i] = psum[i - 1] + i;
	}

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	/*
		dp[2][2] = dp[1][0] + dp[1][1] + dp[1][2]
	*/
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % devider;
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++)
	{
		//sum += dp[n][i] % devider;
		sum = (sum + dp[n][i]) % devider;

	}
	cout << sum << '\n';

	return 0;
}