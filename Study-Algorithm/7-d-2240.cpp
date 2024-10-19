#include <bits/stdc++.h>
using namespace std;

/*
	자두를 심고 먹는다
	자두까 떨어지면 받아먹는다
	자두가 바닥에 떨어지기 전 허공에 있을 떄 잡아야한다

	매 초, 두개 나무중 하나의 나무에서 자두가 떨어진다
	만약 열매가 떨어지는 순간, 자두가 그 나무의 아래에 서 있으면 자두는 그 열매를 받아먹을 수 있다.
	자두는 하나의 나무 아래에 서 있다가 다른 나무 아래로 빠르게(1초보다 훨씬 짧은 시간에) 움직일 수 있다.

	자두는 T초동안 떨어진다
	자두는 최대 W번 움직인다
	1≤T≤1,000
	1≤W≤30

	자두가 받을 수 있는 자두의 최대 개수를 출력한다
	자두는 1번 자두나무 아래에 위치해 있다고 한다.
*/

int t, w;
int arr[1'004];
int maxResult = INT_MIN;
int dp[1'004][4][34]; // [T][location][W]

void Go(int cnt, int sum, int location)
{
	//cout << "Start -> Count: " << cnt << ", Sum: " << sum << ", Location: " << location << '\n';
	if (cnt >= t)
	{
		maxResult = max(maxResult, sum);
		return;
	}

	int jadu = arr[cnt];

	for (int i = 0; i < 2; i++)
	{
		//cout << "i: " << i << '\n';
		if (i == 1)
		{
			if (location == 1)
				location = 2;
			else if (location == 2)
				location = 1;
		}

		if (location == jadu)
			sum++;
		Go(cnt + 1, sum, location);
		if (location == jadu)
			sum--;
	}
}

int Go2(int cnt, int location, int moveCount)
{
	if (cnt >= t)
		return 0;

	if (dp[cnt][location][moveCount] != -1)
		return dp[cnt][location][moveCount];

	int jadu = arr[cnt];
	int& result = dp[cnt][location][moveCount];

	for (int i = 0; i < 2; i++)
	{
		if (i == 1 && moveCount < w)
		{
			if (location == 1)
				location = 2;
			else
				location = 1;
			moveCount++;
		}
		if (location == jadu)
			result = max(result, 1 + Go2(cnt + 1, location, moveCount));
		else
			result = max(result, Go2(cnt + 1, location, moveCount));
	}

	// 이동하지 않고
	//if (location == jadu)
	//	result = 1 + Go2(cnt + 1, location, moveCount);
	//else
	//	result = Go2(cnt + 1, location, moveCount);

	//// 이동하고
	//if (moveCount < w)
	//{
	//	if (location == 1)
	//		location = 2;
	//	else
	//		location = 1;

	//	if (location == jadu)
	//		result = max(result, 1 + Go2(cnt + 1, location, moveCount + 1));
	//	else
	//		result = max(result, Go2(cnt + 1, location, moveCount + 1));
	//}

	return result;
}

void Solution()
{
	//Go(1, 0, 1);
	//cout << maxResult << '\n';

	memset(dp, -1, sizeof(dp));
	int result = Go2(0, 1, 0);
	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t >> w;
	for (int i = 0; i < t; i++)
	{
		cin >> arr[i];
	}

	Solution();

	return 0;
}