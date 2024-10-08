#include <bits/stdc++.h>
using namespace std;

/*
	n개의 서로 다른 양의 정수로 이루어진 수열 a
	1 <= a[i] <= 1'000'000 -> 10^5

	자연수 x
	ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수

	1 ≤ n ≤ 100'000,
	1 ≤ x ≤ 2'000'000
*/

using int64 = long long;

int n, x;
set<int> inputs;
int64 result = 0;

void Solution()
{
	/*for (int i : inputs)
		cout << i << " ";
	cout << '\n';*/

	if (n == 1)
	{
		if(*inputs.begin() == x)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
		return;
	}
	
	for (int inp : inputs)
	{
		int findNum = x - inp;
		if (inp >= findNum)
			continue;
		//cout << "input: " << inp << ", find: " << findNum << '\n';
		if (inputs.find(findNum) != inputs.end())
		{
			result++;
		}
	}

	cout << result << '\n';
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
		inputs.insert(input);
	}
	cin >> x;

	Solution();

	return 0;
}