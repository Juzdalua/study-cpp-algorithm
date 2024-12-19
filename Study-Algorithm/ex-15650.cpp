#include <bits/stdc++.h>
using namespace std;

/*

*/

int n, m;

void combi(int idx, vector<int>& v)
{
	if (v.size() == m)
	{
		for (int& vv : v)
			cout << vv << " ";
		cout << '\n';
		return;
	}

	for (int i = idx + 1; i <= n; i++)
	{
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<int> v;
	combi(0, v);

	return 0;
}