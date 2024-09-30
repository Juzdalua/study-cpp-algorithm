#include <bits/stdc++.h>
using namespace std;

/*
	������ ���� ���̰� ���� �ٸ� N���� ž
	���ʺ��� ���������� �����
	ž ����⿡ ������ ��ġ
	�������� ��ǥ��� �����ϰ� �������� �߻�
	�߻�� �������� ���� ���� ������ ž������ ������ ����

	6, 9, 5, 7, 4
	4 -> 7
	7 -> 9
	5 -> 9
	9 -> x
	6 -> x
	ž���� ���� N�� ž���� ���̰� �־��� ��, ������ ž���� �߻��� ������ ��ȣ�� ��� ž���� �����ϴ����� �˾Ƴ��� ���α׷��� �ۼ��϶�.

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