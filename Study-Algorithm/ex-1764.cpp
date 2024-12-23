#include <bits/stdc++.h>
using namespace std;

/*

*/

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	map<string, int> mm;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		mm[s]++;
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		mm[s]++;
	}

	vector<string> v;
	for (auto& mmm : mm)
	{
		if (mmm.second == 2)
		{
			//cout << mmm.first << '\n';
			v.push_back(mmm.first);
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (string& s : v)
		cout << s << '\n';

	return 0;
}