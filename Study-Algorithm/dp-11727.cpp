#include <bits/stdc++.h>
using namespace std;

/*
	1 ¡Â n ¡Â 1,000
*/

const int devider = 10'007;
long long dp[10'004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= 1000; i++)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % devider;
	}

	int n;
	cin >> n;
	cout << dp[n] << '\n';

	return 0;
}