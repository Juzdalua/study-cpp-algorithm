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
	if (vv.size() == m)
	{
		for (int& i : vv)
			cout << i << " ";
		cout << '\n';
		return;
	}

	for (int i = idx + 1; i < n; i++)
	{
		vv.push_back(v[i]);
		combi(i-1, vv);
		vv.pop_back();
	}
}

bool Compare(int& a, int& b)
{
	return a <= b;
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