#include <bits/stdc++.h>
using namespace std;

/*
	��ȣ�� ������ �´��� Ȯ���Ѵ�
	¦�� �̷�� ��ȣ ���� ���ڿ��� ������ �������Ѵ�
	() []

	��ȣ�� ¦�� �̷�ų�
	��ȣ�� �ƿ� ���ų�

	���̴� 100�ں��� �۴�

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