#include <bits/stdc++.h>
using namespace std;

/*
	1 <= n <= 1'000'000
*/

int n;
vector<int> inputs;

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
		inputs.push_back(input);
	}
	sort(inputs.begin(), inputs.end());
	for (auto& r : inputs)
		cout << r << '\n';

	return 0;
}