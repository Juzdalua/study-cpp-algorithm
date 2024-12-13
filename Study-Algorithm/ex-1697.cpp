#include <bits/stdc++.h>
using namespace std;

/*
	n-1, n+1, n*2
*/

int n, k;
int result = INT_MAX;
bool visited[100'004];

void Go(int here, int sec)
{
	queue<pair<int, int>> q;
	q.push({ here, sec });
	visited[here] = true;

	while (!q.empty())
	{
		auto [now, nowTime] = q.front();
		q.pop();

		//cout << "now -> " << now << ", time -> " << nowTime << '\n';

		if (now == k)
		{
			result = min(result, nowTime);
			break;
		}

		for (int next : { now - 1, now + 1, now * 2 })
		{
			if (next < 0 || next > 100'000) continue;
			if (visited[next]) continue;

			visited[next] = true;
			q.push({ next, nowTime + 1 });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	if (n == k)
	{
		cout << 0 << '\n';
		exit(0);
	}

	Go(n, 0);

	cout << result << '\n';

	return 0;
}