#include <bits/stdc++.h>
using namespace std;

/*
	�ִ���
	1. �迭�� �ڿ��� x�� �ִ´�
	2. �迭���� ���� ū ���� ����ϰ�, �����Ѵ�.

	1 �� N �� 100,000 = 10^5 
	N * N = 10^10
*/

int n;
vector<int> arr;
priority_queue<int> pq;
vector<int> result;

void Solution()
{
	if (pq.empty())
	{
		cout << 0 << '\n';
		return;
	}

	cout << pq.top() << '\n';
	pq.pop();
}

void Solution2()
{
	if (pq.empty())
	{
		result.push_back(0);
		return;
	}

	result.push_back(pq.top());
	pq.pop();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			Solution();
			//Solution2();
		}
		else
		{
			arr.push_back(x);
			pq.push(x);
		}
	}

	/*for (auto& r : result)
		cout << r << '\n';*/

	return 0;
}