#include <bits/stdc++.h>
using namespace std;

/*
	N���� �������� ���� Ư���� ��ġ�� �ִ�.
	��ɲ��� �������� ��ġ�� M���� ��뿡���� ����� �����ϴ�.

	���� �����Ÿ� L
	��뿡�� ������ �Ÿ��� L���� �۰ų� ���� �������� ���
	���x, ����(a,b)�� �Ÿ��� |x-a| + b

	���� �� �ִ� ������ ���� ����϶�

	����� �� M (1 �� M �� 100,000)
	������ �� N (1 �� N �� 100,000)
	�����Ÿ� L (1 �� L �� 1,000,000,000)
	��ǥ�� �ִ밪 1,000,000,000 - 10��
*/

using int64 = long long;
int64 n, m, l;
vector<int64> hunter;
vector<pair<int64, int64>> animal;
int64 result;

void Solution()
{
	// �������� Ž��
	for (auto& a : animal)
	{
		int64 x, y;
		tie(x, y) = a;

		// ������ ���� ����� ��� ã��
		auto findRightKey = upper_bound(hunter.begin(), hunter.end(), x);
		int64 right = (findRightKey != hunter.end()) ? *findRightKey : LLONG_MAX; // ������ ���
		int64 left = (findRightKey != hunter.begin()) ? *(--findRightKey) : LLONG_MIN; // ���� ���

		int64 closeHunter = -1;
		if (abs(x - left) > abs(x - right))
			closeHunter = right;
		else
			closeHunter = left;

		// ���� �Ÿ� ���
		if (l >= abs(closeHunter - x) + y)
			result++;
	}
	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> l;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		hunter.push_back(input);
	}
	sort(hunter.begin(), hunter.end());

	for (int i = 0; i < n; i++)
	{
		int64 x, y;
		cin >> x >> y;

		// �����Ÿ� ��
		if (y > l)
			continue;


		// �����Ÿ� ���̸� ���� ���� ��ġ
		if (y == l)
		{
			if (find(hunter.begin(), hunter.end(), x) == hunter.end())
				continue;
		}

		// ������ ����
		animal.push_back(make_pair(x, y));
	}

	Solution();

	return 0;
}