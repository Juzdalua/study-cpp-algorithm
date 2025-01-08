#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|

	A C A Y K P
	C A P C A K
*/

string s1, s2;
vector<string> dp[1'004];
int maxLen = INT_MIN;

void combi(int start, int idx, int len, vector<char>& v, string& s)
{
	if (v.size() == len)
	{
		string s = "";
		for (auto& vv : v)
		{
			s.push_back(vv);
			//cout << vv << " ";
		}
		//cout << '\n';
		
		dp[start].push_back(s);

		return;
	}

	for (int i = idx + 1; i < s.size(); i++)
	{
		v.push_back(s[i]);
		combi(start, i, len, v, s1);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++)
	{
		char now = s1[i];
		vector<char> v;
		v.push_back(now);

		for (int j = 1; j <= s1.size() - i; j++)
		{
			combi(i, i, j, v, s1);
		}
	}

	for (int i = 0; i < s1.size(); i++)
	{
		for (auto& s : dp[i])
		{
			cout << s << '\n';

			if (s.size() <= maxLen) continue;


			maxLen = max(maxLen, static_cast<int>(s.size()));
		}
	}

	return 0;
}