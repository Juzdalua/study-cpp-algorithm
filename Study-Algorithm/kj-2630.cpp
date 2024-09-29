#include <bits/stdc++.h>
using namespace std;

/*
	���簢�� ����� ����
	�Ͼ�� �Ǵ� �Ķ���
	��Ģ�� ���� �߶� �Ķ�+�Ͼ� ���̸� �����

	��ü ������ ũ�Ⱑ N��N(N=2k, k�� 1 �̻� 7 ������ �ڿ���
	��ü�� ��� �������� �ƴϸ�, ���ο� ���� �߰��κ��� �߶� �װ��� ���̷� ������.
	-> N * N -> 2/N * 2/N 4��
	���� ���̵� �����ϰ� �����Ѵ�.

	�߶��� ���� ��ΰ� �Ͼ�� �Ǵ� �Ķ����� �� ������ �ݺ��Ѵ�
	�ƴϸ� ��ĭ�� �Ǿ� ���̻� �ڸ� �� ������ �����.

	���������� �߶��� �Ͼ����̿� �Ķ����� ������ ����϶�
*/

int n;
int MAX = 128;
int board[132][132];
int inputSum = 0;
int white = 0;
int blue = 0;

void PrintReturn()
{
	cout << white << '\n';
	cout << blue << '\n';
	exit(0);
}

void Cut(int startX, int startY, int endX, int endY)
{
	int size = abs(startX - endX) + 1;
	//cout << "SIZE: " << size << ", START: (" << startX << ", " << startY << "), END : (" << endX << ", " << endY << ")" << endl;

	//// �����̸� Ż��
	if (size == 1)
	{
		if (board[startX][startY] == 0)
		{
			//cout << "ONE WHITE" << endl;
			white++;
			return;
		}
		else
		{
			//cout << "ONE BLUE" << endl;
			blue++;
			return;
		}
	}

	// Ž��
	int checkSum = 0;
	for (int i = startX; i <= endX; i++)
	{
		for (int j = startY; j <= endY; j++)
		{
			checkSum += board[i][j];
		}
	}

	// ��� ���� ������ Ż��
	if (checkSum == 0)
	{
		//cout << "All WHITE" << endl;
		white++;
		return;
	}
	else if (checkSum == size * size)
	{
		//cout << "All BLUE" << endl;
		blue++;
		return;
	}

	// 4���� ������

	// 11��
	Cut(startX, startY, endX - size / 2, endY - size / 2);

	// 1��
	Cut(startX, startY + size / 2, endX - size / 2, endY);

	// 5��
	Cut(startX + size / 2, startY, endX, endY - size / 2);

	// 7��
	Cut(startX + size / 2, startY + size / 2, endX, endY);


}

void Solution()
{
	//cout << "Sum: " << inputSum << endl;
	// ��� ĥ�������� ���
	if (inputSum == n * n)
	{
		white = 0;
		blue = 1;
		PrintReturn();
	}
	else if (inputSum == 0)
	{
		white = 1;
		blue = 0;
		PrintReturn();
	}

	Cut(0, 0, n / 2 - 1, n / 2 - 1); // 11��
	Cut(0, n / 2, n / 2 - 1, n - 1); // 1��
	Cut(n / 2, 0, n - 1, n / 2 - 1); // 5��
	Cut(n / 2, n / 2, n - 1, n - 1); // 7��

	PrintReturn();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 1)
				inputSum++;
		}
	}

	Solution();

	return 0;
}