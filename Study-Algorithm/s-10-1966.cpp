#include <bits/stdc++.h>
using namespace std;

/*
	1. ���� Queue�� ���� �տ� �ִ� ������ ���߿䵵���� Ȯ���Ѵ�.
	2. ������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� �ִٸ�, �� ������ �μ����� �ʰ� Queue�� ���� �ڿ� ���ġ �Ѵ�. �׷��� �ʴٸ� �ٷ� �μ⸦ �Ѵ�.

	�߿䵵�� 1 �̻� 9 ������ ����

	1 �� N �� 100
	0 �� M < N
*/

int t, n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		queue<pair<int, int>> q;
		vector<pair<int, int>> val;

		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;
			q.push({ input ,j });

			val.push_back({ input, j });
		}

		pair<int, int> target = val[m];

		sort(val.begin(), val.end());
		int maxVal = val.back().first;
		int cnt = 0;

		while (!q.empty())
		{
			pair<int, int> num = q.front();
			q.pop();

			if (num.first == maxVal)
			{
				cnt++;
				if (num == target)
				{
					cout << cnt << '\n';
					break;
				}

				val.pop_back();
				maxVal = val.back().first;

				continue;
			}
			else
				q.push(num);
		}
	}

	return 0;
}