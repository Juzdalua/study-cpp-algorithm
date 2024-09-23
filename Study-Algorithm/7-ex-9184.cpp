#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
	-50 ¡Â a, b, c ¡Â 50

*/

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	else if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	else if (a < b && b < c)
		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	else
		return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int dp[24][24][24];
int wdp(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	else if (a > 20 || b > 20 || c > 20)
		return wdp(20, 20, 20);

	else if (dp[a][b][c] != 0)
		return dp[a][b][c];

	else if (a < b && b < c)
		return dp[a][b][c] = wdp(a, b, c - 1) + wdp(a, b - 1, c - 1) - wdp(a, b - 1, c);

	else
		return dp[a][b][c] = wdp(a - 1, b, c) + wdp(a - 1, b - 1, c) + wdp(a - 1, b, c - 1) - wdp(a - 1, b - 1, c - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> results;
	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		//int result = w(a, b, c);
		int result = wdp(a, b, c);
		string str = "w(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ") = " + to_string(result);
		results.push_back(str);
	}

	for (string v : results)
		cout << v << '\n';

	return 0;
}