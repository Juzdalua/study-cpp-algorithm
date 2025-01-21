#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, m;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	v.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int input1, input2;
		cin >> input1 >> input2;

		swap(v[input1], v[input2]);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}