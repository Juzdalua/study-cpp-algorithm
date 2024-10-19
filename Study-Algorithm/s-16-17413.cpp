#include <bits/stdc++.h>
using namespace std;

/*
	알파벳 소문자('a'-'z'), 숫자('0'-'9'), 공백(' '), 특수 문자('<', '>')로만 이루어져 있다.
	문자열의 시작과 끝은 공백이 아니다.
	'<'와 '>'가 문자열에 있는 경우 번갈아가면서 등장하며, '<'이 먼저 등장한다. 또, 두 문자의 개수는 같다.

	태그는 '<'로 시작해서 '>'로 끝나는 길이가 3 이상인 부분 문자열이고, '<'와 '>' 사이에는 알파벳 소문자와 공백만 있다.
	단어는 알파벳 소문자와 숫자로 이루어진 부분 문자열이고, 연속하는 두 단어는 공백 하나로 구분한다. -> h9i bye2
	태그는 단어가 아니며, 태그와 단어 사이에는 공백이 없다. -> hi<a>

	S의 길이는 100,000 이하이다.
	첫째 줄에 문자열 S의 단어를 뒤집어서 출력한다.
*/

string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, s);

	bool tag = false;
	string result = "";
	string rs = "";
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];

		//cout << "i: " << i << ", ch: " << ch << ", tag: " << tag << ", rs: " << rs.size() << '\n';

		if (!tag && ch != ' ' && ch != '<')
		{
			rs.push_back(ch);
			if (i == s.size() - 1)
			{
				reverse(rs.begin(), rs.end());
				result += rs;
			}
			continue;
		}
		else if (!tag && rs.size() > 0 && (ch == ' ' || ch == '<' || ch == s.size() - 1))
		{
			reverse(rs.begin(), rs.end());
			result += rs;
			rs = "";
			result.push_back(ch);

			if (ch == '<')
				tag = true;
			continue;
		}

		// 태그
		if (ch == '<')
		{
			tag = true;
			result.push_back(ch);
			continue;
		}
		else if (tag && ch != '>')
		{
			result.push_back(ch);
			continue;
		}
		else if (ch == '>')
		{
			//cout << "FALSE!!!!" << '\n';
			tag = false;
			result.push_back(ch);
			continue;
		}
	}

	cout << result << '\n';

	return 0;
}