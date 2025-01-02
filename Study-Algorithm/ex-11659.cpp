#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, m;
vector<int> v;
int arr[100'004];
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 1; i <= n; i++)
	{
		arr[i] = arr[i - 1] + v[i-1];
		//cout << arr[i] << " ";
	}
	//cout << '\n';

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		result.push_back(arr[end] - arr[start-1]);
	}

	for (int& r : result)
		cout << r << '\n';

	return 0;
}