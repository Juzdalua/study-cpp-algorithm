#include <bits/stdc++.h>
using namespace std;

/*
	4���� ��ȣ�� ����Ͽ� �ùٸ� ��ȣ�� �����
	( ) [ ]
	1. (), []�� �ùٸ� ��ȣ�̴�
	2. x�� �ùٸ� ��ȣ���, (x), [x]�� �ùٸ� ��ȣ�̴� -> (()), ([]), [()], [[]], ...
	3. xy ��� �ùٸ� ��ȣ���, xy�� �ùٸ� ��ȣ�̴�. -> ()(), [][], ()[], [](), ...

	1. ��()�� �� ��ȣ���� ���� 2�̴�.
	2. ��[]�� �� ��ȣ���� ���� 3�̴�.
	3. ��(X)�� �� ��ȣ���� 2����(X) ���� ���ȴ�.
	4. ��[X]�� �� ��ȣ���� 3����(X) ���� ���ȴ�.
	5. �ùٸ� ��ȣ�� X�� Y�� ���յ� XY�� ��ȣ���� ��(XY)= ��(X)+��(Y) �� ���ȴ�.

	��ȣ�� �а� ���� ����϶�.

	��(()[[]])([])��
	��()[[]]�� �� ��ȣ���� 2 + 3��3=11
	��(()[[]])���� ��ȣ���� 2��11=22
	��([])���� ���� 2��3=6
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