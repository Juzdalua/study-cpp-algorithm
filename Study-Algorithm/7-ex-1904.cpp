#include <iostream>
using namespace std;

/*
	0 또는 1 낱장의 타일
	1 또는 00 타일

	크기가 N인 2진수열 -> 00, 11
	=> 01, 10 불가능
	N = 1 -> 1
	N = 2 -> 00, 11
	N = 3 -> 100, 001, 000
	N = 4 -> 0011, 0000, 1100, 1111, 1001

	타일은 무한히 많다.
	N이 주어졌을 때, 만들 수 있는 모든 가짓수
	1 <= N <= 1'000'000
*/

int n;
const int devider = 15746;
int dp[1'000'004];

void Solution()
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		// i-1에 1 붙이기 + i-2에 00 붙이기
		dp[i] = (dp[i - 1] + dp[i - 2]) % devider;
	}

	cout << dp[n] << '\n'; // dp[n]은 N길이의 수열의 개수
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