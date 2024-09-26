#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	계단 수
	45656 인접한 모든 자리의 차이가 1인 수

	길이가 N인 계단수는 몇개인가?
	0으로 시작하는 수는 계단수가 아니다

	1 2 3 4 5 6 7 8 9

	12 23 34 45 56 67 78 89 10
	21 32 43 54 65 76 87 98

	dp[2][0] = 1; // 10
	dp[2][1] = 1; // 21
	dp[2][2] = 2; // 12 32
	dp[2][3] = 2; // 23 43
	...
	dp[2][7] = 2; // 67 87
	dp[2][8] = 2; // 78 98
	dp[2][9] = 1; // 89

	dp[3][0] = 2; // 210 -> dp[2][1] +
	dp[3][1] = 3; // 121 321 101 -> dp[2][2] + dp[2][0]
	dp[3][2] = 3; // 232 432 212 -> dp[2][3] + dp[2][1]
	...
	dp[3][7] = 3; // 787 987 -> dp[2][8] +
	dp[3][8] = 3; // 898  678 878-> dp[2][9] + dp[2][7]
	dp[3][9] = 2; //  789 989 -> dp[2][8]

	dp[i][j] = dp[i-1][j+1]
	dp[i][j] = dp[i-1][j+1] + dp[i-1][j-1];
*/

int n;
long long dp[104][10];
const long long devider = 1'000'000'000;

void Solution()
{
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];

			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];

			else
				dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];

			dp[i][j] %= devider;
		}
	}

	long long sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) % devider;
	cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	Solution();

	return 0;
}