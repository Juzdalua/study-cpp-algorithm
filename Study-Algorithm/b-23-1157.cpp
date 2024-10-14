#include <bits/stdc++.h>
using namespace std;

/*
	A ~ Z : 65~90
	a ~ z : 97~122
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	map<char, int> m;
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (s[i] > 90)
			s[i] -= 32;

		m[s[i]]++;
	}

	vector<pair<int, char>> result;
	for (auto& mm : m)
	{
		result.push_back({mm.second, mm.first});
		//cout << mm.first << " : " << mm.second << '\n';
	}

	sort(result.begin(), result.end(), [](pair<int, char>& a, pair<int,char> &b) {
		return a.first > b.first;
		});

	/*for (auto& r : result)
		cout << r.first << " : " << r.second << '\n';*/

	if (result.size() == 1)
		cout << result[0].second << '\n';
	else if(result.size() > 1 && result[0].first != result[1].first)
		cout << result[0].second << '\n';
	else if(result.size() > 1 && result[0].first == result[1].first)
		cout << "?" << '\n';


	return 0;
}