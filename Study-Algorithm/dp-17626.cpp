#include <bits/stdc++.h>
using namespace std;

/*
	��� �ڿ����� �� Ȥ�� �� ������ �������� ������ ǥ���� �� �ִٰ� �����Ͽ���
	� �ڿ����� ������ ������� ǥ���ȴ�
	26 = 5^2 + 1^2
	26 = 4^2 + 3^2 + 1^2
	n�� �ּ� ������ ������ ������ ǥ���ϴ� ��ǻ�� ���α׷�
	1 �� n �� 50,000

	25 = 5^2
	26 = 5^2 + 1^2
	11330 = 105^2 + 15^2 + 8^2 + 5^2
*/

int n;
int dp[50000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 4;
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}