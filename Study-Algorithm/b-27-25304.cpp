#include <bits/stdc++.h>
using namespace std;

/*

*/

int x, n;
vector<pair<int, int>> v;
const string YES = "Yes";
const string NO = "No";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	long long sum = 0;
	for (int i = 0;i < n; i++)
	{
		sum += v[i].first * v[i].second;
	}

	if (sum == x)
		cout << YES << '\n';
	else
		cout << NO << '\n';

	return 0;
}