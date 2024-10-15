#include <bits/stdc++.h>
using namespace std;

/*
	A, B ����
	������ ũ�Ⱑ �����ִ�
	�� ������ ���ڸ� 2���� �̻� �Ǹ��� ���� ���ӵ� ������ �Ǹ��Ѵ�
	���������� ũ���� ���� �ֹ��� ũ�Ⱑ �Ǿ���Ѵ�

	1. ��� A �Ǹ�
	2. ��� B �Ǹ�
	3. A, B ���� �Ǹ�

	�մ��� ���ϴ� ���ڸ� �Ǹ��ϴ� ��� ����� ���� ���϶�

	����ũ�� 2,000,000
	�� ���� ������ ũ�� 1000 ���� �ڿ���
	A,B ���������� ���� 3 �� m, n �� 1000
	A: m��, B: n��
*/

using int64 = long long;
int p, m, n;
int a[2'004];
int b[2'004];
int64 result = 0;

void Solution()
{
	for (int i = 0; i < m; i++)
	{
		a[m + i] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		b[n + i] = b[i];
	}

	map<int64, int64> pizzaA;
	for (int i = 0; i < m; i++)
	{
		int64 pA = 0;
		for (int j = i; j < i + m; j++)
		{
			pA += a[j];
			if (pA > p)
				break;
			if (j == i + m - 1)
			{
				if (pizzaA[pA] != 0)
					break;
			}
			pizzaA[pA]++;
		}
	}

	map<int64, int64> pizzaB;
	for (int i = 0; i < n; i++)
	{
		int64 pB = 0;
		for (int j = i; j < i + n; j++)
		{
			pB += b[j];
			if (pB > p)
				break;
			if (j == i + n - 1)
			{
				if (pizzaB[pB] != 0)
					break;
			}
			pizzaB[pB]++;
		}
	}

	for (auto& pa : pizzaA)
	{
		if (pa.first > p || pa.first == p || pa.first == 0)
		{
			break;
			//continue;
		}

		int64 find = p - pa.first;

		auto it = pizzaB.find(find);
		if (it != pizzaB.end())
		{
			//cout << "A: " << pa.second << ", B: " << pizzaB[find] << '\n';
			result += (*it).second * pa.second;
		}
	}
	//cout << "A: " << pizzaA[p] << '\n';
	//cout << "B: " << pizzaB[p] << '\n';
	result += pizzaA[p];
	result += pizzaB[p];

	/*auto findA = pizzaA.find(p);
	if (findA != pizzaA.end())
	{
		result += (*findA).second;
	}

	auto findB = pizzaB.find(p);
	if (findB != pizzaB.end())
	{
		result += (*findB).second;
	}*/

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> p >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	Solution();

	return 0;
}