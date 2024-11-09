#include <bits/stdc++.h>
using namespace std;

/*
	정육면체 상자
	상자마다 크기
	앞에 있는 상자의 크기가 뒤에있는 상자 크기보다 작으면 앞에있는 상자를 뒤에있는 상자에 넣을 수 있다

	1, 5, 2, 3, 7
	크기 1인 상자를 크기 5인 상자에 넣고, 다시 이 상자를 크기 7인 상자 안에 넣을 수 있다.

	한 번에 넣을 수 있는 최대의 상자 개수를 출력하는 프로그램
	1 ≤ n ≤ 1000
*/

int n;
int arr[1004];
int dp[1004];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 1;
	for (int i = 1; i < n;i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int res = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		//cout << "i: " << i << ", dp: " << dp[i] << '\n';
		res = max(dp[i], res);
	}
	cout << res << '\n';

	return 0;
}