#include <bits/stdc++.h>
using namespace std;

/*

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;
	cin >> n >> s;
	int sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		sum += s[i] - '0';
	}
	cout << sum << '\n';

	return 0;
}