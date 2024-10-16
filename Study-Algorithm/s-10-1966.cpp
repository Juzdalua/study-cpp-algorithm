#include <bits/stdc++.h>
using namespace std;

/*
	1. 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
	2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.

	중요도는 1 이상 9 이하의 정수

	1 ≤ N ≤ 100
	0 ≤ M < N
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