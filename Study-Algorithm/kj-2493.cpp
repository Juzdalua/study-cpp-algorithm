#include <bits/stdc++.h>
using namespace std;

/*
	일직선 위에 높이가 서로 다른 N개의 탑
	왼쪽부터 오른쪽으로 세운다
	탑 꼭대기에 레이저 위치
	레이저는 지표면과 평행하게 왼쪽으로 발사
	발사된 레이저는 가장 먼저 만나는 탑에서만 수신이 가능

	6, 9, 5, 7, 4
	4 -> 7
	7 -> 9
	5 -> 9
	9 -> x
	6 -> x
	탑들의 개수 N과 탑들의 높이가 주어질 때, 각각의 탑에서 발사한 레이저 신호를 어느 탑에서 수신하는지를 알아내는 프로그램을 작성하라.

	1 <= n <= 500'000
	1 <= h <= 100,000,000
*/

int n;
vector<int> tower;
vector<int> result;
map<int, int> nMap;

void Solution()
{
	result.push_back(0);

	for (int i = 1; i < n; i++)
	{
		int num = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (tower[j] > tower[i])
			{
				num = tower[j];
				break;
			}
		}
		result.push_back(num);
	}

	for (int r : result)
	{
		cout << nMap[r] << " ";
		//cout << r << " ";
	}
	cout << '\n';
}

void Solution2()
{
	stack<int> s;
	int maxT = -1;
	for (int i = 0; i < n; i++)
	{
		int target = tower[i];

		if (s.empty())
		{
			result.push_back(0);
		}
		else
		{
			while (true)
			{
				if (s.empty())
				{
					result.push_back(0);
					break;
				}
				int prev = s.top();
				if (prev <= target)
				{
					s.pop();
				}
				else
				{
					result.push_back(prev);
					break;
				}
			}
		}
		s.push(target);
	}

	for (int r : result)
	{
		cout << nMap[r] << " ";
		//cout << r << " ";
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		tower.push_back(input);
		nMap[input] = i + 1;
	}

	Solution2();

	return 0;
}