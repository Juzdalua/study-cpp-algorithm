#include <bits/stdc++.h>
using namespace std;

/*
	길이가 N인 수열
	수열에서 연속한 한개 이상의 수를 뽑았을 때, 같은 수가 여러번 등장하지 않는 경우의 수

	1 ≤ N ≤ 100,000 -> 10^4 ->O(N^2) 가능
	1<= 수 <= 100'000
*/

using int64 = long long;
int n;
int inputs[100'004];
int visited[100'004];

void Solution()
{
	int64 sum = 0;
	int64 startIdx = 0;
	int64 endIdx = 0;

	while (endIdx < n)
	{
		if (visited[inputs[endIdx]] == 0)
		{
			visited[inputs[endIdx]]++;
			endIdx++;
		}
		else
		{
			sum += endIdx - startIdx;
			visited[inputs[startIdx]]--;
			startIdx++;
		}
	}
	sum += (endIdx - startIdx) * (endIdx - startIdx + 1) / 2l;

	cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inputs[i];
	}

	Solution();

	return 0;
}