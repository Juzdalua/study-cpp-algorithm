#include <bits/stdc++.h>
using namespace std;

/*
	수빈-N, 동생-K
	수빈이가 걸으면 1초 후, x-1 or x+1로 이동
	순간이동하면 1초 후, 2*x로 이동

	1. 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후
	2. 가장 빠른 시간으로 찾는 방법이 몇 가지

	0 ≤ N ≤ 100,000
	0 ≤ K ≤ 100,000
*/

const int LIMIT = 200'000;
int n, k;
int visited[200'004];
int cnt[200'004];

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		//cout << "\nBFS -> " << x << ", Cost -> " << visited[x] << '\n';

		int nx1 = x + 1;
		int nx2 = x - 1;
		int nx3 = x * 2;

		if (nx1 <= LIMIT && nx1 >= 0)
		{
			if (visited[nx1] == 0)
			{
				//cout << "PUSH -> " << nx1 << ", Cost -> " << visited[nx1] << '\n';
				visited[nx1] = visited[x] + 1;
				cnt[nx1] += cnt[x];
				q.push(nx1);
			}

			else if (visited[nx1] == visited[x] + 1)
			{
				cnt[nx1] += cnt[x];
			}
		}

		if (nx2 <= LIMIT && nx2 >= 0)
		{
			if (visited[nx2] == 0)
			{
				//cout << "PUSH -> " << nx2 << ", Cost -> " << visited[nx2] << '\n';
				visited[nx2] = visited[x] + 1;
				cnt[nx2] += cnt[x];
				q.push(nx2);
			}

			else if (visited[nx2] == visited[x] + 1)
			{
				cnt[nx2] += cnt[x];
			}
		}

		if (nx3 <= LIMIT && nx3 >= 0)
		{
			if (visited[nx3] == 0)
			{
				//cout << "PUSH -> " << nx3 << ", Cost -> " << visited[nx3] << '\n';
				visited[nx3] = visited[x] + 1;
				cnt[nx3] += cnt[x];
				q.push(nx3);
			}

			else if (visited[nx3] == visited[x] + 1)
			{
				cnt[nx3] += cnt[x];
			}
		}
	}
}

void Solution()
{
	if (n == k)
	{
		cout << 0 << '\n';
		cout << 1 << '\n';
		return;
	}

	cnt[n] = 1;
	BFS(n);

	cout << visited[k] << '\n';
	cout << cnt[k] << '\n';

	/*for (auto& r : rm)
		cout << r.first << " : " << r.second << '\n';*/
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	Solution();

	return 0;
}