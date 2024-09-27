#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	2���� ū ��� ¦���� �� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
	�̷��� ���� ������ ����� �Ѵ�.
	�̷��� ǥ���� ������ ��Ƽ���̶�� �Ѵ�.

	4 = 2 + 2,
	6 = 3 + 3,
	8 = 3 + 5,
	10 = 5 + 5,
	12 = 5 + 7,
	14 = 3 + 11,
	14 = 7 + 7

	4 <= n <= 10'000
	���� ������ n�� ������ ��Ƽ���� ���� ������ ��쿡��
	�� �Ҽ��� ���̰� ���� ���� ���� ����Ѵ�.
*/

int n;
vector<int> inputs;
vector<int> prime;
const int MAX = 10'000;

void Primes()
{
	for (int i = 2; i < MAX - 1; i++)
	{
		int cnt = 0;
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0)
			{
				cnt++;
			}
			if (cnt > 2)
				break;
		}
		if (cnt == 1)
			prime.push_back(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		inputs.push_back(input);
	}

	Primes();

	vector<pair<int, int>> result;
	for (int& input : inputs)
	{
		int start = 0;
		int end = 987654321;
		for (int i = 0; i < prime.size(); i++)
		{
			int last = input - prime[i];

			auto it = find(prime.begin() + i, prime.end(), last);
			if (it != prime.end())
			{
				if (end - start > prime[i] - *it)
				{
					start = prime[i];
					end = *it;
				}
			}
		}

		result.push_back(make_pair(start, end));
	}

	for (auto& r : result)
		cout << r.first << " " << r.second << '\n';

	return 0;
}