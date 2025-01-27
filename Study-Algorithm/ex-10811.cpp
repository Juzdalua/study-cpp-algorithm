#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, m;
vector<int > v;

void Print()
{
	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << " ";
	}
	cout << '\n';
}

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
		int a, b;
		cin >> a >> b;
		reverse(v.begin() + a, v.begin() + b+1);
		//Print();
		
	}
	Print();

	return 0;
}