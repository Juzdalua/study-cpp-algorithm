#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> 
using namespace std;

/*
	다양한 포도주가 들어있는 잔이 일렬로 놓여있다
	시식에는 규칙이 있다

	1. 포도주 잔을 선택하면 그 잔을 모두 마셔야하고, 마신 후 원래 위치에 놓아야 한다
	2. 연속으로 놓여있는 3잔을 모두 마실 수 없다.
	최대한 많은 포도주를 마신다
	1번부터 n번까지 포도주잔이 순서대로 있다.
	각 포도주의 양이 주어진다.

	현재 잔을 마시지 않을 경우
	f(n) = f(n-1)

	현재 잔을 연속해서 마실 경우
	f(n) = f(n-3) + n-1 + n

	현재 잔을 연속해서 마시지 않을 경우
	f(n) = f(n-2) + n
*/

int n;
int grape[10'004];
int dp[10'004];

void Solution()
{
	dp[0] = 0;
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(max(dp[i - 1], dp[i - 3] + grape[i - 1] + grape[i]), dp[i - 2] + grape[i]);
	}

	/*for (int i = 1; i <= n; i++)
		cout << "i: " << i << ", dp[i]: " << dp[i] << endl;*/
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
		cin >> grape[i];
	}

	memset(dp, -1, sizeof(dp));
	Solution();

	return 0;
}