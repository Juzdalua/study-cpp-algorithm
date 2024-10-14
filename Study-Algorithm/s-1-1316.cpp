#include <bits/stdc++.h>
using namespace std;

/*

*/

int n;
vector<string> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	int cnt = 0;
	for (string& s : v)
	{
		map<char, int> m;
		for (int i = 0; i < s.size(); i++)
		{
			char ch = s[i];
			m[ch]++;
			if (m[ch] != 1)
			{
				if (ch != s[i - 1])
					break;
			}

			if (i == s.size() - 1)
				cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}