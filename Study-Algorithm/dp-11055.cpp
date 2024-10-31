#include <bits/stdc++.h>
using namespace std;

/*
	A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8}
	A = {1, 2, 50, 60}

	1 ¡Â N ¡Â 1,000
	1 ¡Â Ai ¡Â 1,000
*/

int n;
int arr[1004];
long long dp[1004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <i; j++)
		{
			if(arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
	}
	
	long long maxDp = 0;
	for (int i = 1; i <= n; i++)
	{
		//cout << dp[i] << " ";
		maxDp = max(maxDp, dp[i]);
	}

	cout << maxDp << '\n';

	return 0;
}