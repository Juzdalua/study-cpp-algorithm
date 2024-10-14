#include <bits/stdc++.h>
using namespace std;

/*

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	vector<string> r;
	while (getline(cin, s))
	{
		r.push_back(s);
	}

	for (string& rr : r)
		cout << rr << '\n';
	return 0;
}