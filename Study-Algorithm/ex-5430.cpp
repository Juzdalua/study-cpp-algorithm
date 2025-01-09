#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int t;

deque<int> ConvertToArrFromStr(string& s)
{
	deque<int> arr;
	if (s.size() == 0) return arr;

	auto start = 1;
	auto end = s.find(",", start);
	while (end != string::npos)
	{
		string numStr = s.substr(start, end - start);
		start = end + 1;
		end = s.find(",", start);
		arr.push_back(stoi(numStr));
	}

	if (start != 1)
	{
		string numStr = s.substr(start, s.size() - 1 - start);
		arr.push_back(stoi(numStr));
	}

	return arr;
}

deque<int> ConvertToDequeFromStr(string& s)
{
	deque<int> dq;


	string numStr = "";

	for (int i = 1; i < s.size(); i++)
	{
		if (isdigit(s[i])) numStr += s[i];
		else if (!numStr.empty())
		{
			dq.push_back(stoi(numStr));
			numStr = "";
		}
	}

	return dq;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n;
		cin >> n;
		string arrStr;
		cin >> arrStr;

		bool errorFlag = false;
		bool isReverse = false;
		deque<int> v = ConvertToDequeFromStr(arrStr);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R' && v.size() > 0) isReverse = !isReverse;
			else if (s[i] == 'D')
			{
				if (v.size() == 0)
				{
					cout << "error" << '\n';
					errorFlag = true;
					break;
				}

				if (isReverse) v.pop_back();
				else v.pop_front();
			}
		}

		if (errorFlag) continue;

		cout << "[";
		if (!isReverse)
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i];
				if (i != v.size() - 1) cout << ",";
			}
		}
		else
		{
			for (int i = v.size() - 1; i >= 0; i--)
			{
				cout << v[i];
				if (i != 0) cout << ",";
			}
		}
		cout << "]" << '\n';
	}

	return 0;
}