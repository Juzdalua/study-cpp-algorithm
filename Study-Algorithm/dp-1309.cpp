#include <bits/stdc++.h>
using namespace std;

/*
	1≤N≤100,000
	N * 2
	가로두칸 세로N칸
	사자를 가로, 세로에 인접하게 가둘수 없다.
	사자를 배치하는 경우의 수가 몇 가지인지를 알아내는 프로그램

	사자를 한 마리도 배치하지 않는 경우도 하나의 경우의 수
*/

int n;
long long dp[100'004][3]; // 0-없음, 1-왼쪽, 2-오른쪽
const int devider = 9901;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < 3; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] % devider + dp[i - 1][1] % devider + dp[i - 1][2] % devider;
		dp[i][1] = dp[i - 1][0] % devider + dp[i - 1][2] % devider;
		dp[i][2] = dp[i - 1][0] % devider + dp[i - 1][1] % devider;
	}

	long long result = 0;
	for (int i = 0; i < 3; i++)
		result = (result + dp[n][i]) % devider;

	cout << result << '\n';

	return 0;
}