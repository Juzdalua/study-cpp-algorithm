#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, m;
bool che[10'004];
int minVal;
long long sum;

void CHE()
{
	che[0] = che[1] = true;
	for (int i = 2; i <= n; i++)
	{
		if (che[i]) continue;

		for (int j = i * 2;j <= n; j += i)
		{
			che[j] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	CHE();

	for (int i = m; i <= n; i++)
	{
		if (!che[i])
		{
			if (minVal == 0) minVal = i;
			sum += i;
		}
	}

	if (minVal == 0) {
		cout << -1 << '\n';
		exit(0);
	}
	cout << sum << '\n' << minVal << '\n';

	return 0;
}