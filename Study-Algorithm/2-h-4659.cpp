#include <bits/stdc++.h>
using namespace std;

/*
	패스워드 생성기

	1. 모음 (a, e, i, o, u) 하나를 반드시 포함한다.
	2. 모음이 3개, 또는 자음이 3개 연속으로 오면 안된다.
	3. 같은 글자가 연속으로 2번 오면 안된다.
	4. ee, oo만 허용한다.
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

		// 예외 1. 모음 체크
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

		// 예외 2. 같은글자 체크, ee oo
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

		// 예외 3. 3개 연속 단어 체크
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

		// 출력
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