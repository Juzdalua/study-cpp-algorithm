#include <bits/stdc++.h>
using namespace std;

/*

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int> m;
	int minNum = INT_MAX;
	int second = 0;

	for (int i = 1; i <= 30; i++)
	{
		m[i] = 0;
	}

	for (int i = 0; i < 28; i++)
	{
		int input;
		cin >> input;
		m[input]++;
	}
	
	/*for (auto& mm : m)
	{
		cout << mm.first << ", " << mm.second << '\n';
	}*/

	for (auto& mm : m)
	{
		if (mm.second == 0)
		{
			minNum = mm.first;
			mm.second = 1;
			break;
		}
	}
	
	for (auto& mm : m)
	{
		if (mm.second == 0)
		{
			second = mm.first;
			break;
		}
	}

	cout << minNum << '\n';
	cout << second << '\n';
	return 0;
}