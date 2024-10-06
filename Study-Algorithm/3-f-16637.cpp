#include <bits/stdc++.h>
using namespace std;

/*
	길이가 N인 수식
	0~9, +, -, *
	우선순위는 동일 => 왼쪽부터 계산
	괄호안에는 연산자가 하나만 있어야한다.

	3+8×7-9×2 = 136
	3+(8×7)-(9×2) = 41

	괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램
	추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.

	1 ≤ N ≤ 19
*/

int n;
vector<int> num;
vector<char> op;
int temp = 0;
int maxResult = INT_MIN;

int oper(char a, int b, int c)
{
	if (a == '+')
		return b + c;
	else if (a == '-')
		return b - c;
	else if (a == '*')
		return b * c;
}

void Print()
{
	for (int& n : num)
		cout << n << " ";
	cout << "\n";

	for (char& o : op)
		cout << o << " ";
	cout << "\n";
}

void Go(int idx, int number)
{
	if (idx == num.size() - 1)
	{
		maxResult = max(maxResult, number);
		return;
	}

	Go(idx + 1, oper(op[idx], number, num[idx + 1]));

	if (idx + 2 <= num.size() - 1)
		Go(idx + 2, oper(op[idx], number, oper(op[idx + 1], num[idx + 1], num[idx + 2])));
}

void Solution()
{
	//Print();

	if (n == 1)
	{
		cout << num[0] << '\n';
		return;
	}

	Go(0, num[0]);
	cout << maxResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	string input;
	cin >> input;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			num.push_back(input[i] - '0');
		else
			op.push_back(input[i]);
	}

	Solution();

	return 0;
}