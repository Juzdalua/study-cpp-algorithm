#include <iostream>
using namespace std;

/*
	0 �Ǵ� 1 ������ Ÿ��
	1 �Ǵ� 00 Ÿ��

	ũ�Ⱑ N�� 2������ -> 00, 11
	=> 01, 10 �Ұ���
	N = 1 -> 1
	N = 2 -> 00, 11
	N = 3 -> 100, 001, 000
	N = 4 -> 0011, 0000, 1100, 1111, 1001

	Ÿ���� ������ ����.
	N�� �־����� ��, ���� �� �ִ� ��� ������
	1 <= N <= 1'000'000
*/

int n;
const int devider = 15746;
int dp[1'000'004];

void Solution()
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		// i-1�� 1 ���̱� + i-2�� 00 ���̱�
		dp[i] = (dp[i - 1] + dp[i - 2]) % devider;
	}

	cout << dp[n] << '\n'; // dp[n]�� N������ ������ ����
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	Solution();

	return 0;
}