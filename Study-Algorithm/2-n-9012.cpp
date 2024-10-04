#include <bits/stdc++.h>
using namespace std;

/*
	PS => (, ) �θ� �̷���� ���ڿ�
	VPS => ��ȣ�� �ٸ��� ������ ���ڿ�
	�⺻ VPS => ()

	x�� VPS => (x)�� VPS
	x, y�� VPS => xy�� VPS

*/

const string YES = "YES";
const string NO = "NO";
int t;
vector<string> inputs;

void Solution()
{
	for (string input : inputs)
	{
		// Ȧ���� üũ
		if (input.size() % 2 != 0)
		{
			cout << NO << '\n';
			continue;
		}

		// �¿� ¦ üũ
		int lcnt = 0;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '(')
				lcnt++;
		}
		if (input.size() / 2 != lcnt)
		{
			cout << NO << '\n';
			continue;
		}

		// ��ȸ
		stack<char> s;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '(')
			{
				s.push('(');
				continue;
			}
			else
			{
				if (s.empty())
				{
					cout << NO << '\n';
					break;
				}
				else if (!s.empty() && s.top() != '(')
				{
					cout << NO << '\n';
					break;
				}
				s.pop();
			}
			if (i == input.size() - 1)
				cout << YES << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	inputs.resize(t);
	for (int i = 0; i < t; i++)
	{
		cin >> inputs[i];
	}

	Solution();

	return 0;
}