#include <bits/stdc++.h>
using namespace std;

/*

*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);

	auto start = 0;
	auto end= s.find(" ");
	vector<string> result;

	while (end != string::npos)
	{
		result.push_back(s.substr(start, end - start));
		start = end + 1;
		end = s.find(" ", start);
	}
	result.push_back(s.substr(start));

	int sum = 0;
	for (string r : result)
	{
		//cout << r << '\n';
		int trimCnt = 0;
		for (int i = 0; i < r.size(); i++)
		{
			if (r[i] == ' ')
				trimCnt++;
		}
		if (trimCnt == r.size())
			continue;
		sum++;
	}
	//cout << result.size() << '\n';
	cout << sum << '\n';

	return 0;
}