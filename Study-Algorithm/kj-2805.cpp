#include <bits/stdc++.h>
using namespace std;

/*
	���� M���Ͱ� �ʿ��ϴ�

	���ܱ⿡ ���� H�� �����Ѵ�
	�鳯�� �����κ��� H ���� �ö󰣴�.
	���ٿ� ������ ������ ��� ����
	���̰� H���� ū ������ ���κ��� �߸���, ���� ������ �߸��� �ʴ´�.

	20, 15, 10, 17 -> H=15 -> 15 15 10 15 -> 5+2=7���͸� ��������.

	������ �ּ������� �ڸ���
	��� M���� ���������Ѵ�.
	���� H�� �ִ밪�� ���϶�

	1 �� N �� 1,000,000
	1 �� M �� 2,000,000,000
*/

int n, m;
vector<int> tree;
long long h = -1;
int maxTree = -1;
long long result = 0;
long long maxResult = 0;

void Solution2()
{
	sort(tree.begin(), tree.end());

	int left = 0;
	int right = tree.back();
	while (left <= right)
	{
		h = (left + right) / 2;
		result = 0;

		for (int i = 0; i < n; i++)
		{
			if (tree[i] > h)
				result += tree[i] - h;
		}
		
		if (result >= m)
		{
			left = h + 1;
			maxResult = max(h, maxResult);
			//maxResult = h;
		}
		else
		{
			right = h - 1;
		}
	}
	cout << maxResult << '\n';
}

void Solution()
{
	h = maxTree;

	while (true)
	{
		h -= 1;
		for (int i = 0; i < tree.size(); i++)
		{
			if (tree[i] - h <= 0)
				continue;
			result += tree[i] - h;
		}

		if (result >= m)
		{
			cout << h << '\n';
			exit(0);
		}
		result = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		tree.push_back(input);
		maxTree = max(maxTree, input);
	}

	Solution2();

	return 0;
}