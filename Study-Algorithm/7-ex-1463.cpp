#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	���� X�� ����� �� �ִ� ����
	X�� 3���� ������ �������� 3���� ������
	X�� 2�� ������ �������� 2�� ������
	1�� �A��

	1�� �������Ѵ�
	������ ����ϴ� �ּҰ�
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