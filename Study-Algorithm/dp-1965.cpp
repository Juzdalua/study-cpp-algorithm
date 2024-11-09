#include <bits/stdc++.h>
using namespace std;

/*
	������ü ����
	���ڸ��� ũ��
	�տ� �ִ� ������ ũ�Ⱑ �ڿ��ִ� ���� ũ�⺸�� ������ �տ��ִ� ���ڸ� �ڿ��ִ� ���ڿ� ���� �� �ִ�

	1, 5, 2, 3, 7
	ũ�� 1�� ���ڸ� ũ�� 5�� ���ڿ� �ְ�, �ٽ� �� ���ڸ� ũ�� 7�� ���� �ȿ� ���� �� �ִ�.

	�� ���� ���� �� �ִ� �ִ��� ���� ������ ����ϴ� ���α׷�
	1 �� n �� 1000
*/

int n;
int arr[1004];
int dp[1004];

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

	dp[0] = 1;
	for (int i = 1; i < n;i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int res = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		//cout << "i: " << i << ", dp: " << dp[i] << '\n';
		res = max(dp[i], res);
	}
	cout << res << '\n';

	return 0;
}