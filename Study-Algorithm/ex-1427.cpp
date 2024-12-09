#include <bits/stdc++.h>
using namespace std;

/*

*/

string n;
bool Compare(int& a, int& b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	vector<int> v;
	for (int i = 0; i < n.size(); i++)
	{
		v.push_back(n[i] - '0');
	}

	sort(v.begin(), v.end(), Compare);
	for (int& vv : v)
		cout << vv;
	cout << '\n';

	return 0;
}