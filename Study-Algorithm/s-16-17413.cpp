#include <bits/stdc++.h>
using namespace std;

/*
	���ĺ� �ҹ���('a'-'z'), ����('0'-'9'), ����(' '), Ư�� ����('<', '>')�θ� �̷���� �ִ�.
	���ڿ��� ���۰� ���� ������ �ƴϴ�.
	'<'�� '>'�� ���ڿ��� �ִ� ��� �����ư��鼭 �����ϸ�, '<'�� ���� �����Ѵ�. ��, �� ������ ������ ����.

	�±״� '<'�� �����ؼ� '>'�� ������ ���̰� 3 �̻��� �κ� ���ڿ��̰�, '<'�� '>' ���̿��� ���ĺ� �ҹ��ڿ� ���鸸 �ִ�.
	�ܾ�� ���ĺ� �ҹ��ڿ� ���ڷ� �̷���� �κ� ���ڿ��̰�, �����ϴ� �� �ܾ�� ���� �ϳ��� �����Ѵ�. -> h9i bye2
	�±״� �ܾ �ƴϸ�, �±׿� �ܾ� ���̿��� ������ ����. -> hi<a>

	S�� ���̴� 100,000 �����̴�.
	ù° �ٿ� ���ڿ� S�� �ܾ ����� ����Ѵ�.
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

		// �±�
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