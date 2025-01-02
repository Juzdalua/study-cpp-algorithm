#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int t;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		int h, w, n;
		cin >> h >> w >> n;

		int y = n % h;
		int x = n / h;

		if (y != 0) x++;
		if (y == 0) y = h;

		/*cout << "y -> " << y << '\n';
		cout << "x -> " << x << '\n';*/

		string head = to_string(y);
		string tail = to_string(x);
		if (tail.size() == 1) {
			reverse(tail.begin(), tail.end());
			tail.push_back('0');
			reverse(tail.begin(), tail.end());
		}
		cout << head + tail << '\n'; 
	}

	return 0;
}