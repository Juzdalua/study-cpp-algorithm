#include <bits/stdc++.h>
using namespace std;

/*
	외판원 순회 TSP
	완전탐색 -> O(N!)
	N!의 오른쪽 끝 0의 갯수
	1 <= N <= 1'000'000'000 - 10억 = 10^8
*/

int t;
vector<int> inputs;

void Solution()
{
	for (int item : inputs)
	{
		int cnt2 = 0;
		int cnt5 = 0;
		for (int i = 2; i <= item; i *= 2)
		{
			cnt2 += item / i;
		}

		for (int i = 5; i <= item; i *= 5)
		{
			cnt5 += item / i;
		}

		//cout << "Cnt2: " << cnt2 << ", Cnt5: " << cnt5 << '\n';
		cout << min(cnt2, cnt5) << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	inputs.resize(t);
	for (int i = 0; i < t; i++)
	{
		cin >> inputs[i];
	}

	Solution();

	return 0;
}