#include <bits/stdc++.h>
using namespace std;

/*
	���� n���� ����Ʈ
	���� m���� ����Ʈ
	�� ����Ʈ���� �ִ� �� ���� �ٸ��� ����� �� �ִ�

	�ٸ��� �ִ��� ���� ���������Ѵ�.
	������ ����Ʈ ������ŭ (N��) �ٸ��� �������� �Ѵ�

	0 < N �� M < 30
*/

int n, m, t;

long long Go()
{
	long long result = 1;

	for (int i = 0; i < n; i++)
	{
		result *= (m - i);
		result /= i + 1;
	}

	return result;
}

void Solution()
{
	long long res = Go();
	cout << res << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		Solution();
	}

	return 0;
}