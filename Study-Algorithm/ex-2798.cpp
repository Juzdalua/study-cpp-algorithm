#include <bits/stdc++.h>
using namespace std;

/*
	�� 21 �����ʰ�, ���� �ִ��
	ī�忡 ��������
	N�� ī��, ����M
	3�� ��
	���� M�� �����ʰ� �ִ��� ������
	3���� ���� ���϶�

	5C3
*/
int n,m;
int card[104];
int maxResult = INT_MIN;

void Combi(vector<int>& v, int idx)
{
	if (v.size() == 3)
	{
		/*for (int vv : v)
			cout << vv << " ";
		cout << '\n';*/

		int sum = 0;
		for (int vv : v)
		{
			sum += vv;
		}
		if (sum == m)
		{
			cout << sum << '\n';
			exit(0);
		}
		else if (sum > m)
			return;
		else
		{
			maxResult = max(maxResult, sum);
		}
		
		return;
	}

	for (int i = idx + 1; i < n; i++)
	{
		v.push_back(card[i]);
		Combi(v, i);
		v.pop_back();
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
		cin >> card[i];
	}

	vector<int> v;
	Combi(v, -1);
	cout << maxResult << '\n';

	return 0;
}