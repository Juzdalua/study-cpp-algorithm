#include <bits/stdc++.h>
using namespace std;

/*
	정수를 저장하는 스택
	push X: 정수 X를 스택에 넣는 연산이다.
	pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	size: 스택에 들어있는 정수의 개수를 출력한다.
	empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
	top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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