#include <bits/stdc++.h>
using namespace std;

/*
	0과 1로 시작
	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
	f(n) = f(n-1) + f(n-2)

	n은 90보다 작거나 같은 자연수
*/

int n;
unsigned long long dp[100];

unsigned long long fibo(int num)
{
	//cout << "Fibo -> " << num << '\n';
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;

	if (dp[num] != 0)
		return dp[num];

	return dp[num] = fibo(num - 1) + fibo(num - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << fibo(n) << '\n';

	return 0;
}