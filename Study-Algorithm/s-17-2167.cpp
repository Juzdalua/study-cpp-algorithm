#include <bits/stdc++.h>
using namespace std;

/*
	(i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합
	1 ≤ N, M ≤ 300

*/

struct location
{
	int startX, startY, endX, endY;
};

int n, m;
int arr[304][304];
vector<location> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int vSize = 0;
	cin >> vSize;
	for (int i = 0; i < vSize; i++)
	{
		int in1, in2, in3, in4;
		cin >> in1 >> in2 >> in3 >> in4;
		v.push_back({ in1 - 1,in2 - 1,in3 - 1,in4 - 1 });
	}

	vector<int> result;

	for (location& vv : v)
	{
		int sum = 0;

		for (int i = vv.startX; i <= vv.endX; i++)
		{
			for (int j = vv.startY; j <= vv.endY; j++)
			{
				sum += arr[i][j];
			}
		}
		result.push_back(sum);
	}
	for (int& r : result)
		cout << r << '\n';

	return 0;
}