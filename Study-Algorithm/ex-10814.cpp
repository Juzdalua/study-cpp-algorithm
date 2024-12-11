#include <bits/stdc++.h>
using namespace std;

/*

*/

int n;
vector<tuple<int, int, string>> v;

bool Compare(tuple<int, int, string>& a, tuple<int, int, string>& b)
{
	if (get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
	return get<1>(a) < get<1>(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input1;
		string input2;
		cin >> input1 >> input2;
		v.push_back({i, input1, input2 });
	}
	sort(v.begin(), v.end(), Compare);
	for (auto& vv : v)
		cout << get<1>(vv) << " " << get<2>(vv) << '\n';

	return 0;
}