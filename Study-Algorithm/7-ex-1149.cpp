#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	���� N��
	1�������� N�������� ������� �������� �̾����ִ�.
	���� R,G,B �� �ϳ��� ĥ�Ѵ�.
	�Ʒ� ������ �����ϴ� �ּҰ�

	1���� ���� 2������ ���� �ʾƾ��Ѵ�.
	N���� ���� N-1������ ���� �ʾƾ��Ѵ�.
	2 <= i <= N-1 / i�� �� ���� i-1, i+1���� ���� �ʾƾ��Ѵ�.
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