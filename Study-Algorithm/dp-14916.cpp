#include <bits/stdc++.h>
using namespace std;

/*
	2�� 5�� �Ž�����
	���Ѱ�
	������ ������ �ּҷ� �Ž����ش�
	15 = 5*3 -> 3
	14 = 5*2 + 2*2 -> 4
	13 = 5*1 + 2*4 -> 5

	1 �� n �� 100,000
	���� �Ž��� �� �� ������ -1�� ���
*/

int n;
int dp[100004];

void Solution()
{
	dp[0] = -1;
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = dp[2] + 1;
	dp[5] = 1;

	for (int i = 6; i <= n; i++)
	{
		if (dp[i - 2] != -1)
			dp[i] = dp[i - 2] + 1;

		if (dp[i - 5] != -1)
			dp[i] = min(dp[i], dp[i - 5] + 1);
	}

	cout << dp[n] << '\n';
	exit(0);
}

void Solution2()
{
	int result = 0;
	while (true)
	{
		if (n == 1)
		{
			cout << -1 << '\n';
			exit(0);
		}
		if (n % 5 == 0)
		{
			result += n / 5;
			cout << result << '\n';
			exit(0);
		}
		
		n -= 2;
		result++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	//Solution();
	Solution2();

	return 0;
}