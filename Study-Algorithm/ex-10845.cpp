#include <bits/stdc++.h>
using namespace std;

/*

*/

int n;
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;

		if (s == "push")
		{
			int input;
			cin >> input;
			q.push(input);
		}
		else if (s == "pop")
		{
			if (q.empty()) cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s == "size")
		{
			cout << q.size() << '\n';
		}
		else if (s == "empty")
		{
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "front")
		{
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (s == "back")
		{
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}

	return 0;
}