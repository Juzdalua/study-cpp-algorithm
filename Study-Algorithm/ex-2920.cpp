#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	vector<int> temp = v;
	sort(temp.begin(), temp.end());
	for (int i = 0; i < 8; i++)
	{
		if (temp[i] != v[i]) break;

		if (i == 7)
		{
			cout << "ascending" << '\n';
			exit(0);
		}
	}

	reverse(temp.begin(), temp.end());
	for (int i = 0; i < 8; i++)
	{
		if (temp[i] != v[i]) break;

		if (i == 7)
		{
			cout << "descending" << '\n';
			exit(0);
		}
	}

	cout << "mixed" << '\n';

	return 0;
}