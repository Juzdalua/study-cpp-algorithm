#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long sum = i;
		string s = to_string(i);
		for (int j = 0; j < s.size(); j++)
		{
			sum += s[j] - '0';
		}

		if (sum == n)
		{
			cout << i << '\n';
			exit(0);
		}
	}

	cout << 0 << '\n';

	return 0;
}