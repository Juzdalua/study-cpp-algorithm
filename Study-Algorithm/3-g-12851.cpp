#include <bits/stdc++.h>
using namespace std;

/*
	����-N, ����-K
	�����̰� ������ 1�� ��, x-1 or x+1�� �̵�
	�����̵��ϸ� 1�� ��, 2*x�� �̵�

	1. �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ��
	2. ���� ���� �ð����� ã�� ����� �� ����

	0 �� N �� 100,000
	0 �� K �� 100,000
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