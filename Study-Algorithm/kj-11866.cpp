#include <bits/stdc++.h>
using namespace std;

/*
	1~N�� ����� ���� �̷�� �ɾ��ִ�
	K��° ����� ����
	N���� ��� ���ŵɶ����� �ݺ�

	������� ���ŵǴ� ���� (n,k)
	(7,3) ->  <3, 6, 2, 7, 5, 1, 4>
	1 �� K �� N �� 1,000
*/

int n, k;
queue<int> circle;
vector<int> result;

void Solution()
{
	int cnt = 0;
	while (!circle.empty())
	{
		int cur = circle.front();
		circle.pop();

		cnt++;

		if (cnt < k)
		{
			circle.push(cur);
		}
		else if (cnt == k)
		{
			cnt = 0;
			result.push_back(cur);
		}
	}

	cout << "<";
	for (int i=0; i<n; i++)
	{
		cout << result[i];
		if (i != n - 1)
		{
			cout << ", ";
		}
	}
	cout << ">";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		circle.push(i);
	}

	Solution();

	return 0;
}