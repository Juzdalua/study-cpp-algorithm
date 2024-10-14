#include <bits/stdc++.h>
using namespace std;

/*
	1~6 주사위 3개
	1. 같은 눈이 3개가 나오면 10'000 + 숫자*1'000
	2. 같은 눈이 2개가 나오면 1'000 + 숫자*100
	3. 모두 다른 눈이 나오면 가장 큰숫자 * 100


*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	map<int, int> m;
	m[a]++;
	m[b]++;
	m[c]++;

	int sum = 0;
	if (m.size() == 1)
	{
		sum = 10'000 + (a * 1'000);
	}
	else if (m.size() == 2)
	{
		int r = 0;
		if (m[a] == 2)
			r = a;
		else if (m[b] == 2)
			r = b;
		else
			r = c;

		sum = 1'000 + (r * 100);
	}
	else
	{
		int r = 0;
		r = max(r, a);
		r = max(r, b);
		r = max(r, c);

		sum = r * 100;
	}
	cout << sum << '\n';

	return 0;
}