#include <bits/stdc++.h>
using namespace std;

/*
	�ڿ��� N
	�۰ų� ���� ���������� ������ ��Ÿ�� �� �ִ�
	11=3^2+1^2+1^2(3�� ��)
	11=2^2+2^2+1^2+1^2+1^2(5�� ��)
	11�� �� �����ν� ǥ���� �� �ִ� ������ ���� �ּ� ������ 3

	1 �� N �� 100,000
*/

int n;
int dp[100'004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = INT_MAX;
	}
	
	for (int i = 1; pow(i,2) <= n; i++)
	{
		int next = pow(i, 2);
		for (int j = next; j <= n; j++)
		{
			dp[j] = min(dp[j], dp[j - next] + 1);
		}
	}

	cout << dp[n] << '\n';
	return 0;
}

