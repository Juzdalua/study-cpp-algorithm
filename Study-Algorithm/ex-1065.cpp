#include <bits/stdc++.h>
using namespace std;

/*
	�������� X
	�� �ڸ��� �������� = �Ѽ�
	�������� = ���ӵ� �ΰ��� ���� ���̰� ������ ����
	1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷�
*/

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n < 100)
	{
		cout << n << '\n';
		exit(0);
	}

	int result = 99;
	for (int i = 100; i <= n; i++)
	{
		string num = to_string(i);

		int sub = (num[1] - '0') - (num[0] - '0');
		//cout << "i: " << i << ", sub: " << sub << '\n';
		for (int j = 0; j < num.size() - 1; j++)
		{
			if (num[j + 1] - num[j] != sub)
				break;
			if (j == num.size() - 2)
			{
				//cout << "HAN -> " << i << '\n';
				result++;
			}
		}
	}

	cout << result << '\n';

	return 0;
}