#include <bits/stdc++.h>
using namespace std;

/*
	4개의 기호를 사용하여 올바른 괄호를 만든다
	( ) [ ]
	1. (), []만 올바른 괄호이다
	2. x가 올바른 괄호라면, (x), [x]도 올바른 괄호이다 -> (()), ([]), [()], [[]], ...
	3. xy 모두 올바른 괄호라면, xy도 올바른 괄호이다. -> ()(), [][], ()[], [](), ...

	1. ‘()’ 인 괄호열의 값은 2이다.
	2. ‘[]’ 인 괄호열의 값은 3이다.
	3. ‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
	4. ‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
	5. 올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.

	괄호를 읽고 값을 출력하라.

	‘(()[[]])([])’
	‘()[[]]’ 의 괄호값이 2 + 3×3=11
	‘(()[[]])’의 괄호값은 2×11=22
	‘([])’의 값은 2×3=6
	 22 + 6 = 28
*/

string input;
stack<char> s;
long long result = 0;
long long temp = 1;

void Exit()
{
	cout << 0 << '\n';
	exit(0);
}

void Solution()
{
	int n = input.size();
	for (int i = 0; i < n; i++)
	{
		char current = input[i];
		if (current == '(' || current == '[')
		{
			s.push(current);
			temp *= (current == '(') ? 2 : 3;
		}
		else if (current == ')' || current == ']')
		{
			if (s.empty())
				Exit();
			if (current == ')' && s.top() != '(')
				Exit();
			if (current == ']' && s.top() != '[')
				Exit();

			s.pop();

			if (input[i - 1] == '(' || input[i - 1] == '[')
			{
				//cout << "A: " << result << endl;
				result += temp;
				//cout << "B: " << result << endl;
			}
			temp /= current == ')' ? 2 : 3;
		}
		if (i == n - 1 && !s.empty())
			Exit();

	}
	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input;

	Solution();

	return 0;
}