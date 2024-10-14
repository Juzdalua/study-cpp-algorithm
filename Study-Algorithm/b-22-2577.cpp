#include <bits/stdc++.h>
using namespace std;

/*

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b, c;
	cin >> a >> b >> c;
	long long r = a * b * c;
	string s = to_string(r);
	
	map<int, int> m;
	for (int i = 0; i < 10; i++)
		m[i] = 0;

	for (int i = 0; i < s.size(); i++)
	{
		m[s[i]-'0']++;
	}

	for (auto& i : m)
		cout << i.second << '\n';


	return 0;
}