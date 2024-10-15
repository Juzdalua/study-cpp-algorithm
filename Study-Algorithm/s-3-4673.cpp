#include <bits/stdc++.h>
using namespace std;

/*
	���� ����N
	d(n) => n�� n�� �� �ڸ����� ���ϴ� �Լ�
	d(75) = 75+7+5 = 87

	33 + 3 + 3 = 39
	39 + 3 + 9 = 51
	51 + 5 + 1 = 57
	33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...

	n�� d(n)�� ������
	101�� �����ڴ� 91, 100 �ΰ�
	�����ڰ� ���¼��� �����ѹ�

	100���� ���� ���� �ѹ��� �� 13���� �ִ�.
	1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97

	10000���� �۰ų� ���� ���� �ѹ��� �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	map<int, int> m;
	for (int i = 1; i <= 10'000; i++)
	{
		string s = to_string(i);
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			sum += s[i] - '0';
		}
		int num = i + sum;
		if (num <= 10'000)
			m[num]++;
	}

	/*for (auto& mm : m)
		cout << mm.first << " : " << mm.second << '\n';*/

	for (int i = 1; i <= 10'000; i++)
	{
		if (m[i] == 0)
			cout << i << '\n';
	}

	return 0;
}