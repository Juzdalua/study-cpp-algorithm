#include <bits/stdc++.h>
using namespace std;

/*
	����1, �ƴϸ�0
	1. ������ 4�� ���
	2. 100�� ����� �ƴ� ��, �Ǵ� 400�� ����� ��
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	if((n%4 == 0 && n%100 != 0) || (n%4 == 0 && n%400 == 0))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return 0;
}