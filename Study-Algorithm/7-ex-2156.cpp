#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> 
using namespace std;

/*
	�پ��� �����ְ� ����ִ� ���� �Ϸķ� �����ִ�
	�ýĿ��� ��Ģ�� �ִ�

	1. ������ ���� �����ϸ� �� ���� ��� ���ž��ϰ�, ���� �� ���� ��ġ�� ���ƾ� �Ѵ�
	2. �������� �����ִ� 3���� ��� ���� �� ����.
	�ִ��� ���� �����ָ� ���Ŵ�
	1������ n������ ���������� ������� �ִ�.
	�� �������� ���� �־�����.

	���� ���� ������ ���� ���
	f(n) = f(n-1)

	���� ���� �����ؼ� ���� ���
	f(n) = f(n-3) + n-1 + n

	���� ���� �����ؼ� ������ ���� ���
	f(n) = f(n-2) + n
*/

int n;
int grape[10'004];
int dp[10'004];

void Solution()
{
	dp[0] = 0;
	dp[1] = grape[1];
	dp[2] = grape[1] + grape[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(max(dp[i - 1], dp[i - 3] + grape[i - 1] + grape[i]), dp[i - 2] + grape[i]);
	}

	/*for (int i = 1; i <= n; i++)
		cout << "i: " << i << ", dp[i]: " << dp[i] << endl;*/
	cout << dp[n] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> grape[i];
	}

	memset(dp, -1, sizeof(dp));
	Solution();

	return 0;
}