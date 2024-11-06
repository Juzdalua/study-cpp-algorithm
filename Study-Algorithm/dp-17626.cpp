#include <bits/stdc++.h>
using namespace std;

/*
	모든 자연수는 넷 혹은 그 이하의 제곱수의 합으로 표현할 수 있다고 증명하였다
	어떤 자연수는 복수의 방법으로 표현된다
	26 = 5^2 + 1^2
	26 = 4^2 + 3^2 + 1^2
	n을 최소 개수의 제곱수 합으로 표현하는 컴퓨터 프로그램
	1 ≤ n ≤ 50,000

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