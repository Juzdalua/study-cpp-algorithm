#include <bits/stdc++.h>
using namespace std;

/*
	1 ¡Â N ¡Â 100
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string space = string(n - i, ' ');
		string star = string(i, '*');
		cout << space + star << '\n';
	}

	return 0;
}