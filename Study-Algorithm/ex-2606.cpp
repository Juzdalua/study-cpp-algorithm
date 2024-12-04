#include <bits/stdc++.h>
using namespace std;

/*

*/

int n;
int cnt;
vector<int> arr[104];
map<int, int> m;

void Go(int start)
{
	//cout << "Go -> " << start << '\n';
	vector<int> here = arr[start];

	for (int i = 0; i < here.size(); i++)
	{
		if (m[here[i]] == 0)
		{
			m[here[i]]++;
			Go(here[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int t = 0;
	cin >> t;

	while (t--)
	{
		int mother = 0;
		cin >> mother;

		int input;
		cin >> input;
		arr[mother].push_back(input);
		arr[input].push_back(mother);
	}

	/*for (int i = 1; i < 8; i++)
	{
		cout << i << " -> ";
		for (auto& a : arr[i])
			cout << a << " ";
		cout << '\n';
	}
	return 0;*/

	m[1] = 1;
	Go(1);
	for (auto& mm : m)
	{
		if (mm.second != 0)
			cnt++;
	}

	cout << cnt - 1 << '\n';

	return 0;
}