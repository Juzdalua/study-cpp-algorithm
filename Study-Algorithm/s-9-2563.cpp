#include <bits/stdc++.h>
using namespace std;

/*
	���� ���� 100
	����10,����10 ������
	�����̰� ���� ���̸� ���϶�
	��ġ�� �κ��� �����Ѵ�

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