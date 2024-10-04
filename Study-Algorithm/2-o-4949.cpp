#include <bits/stdc++.h>
using namespace std;

/*
	괄호의 균형이 맞는지 확인한다
	짝을 이루는 괄호 사이 문자열도 균형이 잡혀야한다
	() []

	괄호가 짝을 이루거나
	괄호가 아예 없거나

	길이는 100자보다 작다

*/

vector<string> inputs;
const string YES = "yes";
const string NO = "no";

void Solution()
{
	for (string& input : inputs)
	{
		//cout << input << '\n';
		stack<char> s;
		bool flag = true;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '(' || input[i] == '[')
				s.push(input[i]);

			else if (input[i] == ')')
			{
				if (!s.empty() && s.top() == '(')
				{
					s.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}

			else if (input[i] == ']')
			{
				if (!s.empty() && s.top() == '[')
				{
					s.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}

			
		}
		if (flag && s.empty())
			cout << YES << '\n';
		else
			cout << NO << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	while (true)
	{
		getline(cin, input);
		if (input == ".")
			break;

		inputs.push_back(input);
	}

	Solution();

	return 0;
}