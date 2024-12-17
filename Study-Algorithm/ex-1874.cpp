#include <bits/stdc++.h>
using namespace std;

/*
	1 2 3 4 5
*/

int n;
vector<char> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	queue<int> q;
	stack<int> s;

	while (n--)
	{
		int input;
		cin >> input;
		q.push(input);
	}

	int idx = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		while (true)
		{
			if (s.size() == 0)
			{
				s.push(idx);
				idx++;
				result.push_back('+');
				//cout << "+" << '\n';
				continue;
			}

			int num = s.top();
			if (num == now)
			{
				s.pop();
				result.push_back('-');
				//cout << "-" << '\n';
				break;
			}
			else if (num < now)
			{
				s.push(idx);
				idx++;
				result.push_back('+');
				//cout << "+" << '\n';
				continue;
			}
			else
			{
				cout << "NO" << '\n';
				exit(0);
			}
		}
	}
	
	for (char& c : result)
		cout << c << '\n';

	return 0;
}