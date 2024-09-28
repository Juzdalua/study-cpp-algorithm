#include <bits/stdc++.h>
using namespace std;

/*
	N개의 정수가 주어진다
	이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 구하라
*/

int n, m;
vector<long long> ns, ms, result;
map<int, int> nMap;

void Solution()
{
	sort(ns.begin(), ns.end());
	long long maxN = ns[ns.size() - 1];
	long long mid = ns[ns.size() / 2];

	for (int i = 0; i < m; i++)
	{
		if (ms[i] > maxN)
		{
			result.push_back(0);
			continue;
		}

		auto it = nMap.find(ms[i]);
		if(it == nMap.end())
			result.push_back(0);
		else
			result.push_back(1);
		/*auto it = find(ns.begin(), ns.end(), ms[i]);
		if (it == ns.end())
			result.push_back(0);
		else
			result.push_back(1);*/
	}

	for (long long& r : result)
		cout << r << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		ns.push_back(input);

		nMap[input] = 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		ms.push_back(input);
	}

	Solution();

	return 0;
}