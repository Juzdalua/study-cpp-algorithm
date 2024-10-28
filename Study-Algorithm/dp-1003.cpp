#include <bits/stdc++.h>
using namespace std;

/*
	0 <= n <= 40
*/

int n, t;
vector<pair<int, int>> result;
pair<int, int> dp[44];

void Solution()
{
	result.push_back(dp[n]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0] = { 1,0 };
	dp[1] = { 0,1 };
	for (int i = 2; i <= 40; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		Solution();
	}

	for (auto& r : result)
		cout << r.first << " " << r.second << '\n';

	return 0;
}