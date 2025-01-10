#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n;
long long dp[504][2];

pair<int, int> facWithoutZero(int num)
{
	if (num == 0 || num == 1) return { 1,0 };
	if (dp[num][0] != 1) return { dp[num][0],dp[num][1] };

	long long& res = dp[num][0];
	res = facWithoutZero(num - 1).first * num;

	long long& zero = dp[num][1];
	zero = dp[num - 1][1];

	// 0 없애기
	while (res % 10 == 0)
	{
		res /= 10;
		zero++;
	}

	// 자리수 줄이기
	while (true)
	{
		string s = to_string(res);
		if (s.size() <= 2) break;
		if (s.front() != '0')
		{
			s[0] = '0';
			res = stoi(s);
		}
		else break;
	}
	//res %= 100;

	return { res, zero };
}

void Solution()
{
	for (int i = 0; i <= n; i++)
	{
		if (dp[i][0] == 0) dp[i][0] = 1;
		facWithoutZero(i);
		//cout<<i<<"-> " << dp[i][0] << ", " << dp[i][1] << '\n';
	}

	long long num = dp[n][0];
	long long result = dp[n][1];

	//if (num % 10 == 0) result++;

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	//Solution();

	int result = 0;
	for (int i = 5; i <= n; i *= 5)
	{
		result += n / i;
	}
	cout << result << '\n';

	return 0;
}