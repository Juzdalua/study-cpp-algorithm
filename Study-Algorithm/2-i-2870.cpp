#include <bits/stdc++.h>
using namespace std;

/*
	숫자와 소문자로 되어있는 글자 N
	숫자를 모두 찾은 뒤, 숫자를 비내림차순으로 정리
	숫자 앞에 0이 있으면 정리하면서 생략 가능
	가능한 가장 큰 숫자를 찾느다
	모든 숫자의 앞과 뒤가 문자거나, 줄의 시작 또는 끝이어야 한다.

	오름차순 정렬

	(1 ≤ N ≤ 100)

	48 = 0
	49 ~ 57 = 1 ~ 9
*/

struct CustomCompare
{
	bool operator()(const string& a, const string& b) const
	{
		if (a.size() != b.size()) 
		{
			return a.size() < b.size();
		}
		return a < b;
	}
};

int n;
vector<string> inputs;
multiset <string, CustomCompare> result;

bool IsSaveZero(char ch)
{
	if (ch >= 48 && ch <= 57)
		return true;
	return false;
}

void Solution()
{
	vector<string> temp;
	for (int i = 0; i < inputs.size(); i++)
	{
		string str = inputs[i];
		string newStr = "";

		for (int j = 0; j < str.size(); j++)
		{
			char ch = str[j];

			if (IsSaveZero(ch))
			{
				newStr += ch;

				if (j == str.size() - 1)
				{
					temp.push_back(newStr);
					newStr = "";
				}
			}
			else
			{
				if (newStr != "")
				{
					temp.push_back(newStr);
					newStr = "";
				}
			}
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		string str = temp[i];
		string newStr = "";
		for (int j = 0; j < str.size(); j++)
		{
			char ch = str[j];
			if (ch == '0' && j != str.size() - 1)
			{
				continue;
			}
			else
				newStr += ch;
		}
		// 0000
		if (newStr == "")
			result.insert("0");
		else
			result.insert(newStr);
	}

	for (string r : result)
		cout << r << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		inputs.push_back(input);
	}

	Solution();

	return 0;
}