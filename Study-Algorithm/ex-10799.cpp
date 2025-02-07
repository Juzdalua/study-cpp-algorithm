#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

string str;
stack<char> s;
int result, numOfPipe;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
		((
		()
		))
		)(
	*/
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		s.push(str[i]);
	}


	while (!s.empty())
	{
		char now = s.top();
		s.pop();

		if (now == ')')
		{
			if (s.top() == ')')
			{
				numOfPipe++;
				//cout << "Add Pipe" << '\n';
			}
			else
			{
				s.pop();
				result += numOfPipe;
				//cout << "Razer -> " << numOfPipe << '\n';
			}
		}
		else if(now == '(')
		{
			result++;
			numOfPipe--;
		}
	}

	cout << result << '\n';

	return 0;
}