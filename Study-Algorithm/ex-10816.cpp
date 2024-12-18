#include <bits/stdc++.h>
using namespace std;

/*

*/

int n, m;
map<int, int> card;
vector<int> result;

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
		card[input]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		result.push_back(card[input]);
	}

	for (int& r : result)
		cout << r << " ";
	cout << '\n';

	return 0;
}