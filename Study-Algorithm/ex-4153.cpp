#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

const string OK = "right";
const string NO = "wrong";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0) break;

		int maxV = max(a, b);
		maxV = max(maxV, c);
		long long sum = 0;
		for (long long i : {a,b,c})
		{
			if (i == maxV) continue;
			sum += pow(i, 2);
		}

		if (pow(maxV, 2) == sum) cout << OK << '\n';
		else cout << NO << '\n';
	}

	return 0;
}