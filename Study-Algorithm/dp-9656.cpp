#include <bits/stdc++.h>
using namespace std;

/*
	N개 돌
	상근이 창영이
	돌을 1개, 3개 가져갈수있다
	마지막 돌을 가져가는사람이 진다
	이기는 사람을 구하는 프로그램을 작성하시오. 게임은 상근이가 먼저 시작한다.

	1 ≤ N ≤ 1000
*/

int n;
const string sk = "SK";
const string cy = "CY";
string dp[1004] = { "0" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[n] = sk;
	dp[n - 1] = cy;
	
	while (true)
	{
		if (n == 1 || n == 3)
		{
			if(dp[n] == sk)
				cout << cy << '\n';
			else
				cout << sk << '\n';
			exit(0);
		}
		
		else if (n == 2)
		{
			cout << dp[n] << '\n';
			exit(0);
		}

		if (n > 3)
		{
			n -= 3;
			dp[n] = dp[n + 3] == sk ? cy : sk;
		}
	}
	


	return 0;
}