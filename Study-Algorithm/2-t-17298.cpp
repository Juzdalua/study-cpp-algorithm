#include <bits/stdc++.h>
using namespace std;

/*
	크기가 N인 수열
	1 <= i <= N

	오큰수 NGE(i)
	A[i]의 오큰수는 오른쪽에 있으면서 A[i]보다 큰 수 중 가장 왼쪽에 있는 수
	없을경우 오큰수는 -1

	 A = [3, 5, 2, 7]
	 NGE(1) = 5,
	 NGE(2) = 7,
	 NGE(3) = 7,
	 NGE(4) = -1

	 A = [9, 5, 4, 8]
	 NGE(1) = -1,
	 NGE(2) = 8,
	 NGE(3) = 8,
	 NGE(4) = -1

	  1 ≤ N ≤ 1,000,000 = 백만 = 10^6
*/

int n;
vector<int> a;
vector<int> result;

void Solution()
{
	for (int i = 1; i <= n; i++)
	{
		int cur = a[i];
		int next = -1;
		for (int j = i; j <= n; j++)
		{
			if (cur >= a[j])
				continue;
			next = a[j];
			break;
		}
		result.push_back(next);
	}

	for (int& r : result)
		cout << r << " ";
}

void Solution2()
{
	result.resize(n + 1, -1);

	stack<int> s;
	for (int i = 1; i <= n; i++)
	{
		while (!s.empty())
		{
			if (a[s.top()] < a[i])
			{
				result[s.top()] = a[i];
				s.pop();
				continue;
			}
			break;
		}

		s.push(i);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << result[i] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	Solution2();

	return 0;
}