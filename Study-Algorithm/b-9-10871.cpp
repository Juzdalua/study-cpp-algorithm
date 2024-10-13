#include <bits/stdc++.h>
using namespace std;

/*
	1 ¡Â N, X ¡Â 10,000
*/

int n, x;
int arr[10'004];
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] < x)
			result.push_back(arr[i]);
	}

	for (int r : result)
		cout << r <<   " ";

	return 0;
}