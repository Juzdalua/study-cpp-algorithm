#include <bits/stdc++.h>
using namespace std;

/*
	자연수N 정수K
	nCk
	n! / k! * (n-k)!

	1 <= n <= 1'000
	0 <= k <= n

	(a*b)%c = a%c + b%c
*/

int n, k;
const int devider = 10'007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int up = 1;
	int down = 1;
	long long sum = 1;
	for (int i = 0; i < k; i++)
	{
		up = up * (n - i) % devider;
		down = down * (k - i) % devider;
		cout << "i: " << i << ", up: " << up << ", down: " << down << '\n';
	}
	sum = (up / down) % devider;
	if (sum == 0)
		sum = 1;
	cout << sum << '\n';

	return 0;
}