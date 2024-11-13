#include <bits/stdc++.h>
using namespace std;

/*
	화면에 A
	A -> BA -> BAB -> BABBA
	
	B -> BA
	A -> B

	k번 누르면 A와 B의 갯수는?
	1 ≤ K ≤ 45
*/

int k;
int dp[50][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	dp[0][0] = 1;

	for (int i = 1; i <= k; i++)
	{
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
	}

	cout << dp[k][0] << " " << dp[k][1] << '\n';

	return 0;
}