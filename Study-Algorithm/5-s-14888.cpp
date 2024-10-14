#include <bits/stdc++.h>
using namespace std;

/*
	N���� ���� �̷���� ���� A
	A ���̿� ���� �� �ִ� N-1���� ������
	+ - * /
	A ������ �ٲ��� �ʰ� �����ڸ� �ִ´�

	������ �켱���� ���� �տ������� ����Ѵ�.
	�������� ���� ������
	������ ����� ������, ����� �ٲ� �� ���� ���� ������ �ٲ۴�

	���� ����� �ּ��� �Ͱ� �ִ��� ���� ���϶�

	2 �� N �� 11
	1 �� Ai �� 100

*/

int n;
int arr[15];
int oper[5]; // +, -, *, /
int maxResult = INT_MIN;
int minResult = INT_MAX;
vector<char> ope;

void SetOper()
{
	for (int i = 0; i < oper[0]; i++)
		ope.push_back('+');
	for (int i = 0; i < oper[1]; i++)
		ope.push_back('-');
	for (int i = 0; i < oper[2]; i++)
		ope.push_back('*');
	for (int i = 0; i < oper[3]; i++)
		ope.push_back('/');
	
	sort(ope.begin(), ope.end());
}

void Calc()
{
	int sum = arr[0];
	for (int i = 0; i < n-1; i++)
	{
		if (ope[i] == '+')
		{
			sum += arr[i + 1];
		}
		else if(ope[i] == '-')
		{
			sum -= arr[i + 1];
		}
		else if (ope[i] == '*')
		{
			sum *= arr[i + 1];
		}
		else if (ope[i] == '/')
		{
			sum /= arr[i + 1];
		}
	}

	maxResult = max(maxResult, sum);
	minResult = min(minResult, sum);
}

void Solution()
{
	SetOper();
	
	do
	{
		Calc();

	} while (next_permutation(ope.begin(), ope.end()));

	cout << maxResult << '\n';
	cout << minResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	Solution();

	return 0;
}