#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int input;
		cin >> input;
		if (input < 40) input = 40;
		sum += input;
	}

	cout << sum / 5 << '\n';
	return 0;
}