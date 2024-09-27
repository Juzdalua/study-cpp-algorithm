#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	수열 A가 주어진다
	가장 긴 부분 수열을 구한다
	A = {10, 20, 10, 30, 20, 50} -> 10, 20, 30, 50 = 4

	11
	100 1 2 3 101 4 5 6 102 7 8
	=> 8

	첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
	둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
*/

int n;
int a[1'004];
int dp[1'004];
vector<int> result;

int Go(int idx)
{
	if (dp[idx] != -1)
		return dp[idx];

	dp[idx] = 1;

	for (int i = idx + 1; i < n; i++)
	{
		if (a[i] > a[idx])
			dp[idx] = max(dp[idx], Go(i) + 1);
	}

	return dp[idx];
}

void Solution()
{
	memset(dp, -1, sizeof(dp));

	int maxLen = 0;
	for (int i = 0; i < n; i++)
	{
		maxLen = max(maxLen, Go(i));
	}

	/*for (int i = 0; i < n; i++)
		cout << dp[i] << " ";*/
	cout << maxLen << '\n';
}

void BottomUp()
{
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	/*for (int i = 0; i < n; i++)
		cout << dp[i] << " ";*/
	int maxLength = *max_element(dp, dp + n);
	cout << maxLength << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	//Solution();
	BottomUp();

	return 0;
}