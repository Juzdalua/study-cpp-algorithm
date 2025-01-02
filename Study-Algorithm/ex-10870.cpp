#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n;

int fibo(int start)
{
	if (start == 0 || start == 1) return start;

	return fibo(start - 1) + fibo(start - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << fibo(n) << '\n';

	return 0;
}