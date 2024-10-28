#include <bits/stdc++.h>
using namespace std;

/*
	a�� bȣ�� ����� (a-1)���� 1ȣ~bȣ���� ����� �� �ո�ŭ �����;� ��ƾ� �Ѵ�.
	k�� nȣ
	
	0��
	1ȣ - 1��
	2ȣ - 2��
	iȣ - i��
	1 �� k, n �� 14
*/

int n, k, t;
vector<int> result;
int dp[18][18];

int Go(int chung, int ho)
{
	if (ho == 1)
		return 1;
	
	if (chung == 0)
		return ho;

	int& res = dp[chung][ho];
	if (res != 0)
		return res;

	for (int i = 1; i <= ho; i++)
		res += Go(chung - 1, i);
	return res;
}

void Solution()
{
	int g = Go(k, n);

	result.push_back(g);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= n; i++)
		dp[0][i] = i;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> k >> n;
		Solution();
	}

	for (int& r : result)
		cout << r << '\n';

	return 0;
}