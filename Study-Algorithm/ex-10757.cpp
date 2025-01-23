#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

string a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	int i = 0;
	string result = "0";
	while (true)
	{
		if (i >= a.size() && i >= b.size()) break;

		int numA = 0;
		int numB = 0;
		
		if (i < a.size()) numA = a[i] - '0';
		if (i < b.size()) numB = b[i] - '0';
		int res = numA + numB;
		res += result[i] - '0';
		int up = res / 10;
		res %= 10;
		result[i] = to_string(res)[0];
		result.push_back(to_string(up)[0]);
		
		i++;
	}
	if (result[result.size() - 1] == '0') result.pop_back();
	reverse(result.begin(), result.end());
	cout << result << '\n';

	return 0;
}