#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
			7
		  3   8
		8   1   0
	  2   7   4   4
	4   5   2   6   5

	선택된 수의 합이 최대
*/

int n;
vector<vector<int>> triangle;
int dp[504][504];
int maxSum = 0;

void Solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;
	}

	dp[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + triangle[i][j];

			else if (j == i)
				dp[i][j] = dp[i - 1][j-1] + triangle[i][j];

			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}
	for (int j = 0; j < n; j++) 
		maxSum = max(maxSum, dp[n - 1][j]);
	
	cout << maxSum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	cin >> n;
	int i = 1;
	while (true)
	{
		int input;
		cin >> input;
		v.push_back(input);
		if (v.size() == i)
		{
			triangle.push_back(v);
			v.clear();
			i++;
		}

		if (triangle.size() == n)
			break;
	}

	Solution();

	return 0;
}