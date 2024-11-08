#include <bits/stdc++.h>
using namespace std;

/*
	정수 n을 나타내는 방법

	n=4 -> 7
	1+1+1+1
	1+2+1
	2+1+1
	3+1

	1+1+2
	2+2

	1+3

	0 <= n <= 1,000,000
*/

int n, t;
vector<int> v;
int maxN = INT_MIN;
const int devider = 1'000'000'009;
int dp[1'000'004][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		int input;
		cin >> input;
		v.push_back(input);
		maxN = max(maxN, input);
	}

	n = maxN;

	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 2;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			/*dp[i][1] += dp[i - 1][j];
			dp[i][2] += dp[i - 2][j];
			dp[i][3] += dp[i - 3][j];*/

			dp[i][1] = dp[i][1] % devider + dp[i - 1][j] % devider;
			dp[i][2] = dp[i][2] % devider + dp[i - 2][j] % devider;
			dp[i][3] = dp[i][3] % devider + dp[i - 3][j] % devider;
		}
	}

	for (int vv : v)
	{
		long long result = 0;
		for (int i = 1; i <= 3; i++)
		{
			result = result % devider + dp[vv][i] % devider;
		}

		cout << result % devider << '\n';
	}

	return 0;
}