#include <bits/stdc++.h>
using namespace std;

/*
	1~N번 사람이 원을 이루며 앉아있다
	K번째 사람을 제거
	N명이 모두 제거될때까지 반복

	사람들이 제거되는 순열 (n,k)
	(7,3) ->  <3, 6, 2, 7, 5, 1, 4>
	1 ≤ K ≤ N ≤ 1,000
*/

int n, k;
queue<int> circle;
vector<int> result;

void Solution()
{
	int cnt = 0;
	while (!circle.empty())
	{
		int cur = circle.front();
		circle.pop();

		cnt++;

		if (cnt < k)
		{
			circle.push(cur);
		}
		else if (cnt == k)
		{
			cnt = 0;
			result.push_back(cur);
		}
	}

	cout << "<";
	for (int i=0; i<n; i++)
	{
		cout << result[i];
		if (i != n - 1)
		{
			cout << ", ";
		}
	}
	cout << ">";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		circle.push(i);
	}

	Solution();

	return 0;
}