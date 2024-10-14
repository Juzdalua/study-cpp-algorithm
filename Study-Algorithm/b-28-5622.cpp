#include <bits/stdc++.h>
using namespace std;

/*

*/

int timer = 2;
string s;

int Convert(char ch)
{
	if (ch >= 'A' && ch <= 'C')
		return 2;
	else if (ch >= 'D' && ch <= 'F')
		return 3;
	else if (ch >= 'G' && ch <= 'I')
		return 4;
	else if (ch >= 'J' && ch <= 'L')
		return 5;
	else if (ch >= 'M' && ch <= 'O')
		return 6;
	else if (ch >= 'P' && ch <= 'S')
		return 7;
	else if (ch >= 'T' && ch <= 'V')
		return 8;
	else if (ch >= 'W' && ch <= 'Z')
		return 9;
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		int num = Convert(ch);
		int time = timer + num - 1;
		sum += time;
	}
	cout << sum << '\n';


	return 0;
}