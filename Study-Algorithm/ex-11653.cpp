#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n;
bool che[10'000'000];
vector<int> v;

void CHE()
{
	for (int i = 2; i <= n; i++)
	{
		if (che) continue;
		for (int j = i * 2; j <= n; j += i)
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

	cin >> n;
	CHE();

	while (n > 1)
	{
		for (int i = 2; i <= n; i++)
		{
			if (che[i]) continue;
			if (n % i == 0)
			{
				n /= i;
				v.push_back(i);
				break;
			}
		}
	}

	for (int& vv : v)
		cout << vv << '\n';

	return 0;
}