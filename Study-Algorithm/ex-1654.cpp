#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, k;
long long maxLen, result;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		long long input;
		cin >> input;
		v.push_back(input);
		maxLen = max(maxLen, input);
	}

	long long left = 1;
	long long right = maxLen;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;

		for (int& vv : v)
		{
			cnt += vv / mid;
		}
		if (cnt >= n)
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << result << '\n';

	return 0;
}