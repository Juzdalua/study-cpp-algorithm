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
//vector<string> dp[1'004];
map<string, int> dpm;
int maxLen = INT_MIN;

enum
{
	S1 = 0,
	S2 = 1
};

void combi(int start, int idx, int len, vector<char>& v, string& s, int type)
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

		if (type == S1)
		{
			//dp[start].push_back(s);
			dpm[s]++;
		}
		else
		{
			if (dpm[s] != 0)
			{
				//cout << "S -> " << s << '\n';
				maxLen = max(maxLen, static_cast<int>(s.size()));
			}
		}

		return;
	}

	for (int i = idx + 1; i < s.size(); i++)
	{
		v.push_back(s[i]);
		combi(start, i, len, v, s, type);
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
			combi(i, i, j, v, s1, S1);
		}
	}

	for (int i = 0; i < s1.size(); i++)
	{
		for (auto& s : dpm)
		{
			//cout << s << '\n';
			if (static_cast<int>(s.first.size()) <= maxLen) continue;

			for (int j = 0; j < s2.size(); j++)
			{
				char now = s2[j];
				vector<char> v;
				v.push_back(now);

				for (int k = 1; k <= s2.size() - j; k++)
				{
					combi(j, j, k, v, s2, S2);
				}
			}
		}
	}

	cout << maxLen << '\n';

	return 0;
}