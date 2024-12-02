#include <bits/stdc++.h>
using namespace std;

/*
	depth 0: 1 -> 1
	depth 1: 2~7 -> 6
	depth 2: 8~19 -> 12
	depth 3: 20~37 -> 18
	depth 4: 38~61 -> 24
*/

int n;
int depth;
vector<vector<int>> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	long long lastNum = 1;
	while (true)
	{
		if (n <= lastNum)
			break;

		depth++;
		lastNum += depth * 6;
	}
	
	//cout << "depth: " << depth << ", lastNum: " << lastNum << '\n';
	cout << depth + 1 << '\n';

	return 0;
}