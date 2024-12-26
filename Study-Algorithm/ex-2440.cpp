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
	for (int i = n; i >=1; i--)
	{
		string s = "";
		for (int j = 0; j < i; j++)
		{
			s.push_back('*');
		}
		cout << s << '\n';
	}

	return 0;
}