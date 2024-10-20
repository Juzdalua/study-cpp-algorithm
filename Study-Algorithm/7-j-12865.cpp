#include <bits/stdc++.h>
using namespace std;

/*
	N개의 물건
	무게W, 가치V
	가치만큼 즐길수있다.
	최대 K만큼 무게의 배낭
	물건들 가치의 최대값을 구하라

	1 ≤ N ≤ 100
	1 ≤ K ≤ 100,000
	1 ≤ W ≤ 100,000
	0 ≤ V ≤ 1,000
*/

int n, k;
vector<pair<int, int>> v;
long long dp[100'004];

bool Compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}

void Solution()
{
	sort(v.begin(), v.end(), Compare);

	for (pair<int, int>& vv : v)
	{
		int weight = vv.first;
		int value = vv.second;

		//cout << "Weight: " << weight << ", Value: " << value << '\n';
		for (int j = k; j >= weight; j--)
		{
			//cout << "j: " << j << ", dp[j]: " << dp[j] << ", dp[j - weight]: " << dp[j - weight];
			dp[j] = max(dp[j], dp[j - weight] + value);
			//cout << ", Update -> " << dp[j] << '\n';
		}
		//cout << '\n';
	}
	cout << dp[k] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		v.push_back({ in1,in2 });
	}

	Solution();

	return 0;
}