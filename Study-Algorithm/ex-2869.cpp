#include <bits/stdc++.h>
using namespace std;

/*

*/

long long a, b, v;
long long day, h;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> v;
	long long cnt = v / (a - b);

	cnt -= a;
	long long curH = cnt * (a - b);

	while (true)
	{
		cnt++;
		curH += a;
		if (curH >= v)
			break;
		curH -= b;
	}

	cout << cnt << '\n';

	return 0;
}