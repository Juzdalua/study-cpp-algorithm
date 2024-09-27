#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/*
	�ϳ��� ž
	��밡 3��
	1�� ��뿡 n���� ������ �ִ�.
	�ݰ��� ū ������� �׿��ִ�.
	1->3���� �ű��.

	1. �� ���� �� ���� ���Ǹ� �ű� �� �ִ�.
	2. �׻� �� ������ �Ʒ� ���Ǻ��� �۾ƾ��Ѵ�.

	�ʿ��� �̵������� ���
	�̵�Ƚ���� �ּ�.
	N (1 �� N �� 100)

	n = 1
	1 -> 3

	n = 2
	1 -> 2 => temp
	1 -> 3 => to ---> ���� ū ����
	2 -> 3 => to

	n = 3
	1 -> 3 => temp
	2 -> 2 => temp
	3 -> 2 => temp
	1 -> 3 => to ---> ���� ū ����
	2 -> 1 => to
	2 -> 1 => to
	1 -> 3 => to

	f(n) = 1 + 2 * f(n-1)
	f(n) = 1 + 2 * (2^n-1 - 1) = 2^n - 1
*/

int n;
long long cnt = 0;

void HanoiWithPrint(int start, int from, int temp, int to)
{
	if (start == 1)
	{
		cout << from << " " << to << '\n';
		cnt++;
		return;
	}

	HanoiWithPrint(start - 1, from, to, temp);
	cout << from << " " << to << '\n';
	cnt++;
	HanoiWithPrint(start - 1, temp, from, to);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	string result = to_string(pow(2, n));
	result = result.substr(0, result.find('.'));
	result[result.size() - 1] -= 1;
	cout << result << '\n';

	if (n <= 20)
		HanoiWithPrint(n, 1, 2, 3);

	return 0;
}