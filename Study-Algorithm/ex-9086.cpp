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
	while (n--)
	{
		string s;
		cin >> s;
		if (s.size() == 1) cout << s.back() << s.back() << '\n';
		else cout << s.front() << s.back() << '\n';
	}

	return 0;
}