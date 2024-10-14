#include <bits/stdc++.h>
using namespace std;

/*

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int aa = stoi(a);
	int bb = stoi(b);
	int result = max(aa, bb);
	cout << result << '\n';

	return 0;
}