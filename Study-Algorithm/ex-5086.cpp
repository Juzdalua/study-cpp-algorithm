#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		if (b % a == 0) {
			cout << "factor" << '\n';
			continue;
		}
		else if (a % b == 0)
		{
			cout << "multiple" << '\n';
			continue;
		}
		else {
			cout << "neither" << '\n';
			continue;
		}
	}

	return 0;
}