#include <bits/stdc++.h>
using namespace std;

/*

*/

int n;
int arr[24];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "add")
		{
			int input;
			cin >> input;
			if (arr[input] == 0)
				arr[input] = 1;
		}
		else if (s == "remove")
		{
			int input;
			cin >> input;
			arr[input] = 0;
		}
		else if (s == "check")
		{
			int input;
			cin >> input;
			if (arr[input] == 0)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (s == "toggle")
		{
			int input;
			cin >> input;
			if (arr[input] == 0)
				arr[input] = 1;
			else
				arr[input] = 0;
		}
		else if (s == "all")
		{
			/*for (int i = 1; i <= 20; i++)
				arr[i] = 1;*/
			memset(arr, 1, sizeof(arr));
		}
		else if (s == "empty")
		{
			memset(arr, 0, sizeof(arr));
		}
	}

	return 0;
}