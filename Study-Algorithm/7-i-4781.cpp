#include <bits/stdc++.h>
using namespace std;

/*
	���� ������ ������ �����Ѵ�
	������ ������ Į�θ��� ���� ����� �̱��
	�� ������ ������ ������ ����.
	������ �ɰ�������
	Į�θ��� ���� ���� ũ�� �Ǵ����� ���ϴ� ���α׷�

	int ������ ���� 1 �� n �� 5,000,
	double �� 0.01 �� m �� 100.00
	int �� 1 <= money <= 100'000
	int Į�θ� 1 �� c �� 5,000,
	double ���� 0.01 �� p �� 100.00
*/

int n;
string m;
int money;
vector<pair<int, int>> v;
long long dp[100'004];

void Solution()
{
	 money = stoi(m.substr(0, m.find(".")) + m.substr(m.find(".") + 1));
	 memset(dp, 0, sizeof(dp));

	for (pair<int, int>& satang : v)
	{
		int kcal = satang.first;
		int pay = satang.second;

		for (int i = pay; i <= money; i++)
		{
			dp[i] = max(dp[i], dp[i - pay] + kcal);
		}
	}
	cout << dp[money] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		cin >> n >> m;
		if (n == 0)
		{
			break;
		}

		v.clear();
		for (int i = 0; i < n; i++)
		{
			int in1;
			string in2;
			cin >> in1 >> in2;
			string s = in2.substr(0, in2.find(".")) + in2.substr(in2.find(".") + 1);
			v.push_back({ in1,stoi(s)});
		}
		Solution();
	}

	return 0;
}