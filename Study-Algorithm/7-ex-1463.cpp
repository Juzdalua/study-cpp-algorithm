#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	정수 X에 사용할 수 있는 연산
	X가 3으로 나누어 떨어지면 3으로 나눈다
	X가 2로 나누어 떨어지면 2로 나눈다
	1을 뺸다

	1을 만들어야한다
	연산을 사용하는 최소값
	1 <= n <= 10^6

	2 -> 1 = 1
	10 -> 9 -> 3 -> 1 = 3
	10 -> 5 -> 4 -> 2 -> 1 = 4
	10 -> 5 -> 4 -> 3 -> 1 = 4
*/


int n;
int dp[1'000'004];
const int INF = 987654321;

int Go(int x)
{
	/*if (x == 1)
		return 0;

	if (dp[x] != INF)
		return dp[x];*/

	if (x == 1 || dp[x] != INF)
		return dp[x];

	if (x % 3 == 0)
		dp[x] = min(dp[x], Go(x / 3) + 1);

	if (x % 2 == 0)
		dp[x] = min(dp[x], Go(x / 2) + 1);

	dp[x] = min(dp[x], Go(x - 1) + 1);

	return dp[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	fill(dp, dp + n + 1, INF);
	dp[1] = 0;

	int result = Go(n);
	cout << result << '\n';

	return 0;
}