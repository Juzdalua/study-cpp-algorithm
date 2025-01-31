#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int result = INT_MIN;
pair<int, int> pos;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int input;
			cin >> input;
			result = max(result, input);
			if (result == input)
			{
				pos = { i,j };
			}
		}
	}

	cout << result << '\n';
	cout << pos.first + 1 << " " << pos.second + 1 << '\n';

	return 0;
}