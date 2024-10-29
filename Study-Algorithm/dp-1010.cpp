#include <bits/stdc++.h>
using namespace std;

/*
	서쪽 n개의 사이트
	동쪽 m개의 사이트
	한 사이트에는 최대 한 개의 다리만 연결될 수 있다

	다리를 최대한 많이 지으려고한다.
	서쪽의 사이트 개수만큼 (N개) 다리를 지으려고 한다

	0 < N ≤ M < 30
*/

int n, m, t;

long long Go()
{
	long long result = 1;

	for (int i = 0; i < n; i++)
	{
		result *= (m - i);
		result /= i + 1;
	}

	return result;
}

void Solution()
{
	long long res = Go();
	cout << res << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		Solution();
	}

	return 0;
}