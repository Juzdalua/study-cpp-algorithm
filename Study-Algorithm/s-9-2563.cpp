#include <bits/stdc++.h>
using namespace std;

/*
	가로 세로 100
	가로10,세로10 색종이
	색종이가 붙은 넓이를 구하라
	겹치는 부분은 빼야한다

	(x,y) -> (x+10,y), (x,y+10), (x+10,y+10)
*/

int n;
vector<pair<int, int>> inputs;
int arr[104][104];
int result;
int sum;

void Print()
{
	cout << '\n';
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

void Solution()
{
	for (auto& v : inputs)
	{
		for (int i = v.first; i < v.first + 10; i++)
		{
			for (int j = v.second; j < v.second + 10; j++)
			{
				if(arr[i][j] == 0)
					arr[i][j]++;
			}
		}
	}
	//Print();
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1)
				sum++;
		}
	}

	cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		inputs.push_back({ in1,in2 });
	}

	Solution();

	return 0;
}