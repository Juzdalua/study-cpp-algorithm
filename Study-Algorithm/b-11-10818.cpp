#include <bits/stdc++.h>
using namespace std;

/*
	1 ¡Â N ¡Â 1,000,000
*/

int n;
int arr[1'000'004];
int minResult = INT_MAX;
int maxResult = INT_MIN;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		minResult = min(minResult, arr[i]);
		maxResult = max(maxResult, arr[i]);
	}

	cout << minResult << " " << maxResult << '\n';
		
	return 0;
}