#include <bits/stdc++.h>
using namespace std;

/*
	���̰� N�� ����
	0~9, +, -, *
	�켱������ ���� => ���ʺ��� ���
	��ȣ�ȿ��� �����ڰ� �ϳ��� �־���Ѵ�.

	3+8��7-9��2 = 136
	3+(8��7)-(9��2) = 41

	��ȣ�� ������ �߰��� ���� �� �ִ� ���� ����� �ִ��� ���ϴ� ���α׷�
	�߰��ϴ� ��ȣ ������ ������ ������, �߰����� �ʾƵ� �ȴ�.

	1 �� N �� 19
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