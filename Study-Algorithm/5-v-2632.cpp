#include <bits/stdc++.h>
using namespace std;

/*
	A, B 피자
	조각에 크기가 쓰여있다
	한 종류의 피자를 2조각 이상 판매할 때는 연속된 조각을 판매한다
	피자조각의 크기의 합이 주문한 크기가 되어야한다

	1. 모두 A 판매
	2. 모두 B 판매
	3. A, B 섞어 판매

	손님이 원하는 피자를 판매하는 모든 방법의 수를 구하라

	피자크기 2,000,000
	각 피자 조각의 크기 1000 이하 자연수
	A,B 피자조각의 개수 3 ≤ m, n ≤ 1000
	A: m개, B: n개
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