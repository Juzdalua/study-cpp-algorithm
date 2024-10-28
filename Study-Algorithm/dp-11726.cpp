#include <bits/stdc++.h>
using namespace std;

/*
	2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	���� 2, ���� n

	1 �� n �� 1,000
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