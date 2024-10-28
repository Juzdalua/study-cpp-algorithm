#include <bits/stdc++.h>
using namespace std;

/*
	n을 1, 2, 3의 합으로 나타내는 방법의 수

	n = 4 -> 7
	1+1+1+1
	1+1+2
	1+2+1
	2+1+1
	2+2
	1+3
	3+1

	0 < n < 11
*/

int n, t;
int dp[15];
vector<int> result;

void Solution()
{
	result.push_back(dp[n]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i=4; i<=11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		Solution();
	}

	for (int& r : result)
		cout << r << '\n';

	return 0;
}