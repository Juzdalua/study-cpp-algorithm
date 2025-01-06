#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, m;
map<int, int> nm;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		nm[input]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < m; i++)
	{
		if (nm[v[i]] == 1) cout << 1 << " ";
		else cout << 0 << " ";
	}

	return 0;
}