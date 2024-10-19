#include <bits/stdc++.h>
using namespace std;

/*
	같은 돈으로 사탕을 구매한다
	구매한 사탕의 칼로리가 높은 사람이 이긴다
	각 사탕의 갯수는 무한히 많다.
	사탕은 쪼갤수없다
	칼로리의 합이 가장 크게 되는지를 구하는 프로그램

	int 사탕의 종류 1 ≤ n ≤ 5,000,
	double 돈 0.01 ≤ m ≤ 100.00
	int 돈 1 <= money <= 100'000
	int 칼로리 1 ≤ c ≤ 5,000,
	double 가격 0.01 ≤ p ≤ 100.00
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