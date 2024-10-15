#include <bits/stdc++.h>
using namespace std;

/*
	¸ö¹«°Ô x, Å° y
	µ¢Ä¡ (x,y)

	2 ¡Â N ¡Â 50
	10 ¡Â x, y ¡Â 200
*/

int n;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		v.push_back({ in1,in2 });
	}

	vector<int> result;
	for (int i = 0; i < v.size(); i++)
	{
		int count = 1;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				count++;
		}
		result.push_back(count);
	}

	for (int& r : result)
		cout << r << " ";


	return 0;
}