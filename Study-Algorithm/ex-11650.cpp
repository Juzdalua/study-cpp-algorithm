#include <bits/stdc++.h>
using namespace std;

/*

*/

int n;
vector<pair<int, int>> v;

bool Compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input1, input2;
		cin >> input1 >> input2;
		v.push_back({ input1, input2 });
	}

	sort(v.begin(), v.end(), Compare);
	for (auto& vv : v)
		cout << vv.first << " " << vv.second << '\n';
	cout << '\n';

	return 0;
}