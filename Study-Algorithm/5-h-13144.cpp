#include <bits/stdc++.h>
using namespace std;

/*
	���̰� N�� ����
	�������� ������ �Ѱ� �̻��� ���� �̾��� ��, ���� ���� ������ �������� �ʴ� ����� ��

	1 �� N �� 100,000 -> 10^4 ->O(N^2) ����
	1<= �� <= 100'000
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