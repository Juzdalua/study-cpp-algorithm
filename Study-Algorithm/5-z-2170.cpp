#include <bits/stdc++.h>
using namespace std;

/*
	��ȭ���� �ڸ� ��� ���� �ߴ´�
	���� �� ������ �� ������ �ߴ´�

	������ ���ļ� ���� ���� ������ �Ұ����ϴ�
	-> ������ �׾ ������ ���� �ϳ��� ������ �����Ѵ�.

	�׷��� ������ �� ���� ���϶�

	1 �� N �� 1,000,000
	-1,000,000,000 �� x < y �� 1,000,000,000
*/

int n;
vector<pair<int, int>> v;

void Solution()
{
	sort(v.begin(), v.end());
	int l = v[0].first;
	int r = v[0].second;
	long long sum = 0;

	for (int i = 1; i < v.size(); i++)
	{
		int start = v[i].first;
		int end = v[i].second;

		if (start > r || end < l)
		{
			sum += r - l;
			l = start;
			r = end;
			continue;
		}

		l = min(l, start);
		r = max(r, end);
	}
	sum += r - l;
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
		int in1, in2;
		cin >> in1 >> in2;
		v.push_back({ in1,in2 });
	}

	Solution();

	return 0;
}