#include <bits/stdc++.h>
using namespace std;

/*
	Ź�� ���� N���� ��
	���� �����ư��� ���� ��������.
	���� 1�� �Ǵ� 3�� ��������
	������ ���� �������� ����� �̱��
	����̰� ���� �����Ѵ�.
	�̱�� ����� ���϶�

	���-Ȧ��
	����-¦��

	1 �� N �� 1000
*/

const string SK = "SK";
const string CY = "CY";
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	if (n % 2 == 0)
		cout << CY << '\n';
	else
		cout << SK << '\n';

	return 0;
}