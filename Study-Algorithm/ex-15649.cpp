#include <bits/stdc++.h>
using namespace std;

/*

*/

int n, m;
vector<int> v;
vector<vector<int>> r;

//bool Compare(vector<int>& a, vector<int>& b)
//{
//
//}

void combi(int idx, vector<int>& vv)
{
	if (vv.size() == m)
	{
		do {
			/*for (int& i : vv)
				cout << i << " ";
			cout << '\n';*/
			r.push_back(vv);
		} while (next_permutation(vv.begin(), vv.end()));

		/*for (int& i : vv)
			cout << i << " ";
		cout << '\n';*/
		return;
	}

	for (int i = idx + 1; i < n; i++)
	{
		vv.push_back(v[i]);
		combi(i, vv);
		vv.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		v.push_back(i);

	vector<int> vv;
	combi(-1, vv);

	sort(r.begin(), r.end());
	for (vector<int>& i : r)
	{
		for(int& rr : i)
			cout << rr << " ";
		cout << '\n';
	}

	return 0;
}