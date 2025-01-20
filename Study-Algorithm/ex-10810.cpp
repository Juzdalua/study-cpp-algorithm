#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, m;
map<int, int> mm;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		mm[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j <= b; j++)
		{
			if (mm[j] != 0) mm[j] = 0;
			mm[j] = c;
		}
	}

	for (auto& i : mm)
	{
		cout << i.second << " ";
	}
	cout << '\n';

	return 0;
}