#include <bits/stdc++.h>
using namespace std;

/*
		__ _   _ _____
	 __|  | | | |   | |
	|  |  | |_| | | | |
	|_____|_____|_|___|


*/

int n, r, c;
long long result;

int dy[4] = { 0,0, 1, 0 };
int dx[4] = { 0,1,-1,1 };

int SetResult()
{
	int mid = pow(2, n-1);

	if (r >= mid)
	{
		result += pow(mid, 2) * 2;
	}
	if (c >= mid)
	{
		result += pow(mid, 2);
	}

	r %= mid;
	c %= mid;

	return mid;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> c;
	
	int len = SetResult();
	//cout << r << " " << c << " "<<result<< '\n';

	int x = 0;
	int y = 0;
	if (r == 0 && c == 0)
	{
		cout << result << '\n';
		exit(0);
	}

	while (true)
	{
		for (int i = 0; i < 4; i++)
		{
			//cout << "Result -> " << result << ", (" << y << ", " << x << ")" << '\n';
			y += dy[i];
			x += dx[i];
			if (y == r && x == c) 
			{
				cout << result << '\n';
				exit(0);
			}
			result++;
		}
		
		if (x < len - 1)
		{
			x++;
			y--;
		}
		else
		{
			x = 0;
			y++;
		}
	}

	return 0;
}