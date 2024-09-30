#include <bits/stdc++.h>
using namespace std;

/*
	������ �����ϴ� ����
	push X: ���� X�� ���ÿ� �ִ� �����̴�.
	pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
	size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
	empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
	top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> s;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string inputStr;
		cin >> inputStr;

		if (inputStr == "push")
		{
			int input;
			cin >> input;
			s.push(input);
			continue;
		}
		else if (inputStr == "pop")
		{
			if (s.empty())
				cout << -1 << '\n';
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
			continue;
		}
		else if (inputStr == "size")
		{
			cout << s.size() << '\n';
			continue;
		}
		else if (inputStr == "empty")
		{
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			continue;
		}
		else if (inputStr == "top")
		{
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
			continue;
		}
	}


	return 0;
}