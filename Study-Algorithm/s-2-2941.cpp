#include <bits/stdc++.h>
using namespace std;

/*

*/

vector<string> v = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
string s;

bool Check(string ss)
{
	//cout << "START -> " << ss << '\n';
	for (string& vv : v)
	{
		if (ss == vv)
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	int sum = 0;
	int check = 0;
	if (s.size() > 1)
	{
		for (int i = 0; i < s.size() - 1; i++)
		{
			string ss = "";
			ss.push_back(s[i]);
			ss.push_back(s[i + 1]);
			if (Check(ss))
			{
				if (i > 0 && ss == "z=" && s[i - 1] == 'd')
					continue;
				//cout << ss << '\n';
				sum++;
				check += 2;
			}
		}
	}

	if (s.size() > 2)
	{
		for (int i = 0; i < s.size() - 2; i++)
		{
			string ss = "";
			ss.push_back(s[i]);
			ss.push_back(s[i + 1]);
			ss.push_back(s[i + 2]);
			if (Check(ss))
			{
				//cout << ss << '\n';
				sum++;
				check += 3;
			}
		}
	}

	/*cout << s.size() << '\n';
	cout << check << '\n';
	cout << sum << '\n';*/

	sum += s.size() - check;
	cout << sum << '\n';

	return 0;
}