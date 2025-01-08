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

void combi(int idx, vector<int>& vv)
{
	if (m == vv.size())
	{
		for (int& vvv : vv)
			cout << vvv << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		vv.push_back(v[i]);
		combi(i, vv);
		vv.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	vector<int> vv;
	combi(-1, vv);

	return 0;
}