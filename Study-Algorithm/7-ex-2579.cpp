#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
	����� ������ �ش� ������ ��´�
	1ĭ, 2ĭ �� ���� �� �ִ�
	���ӵ� ������ ĭ ���� �� ����
	������ ����� ��ƾ��Ѵ�
	O: 1 -> 2 or 3
	X: 1 -> 2 > 3
	X: 1 -> 4
	������ �ִ�

	f(n) = max(f(n-1), f(n-2)) + stair[i];
	
	2��� + 1���
	f(n) = f(n-2) + stair[i]


	f(n) = f(n-3) + stair[i-1] + stair[i];

	
	
*/

int n;
int stair[304];
int dp[304];

void Solution()
{
	dp[1] = stair[1];
	dp[2] = dp[1] + stair[2];
	dp[3] = max(stair[1], stair[2]) + stair[3];

	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i-2], dp[i-3] + stair[i-1]) + stair[i];
	}

	cout << dp[n] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
	}

	Solution();


	return 0;
}