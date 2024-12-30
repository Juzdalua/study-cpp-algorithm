#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n;

void Solution1(vector<int>& v)
{
	sort(v.begin(), v.end());
	for (int& i : v)
	{
		cout << i << '\n';
	}
}

void Solution2(map<int, int>& m)
{
	for (auto& mm : m)
	{
		for (int i = 0; i < mm.second; i++)
		{
			cout << mm.first << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> v;
	map<int, int>m;

	while (n--)
	{
		int input;
		cin >> input;

		//v.push_back(input);
		m[input]++;
	}

	//Solution1(v);
	Solution2(m);

	return 0;
}