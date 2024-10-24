#include <bits/stdc++.h>
using namespace std;

/*
	N보다 작거나 같은 소수

	2부터 N까지 모든 정수를 적는다.
	아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
	P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
	아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.

	1 ≤ K < N,
	max(1, K) < N ≤ 1000
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