#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	집이 N개
	1번집부터 N번집까지 순서대로 선분으로 이어져있다.
	집은 R,G,B 중 하나로 칠한다.
	아래 조건을 만족하는 최소값

	1번집 색은 2번집과 같지 않아야한다.
	N번집 색은 N-1번집과 같지 않아야한다.
	2 <= i <= N-1 / i번 집 색은 i-1, i+1집과 같지 않아야한다.
	2 <= N <= 1'000
*/

int n;
int r[1'004];
int g[1'004];
int b[1'004];
int dp[1'004][3]; // n, RGB -> min
const int INF = 987654321;

void Solution()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	dp[1][0] = r[0];
	dp[1][1] = g[0];
	dp[1][2] = b[0];

	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i - 1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i - 1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i - 1];
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> r[i] >> g[i] >> b[i];
	}

	Solution();

	return 0;
}