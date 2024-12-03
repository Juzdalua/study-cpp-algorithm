#include <bits/stdc++.h>
using namespace std;

/*

*/

int n, m;
bool arr[1'000'004];

void che()
{
	for (int i = 2; i <= n; i++)
	{
		if (arr[i])
			continue;
		for (int j = i * 2; j <= n; j += i)
		{
			arr[j] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	che();
	arr[1] = true;
	for (int i = m; i <= n; i++)
	{
		if (!arr[i])
			cout << i << '\n';
	}

	return 0;
}