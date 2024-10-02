#include <bits/stdc++.h>
using namespace std;

/*
	�н����� ������

	1. ���� (a, e, i, o, u) �ϳ��� �ݵ�� �����Ѵ�.
	2. ������ 3��, �Ǵ� ������ 3�� �������� ���� �ȵȴ�.
	3. ���� ���ڰ� �������� 2�� ���� �ȵȴ�.
	4. ee, oo�� ����Ѵ�.
*/

const vector<char> moum = { 'a', 'e', 'i', 'o', 'u' };
const string OK = "is acceptable.";
const string NO = "is not acceptable.";
vector<string> inputs;

bool IsMoum(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return true;
	return false;
}

void Solution()
{
	for (int i = 0; i < inputs.size(); i++)
	{
		string str = inputs[i];

		// ���� 1. ���� üũ
		bool flag = false;
		for (int j = 0; j < str.size(); j++)
		{
			if (IsMoum(str[j]))
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "<" << inputs[i] << "> " << NO << '\n';
			continue;
		}

		// ���� 2. �������� üũ, ee oo
		flag = true;
		if (str.size() >= 2)
		{
			for (int j = 0; j < str.size() - 1; j++)
			{
				if (str[j] == str[j + 1])
				{
					if (str[j] != 'e' && str[j] != 'o')
					{
						flag = false;
						break;
					}
				}
			}
			if (!flag)
			{
				cout << "<" << inputs[i] << "> " << NO << '\n';
				continue;
			}
		}

		// ���� 3. 3�� ���� �ܾ� üũ
		flag = true;
		if (str.size() >= 3)
		{
			for (int j = 0; j < str.size() - 2; j++)
			{

				if ((IsMoum(str[j]) && IsMoum(str[j + 1]) && IsMoum(str[j + 2])) || (!IsMoum(str[j]) && !IsMoum(str[j + 1]) && !IsMoum(str[j + 2])))
				{
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				cout << "<" << inputs[i] << "> " << NO << '\n';
				continue;
			}
		}

		// ���
		cout << "<" << inputs[i] << "> " << OK << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	while (cin >> input)
	{
		if (input == "end")
			break;

		inputs.push_back(input);
	}

	Solution();

	return 0;
}