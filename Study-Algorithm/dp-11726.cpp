#include <bits/stdc++.h>
using namespace std;

/*
	2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
	세로 2, 가로 n

	1 ≤ n ≤ 1,000
*/

const int devider = 10'007;
int n;
long long dp[1004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % devider;

	cin >> n;
	cout << dp[n];
	return 0;
}