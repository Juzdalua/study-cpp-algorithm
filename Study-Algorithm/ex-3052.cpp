#include <bits/stdc++.h>
using namespace std;

/*
	
*/

const int devider = 42;
int arr[10];
map<int, int> res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 10; i++)
	{
		res[arr[i] % devider]++;
	}

	cout << res.size() << '\n';

	return 0;
}