#include <bits/stdc++.h>
using namespace std;

/*

*/

int n;
vector<int> v;

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
		if (s == "push_back")
		{
			int input;
			cin >> input;
			v.push_back(input);
		}
		else if (s == "push_front")
		{
			reverse(v.begin(), v.end());
			int input;
			cin >> input;
			v.push_back(input);
			reverse(v.begin(), v.end());
		}
		else if (s == "pop_front")
		{
			if (v.empty())
				cout << -1 << '\n';
			else
			{
				reverse(v.begin(), v.end());
				int num = v.back();
				v.pop_back();
				cout << num << '\n';
				reverse(v.begin(), v.end());
			}
		}
		else if (s == "pop_back")
		{
			if (v.empty())
				cout << -1 << '\n';
			else
			{
				int num = v.back();
				v.pop_back();
				cout << num << '\n';
			}
		}
		else if (s == "size")
		{
			cout << v.size() << '\n';
		}
		else if (s == "empty")
		{
			if(v.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "front")
		{
			if (v.empty())
				cout << -1 << '\n';
			else
			{
				int num = v[0];
				cout << num << '\n';
			}
		}
		else if (s == "back")
		{
			if (v.empty())
				cout << -1 << '\n';
			else
			{
				int num = v.back();
				cout << num << '\n';
			}
		}
	}

	return 0;
}