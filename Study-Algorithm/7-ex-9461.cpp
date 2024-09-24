#include <iostream>
#include <vector>
using namespace std;

/*
	ù �ﰢ�� = ���ﰢ��, ���� ���� 1
	�������� ���δ�
	���� �� �ﰢ���� ���� ���� k
	P(N) = ������ �ִ� ���ﰢ�� ���� ����
	P(1)���� P(10)���� ù 10�� ���ڴ� 1, 1, 1, 2, 2, 3, 4, 5, 7, 9

	2: p(4) = p(3) + p(1)
	2: p(5) = p(4)
	3: p(6) = p(5) + p(3)
	4: p(7) = p(6) + p(2)
	5: p(8) = p(7) + p(1)
	7: p(9) = p(8) + p(4)
	9: p(10) = p(9) + p(5)
	12: p(11) = p(10) + p(6)
	16: p(12) = p(11) + p(7)

	dp[n] = dp[n-2] + dp[n-3]
*/

long long dp[104];
vector<long long> result;

void Solution(long long n)
{
	if (dp[n] != 0)
	{
		result.push_back(dp[n]);
		return;
	}

	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	result.push_back(dp[n]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = dp[2] = dp[3] = 1;
	
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int input;
		cin >> input;

		Solution(input);
	}

	for (long long r : result)
		cout << r << '\n';

	return 0;
}