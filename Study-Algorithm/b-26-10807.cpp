#include <bits/stdc++.h>
using namespace std;

/*
	1 ¡Â N ¡Â 100
*/

int n;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		m[input]++;
	}
	int v;
	cin >> v;

	cout << m[v] << '\n';

	return 0;
}