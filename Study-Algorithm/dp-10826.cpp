#include <bits/stdc++.h>
using namespace std;

/*
	f(0) = 0, f(1) = 1
	f(n) = f(n-1) + f(n-2)

	n=10-> 55
	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55

	n=17-> 55
	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

	0 <= n <= 10'000
*/

int n;
string dp[10'004] = { "0" };

void fibo()
{
	for (int i = 2; i <= n; i++)
	{
		string ex1 = dp[i - 1];
		string ex2 = dp[i - 2];
		int exSize = ex1.size();
		//cout << '\n' << "i: " << i << ", ex1: " << ex1 << ", ex2: " << ex2 << '\n';

		int updateNum = 0;
		for (int j = 0; j < exSize; j++)
		{
			int num = ex1.back() - '0';
			ex1.pop_back();

			if (ex2.size() > 0)
			{
				num += ex2.back() - '0';
				ex2.pop_back();
			}

			if (updateNum)
			{
				num++;
				updateNum = 0;
			}

			if (num >= 10)
			{
				updateNum++;
				num %= 10;
			}

			dp[i].push_back(to_string(num)[0]);
			//cout << "num: " << num << '\n';
			//cout << "dp: " << dp[i] << '\n';
		}
		if (updateNum)
		{
			dp[i].push_back('1');
		}
		reverse(dp[i].begin(), dp[i].end());

		//dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dp[1] = "1";
	fibo();
	cout << dp[n] << '\n';

	return 0;
}