#include <bits/stdc++.h>
using namespace std;

/*
	수빈 N(0 ≤ N ≤ 500,000)
	동생 K(0 ≤ K ≤ 500,000)

	n-1, n+1, n*2
	k -> k+1 -> k+1+2 -> k+1+2+3, n초 후: k+1+...+n
	동생의 이동거리는 이전 이동거리보다 1 더 이동한다.
	동생을 찾는 최단거리

	수빈이가 동생을 찾을 수 없거나, 찾는 위치가 500,000을 넘는 경우에는 -1
*/

const int LIMIT = 500'000;
int n, k;
int visited[2][LIMIT + 4];
int curIdx = 1;
bool flag = false;

void BFS()
{
	queue<int> q;
	q.push(n);
	visited[0][n] = 1;

	while (!q.empty())
	{
		// 동생이 먼저 움직인다.
		k += curIdx;
		if (k > LIMIT)
			break;

		// 수빈이가 먼저 방문했던 곳에 동생이 방문한다면, 홀짝 시간대 체크
		if (visited[curIdx % 2][k])
		{
			flag = true;
			break;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int here = q.front();
			q.pop();

			for (int there : {here + 1, here - 1, here * 2})
			{
				// overflow
				if (there > LIMIT || there < 0)
					continue;

				// 같은 홀,짝에 방문했다면 건너뛰기
				if (visited[curIdx % 2][there] != 0)
					continue;

				// 이번이 짝수 -> 홀수에 다음방문
				// 이번이 홀수 -> 짝수에 다음방문
				visited[curIdx % 2][there] = visited[(curIdx + 1) % 2][here] + 1;

				if (there == k)
				{
					flag = true;
					break;
				}

				q.push(there);
			}
			if (flag)
				break;
		}
		if (flag)
			break;
		curIdx++;
	}

	if (flag)
		cout << curIdx << '\n';
	else
		cout << -1 << '\n';
}

void Solution()
{
	if (n == k)
	{
		cout << 0 << '\n';
		return;
	}

	BFS();
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