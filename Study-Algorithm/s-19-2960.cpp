#include <bits/stdc++.h>
using namespace std;

/*
	N���� �۰ų� ���� �Ҽ�

	2���� N���� ��� ������ ���´�.
	���� ������ ���� �� �� ���� ���� ���� ã�´�. �̰��� P��� �ϰ�, �� ���� �Ҽ��̴�.
	P�� �����, ���� ������ ���� P�� ����� ũ�� ������� �����.
	���� ��� ���� ������ �ʾҴٸ�, �ٽ� 2�� �ܰ�� ����.

	1 �� K < N,
	max(1, K) < N �� 1000
*/

int n, k;
int arr[1004];
int cnt;

void Done(int i)
{
	//cout << "count: " << cnt << ", i: " << i << '\n';
	cnt++;
	if (cnt == k)
	{
		cout << i << '\n';
		exit(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 2; i <= n; i++)
	{
		arr[i] = 1;
	}

	int p = 0;
	while (true)
	{
		for (int i = 2; i <= n; i++)
		{
			if (arr[i] == 1)
			{
				p = i;
				arr[i] = 0;
				Done(i);
				break;
			}
		}

		for (int i = 2; i <= n; i++)
		{
			if (i % p == 0 && arr[i] == 1)
			{
				arr[i] = 0;
				Done(i);
			}
		}
	}

	return 0;
}