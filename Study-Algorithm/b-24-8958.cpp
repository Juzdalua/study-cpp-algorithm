#include <bits/stdc++.h>
using namespace std;

/*
	
*/

int n;
vector<string> inputs;
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		inputs.push_back(input);
	}

	for (string& s : inputs)
	{
		int sum = 0;

		int j = 1;
		for (int i = 0; i < s.size(); i++)
		{
			char now = s[i];
			if (now == 'O')
			{
				sum += j;
				j++;
			}
			else
			{
				j = 1;
			}
		}
		result.push_back(sum);
	}

	for (int& i : result)
		cout << i << '\n';

	return 0;
}