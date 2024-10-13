#include <bits/stdc++.h>
using namespace std;

/*
	0 <= N <= 99

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string a = to_string(n);

	int count = 0;
	while (true)
	{
		if (a.size() == 1)
		{
			a = '0' + a;
		}

		int l = a[0] - '0';
		int r = a[1] - '0';

		char right = to_string(l + r).back();
		char left = a.back();

		a[0] = left;
		a[1] = right;
		//cout << "Count: " << count << ", Left: " << left << ", Right: " << right << ", A: " << a << '\n';
		count++;
		
		if (stoi(a) == n)
			break;
	}
	cout << count << '\n';

	return 0;
}