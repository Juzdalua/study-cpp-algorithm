#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

map<int, int> mx;
map<int, int> my;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		mx[x]++;
		my[y]++;
	}

	int x = 0;
	int y = 0;
	for (auto& mm : mx)
	{
		if (mm.second % 2 != 0) {
			x = mm.first;
		}
	}
	for (auto& mm : my)
	{
		if (mm.second % 2 != 0) {
			y = mm.first;
		}
	}
	cout << x << " " << y << '\n';
	return 0;
}