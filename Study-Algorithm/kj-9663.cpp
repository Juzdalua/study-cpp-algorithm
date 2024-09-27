#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	ũ�� N * N ü����
	��N���� ���� ������ �� ���� ���´�
	���� ���� ����� ���� ���϶�
	1 �� N < 15
*/

int n;
int posX[20];
int posY[20];

int Go(int y, int x)
{
	// ���� ó��
	for (int i = 0; i < y; i++)
	{
		// ���� ��ħ
		if (y == posY[i])
			return 0;

		// ���� ��ħ
		if (x == posX[i])
			return 0;

		// �밢�� ��ħ - ������ �밢���� x-y ���̰� �����ϴ�.
		if (abs(x - posX[i]) == abs(y - posY[i]))
			return 0;
	}

	// ��������
	if (y == n - 1)
	{
		return 1;
	}

	// ��ġ ����
	posX[y] = x;
	posY[y] = y;

	// ����Լ�
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += Go(y + 1, i);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += Go(0, i);
	}

	return 0;
}