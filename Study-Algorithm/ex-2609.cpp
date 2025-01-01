#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

long long a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	long long large = min(a, b);

	while (large > 0)
	{
		if (a % large == 0 && b % large == 0) break;
		large--;
	}

	cout << large << '\n';
	cout << (a / large) * (b / large) * large << '\n';

	return 0;
}