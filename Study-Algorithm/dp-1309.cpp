#include <bits/stdc++.h>
using namespace std;

/*
	1��N��100,000
	N * 2
	���ε�ĭ ����Nĭ
	���ڸ� ����, ���ο� �����ϰ� ���Ѽ� ����.
	���ڸ� ��ġ�ϴ� ����� ���� �� ���������� �˾Ƴ��� ���α׷�

	���ڸ� �� ������ ��ġ���� �ʴ� ��쵵 �ϳ��� ����� ��
*/

int n;
long long dp[100'004][3]; // 0-����, 1-����, 2-������
const int devider = 9901;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < 3; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] % devider + dp[i - 1][1] % devider + dp[i - 1][2] % devider;
		dp[i][1] = dp[i - 1][0] % devider + dp[i - 1][2] % devider;
		dp[i][2] = dp[i - 1][0] % devider + dp[i - 1][1] % devider;
	}

	long long result = 0;
	for (int i = 0; i < 3; i++)
		result = (result + dp[n][i]) % devider;

	cout << result << '\n';

	return 0;
}