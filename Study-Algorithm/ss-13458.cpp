#include <bits/stdc++.h>
using namespace std;

/*
	N���� ������
	�� �����帶�� �����ڰ� �ִ�.
	i�� �������� �����ڴ� A[i]��

	�Ѱ�����, �ΰ�����
	�Ѱ����� - �� �����忡�� B�� ����
	�ΰ����� - �� �����忡�� C�� ����
	�� �����忡 �� �������� 1��, �ΰ������� ������ ����
	�� �������� ���û��� ��� �����ؾ��Ѵ�.

	�ʿ��� �������� �ּҰ��� ���϶�

	������ 1 �� N �� 1,000,000 - 10^6
	�� ������ ������ �� 1 �� Ai �� 1,000,000 - 10^6
	1 �� B, C �� 1,000,000
*/

using int64 = long long;

int n;
int arr[1'000'004];
int b, c;
int64 sum;

void Solution()
{
	for (int i = 0; i < n; i++)
	{
		// �Ѱ���
		sum++;
		arr[i] -= b;
		if (arr[i] <= 0)
			continue;

		if (arr[i] % c == 0)
		{
			sum += arr[i] / c;
		}
		else
		{
			sum += (arr[i] / c) + 1;
		}
	}
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
		cin >> arr[i];
	}
	cin >> b >> c;

	Solution();

	return 0;
}