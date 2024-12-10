#include <bits/stdc++.h>
using namespace std;

/*
	n���� ī��, 1~n���� ����.
	1���� ���� ��, n���� ���� �Ʒ�

	���� �� ī�带 �ٴڿ� ������.
	���� �� ī�带 ���� �Ʒ��� �ű��.

	���� �������� ���� ī��
	1 �� N �� 500,000
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