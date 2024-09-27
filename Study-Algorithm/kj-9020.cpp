#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다.
	이러한 수를 골드바흐 수라고 한다.
	이러한 표현을 골드바흐 파티션이라고 한다.

	4 = 2 + 2,
	6 = 3 + 3,
	8 = 3 + 5,
	10 = 5 + 5,
	12 = 5 + 7,
	14 = 3 + 11,
	14 = 7 + 7

	4 <= n <= 10'000
	만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는
	두 소수의 차이가 가장 작은 것을 출력한다.
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