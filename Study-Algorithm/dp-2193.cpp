#include <bits/stdc++.h>
using namespace std;

/*
	��ģ���� 0���� �������� �ʴ´�.
	��ģ�������� 1�� �� �� �������� ��Ÿ���� �ʴ´�. ��, 11�� �κ� ���ڿ��� ���� �ʴ´�.
	1, 10, 100, 101, 1000, 1001
	0010101, 101101

	1 �� N �� 90
	N�ڸ� ��ģ���� ������ ���ϴ� ���α׷�
*/

int n;
long long dp[94][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[1][1] = 1;
	dp[2][0] = 1;

	for (int i = 3; i <= 90; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1] << '\n';

	return 0;
}