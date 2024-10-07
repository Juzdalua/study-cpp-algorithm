#include <bits/stdc++.h>
using namespace std;

/*
	���� N(0 �� N �� 500,000)
	���� K(0 �� K �� 500,000)

	n-1, n+1, n*2
	k -> k+1 -> k+1+2 -> k+1+2+3, n�� ��: k+1+...+n
	������ �̵��Ÿ��� ���� �̵��Ÿ����� 1 �� �̵��Ѵ�.
	������ ã�� �ִܰŸ�

	�����̰� ������ ã�� �� ���ų�, ã�� ��ġ�� 500,000�� �Ѵ� ��쿡�� -1
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
		// ������ ���� �����δ�.
		k += curIdx;
		if (k > LIMIT)
			break;

		// �����̰� ���� �湮�ߴ� ���� ������ �湮�Ѵٸ�, Ȧ¦ �ð��� üũ
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

				// ���� Ȧ,¦�� �湮�ߴٸ� �ǳʶٱ�
				if (visited[curIdx % 2][there] != 0)
					continue;

				// �̹��� ¦�� -> Ȧ���� �����湮
				// �̹��� Ȧ�� -> ¦���� �����湮
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