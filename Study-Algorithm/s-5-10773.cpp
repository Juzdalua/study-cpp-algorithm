#include <bits/stdc++.h>
using namespace std;

/*
	�߸��� ���� �θ��� 0�� ��ģ��.
	���� �ֱٿ� �� ���� �����.

	1 �� K �� 100,000
	0 <= n <=1,000,000
	������ "0" �� ��쿡�� ���� �ֱٿ� �� ���� �����, �ƴ� ��� �ش� ���� ����.
*/

int k;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
			v.pop_back();
		else
			v.push_back(input);
	}

	int sum = 0;
	for (int& vv : v)
		sum += vv;
	cout << sum << '\n';

	return 0;
}