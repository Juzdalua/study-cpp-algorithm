#include <bits/stdc++.h>
using namespace std;

/*
	n개의 카드, 1~n번의 숫자.
	1번이 제일 위, n번이 제일 아래

	제일 위 카드를 바닥에 버린다.
	제일 위 카드를 가장 아래로 옮긴다.

	가장 마지막에 남는 카드
	1 ≤ N ≤ 500,000
*/

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	int last = 0;
	while (!q.empty())
	{
		last = q.front();
		q.pop();
		if (q.empty())
			break;

		last = q.front();
		q.pop();
		q.push(last);
	}

	cout << last << '\n';

	return 0;
}