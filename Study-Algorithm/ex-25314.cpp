#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n;
const string LONG = "long ";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	string s = "";
	for (int i = 0; i < n / 4; i++)
	{
		s += LONG;
	}
	s += "int";
	cout << s << '\n';

	return 0;
}