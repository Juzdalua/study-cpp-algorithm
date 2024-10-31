#include <bits/stdc++.h>
using namespace std;

/*
	A = {10, 30, 10, 20, 20, 10}
	A = {30, 20, 10}  이고, 길이는 3
	1 ≤ N ≤ 1,000
	1 ≤ Ai ≤ 1,000
*/

int n;
int arr[1004];
int dp[1004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		//cout << dp[i] << " ";
		result = max(result, dp[i]);
	}

	cout << result << '\n';

	return 0;
}