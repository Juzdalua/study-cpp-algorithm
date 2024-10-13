#include <bits/stdc++.h>
using namespace std;

/*
	a ~ z
	97 ~ 122
*/

string s;
int arr[30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(arr, -1, sizeof(arr));
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		int asc = static_cast<int>(s[i]);
		//cout << asc << " ";
		if (arr[asc - 97] == -1)
			arr[asc - 97] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";

	return 0;
}