#include <bits/stdc++.h>
using namespace std;

/*
	정사각형 모양의 종이
	하얀색 또는 파란색
	규칙을 따라 잘라서 파란+하얀 종이를 만든다

	전체 종이의 크기가 N×N(N=2k, k는 1 이상 7 이하의 자연수
	전체가 모두 같은색이 아니면, 가로와 세로 중간부분을 잘라서 네개의 종이로 나눈다.
	-> N * N -> 2/N * 2/N 4개
	나눈 종이도 동일하게 진행한다.

	잘라진 종이 모두가 하얀색 또는 파란색이 될 때까지 반복한다
	아니면 한칸이 되어 더이상 자를 수 없으면 멈춘다.

	최종적으로 잘라진 하얀종이와 파란종이 개수를 출력하라
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

	//// 한장이면 탈출
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

	// 탐색
	int checkSum = 0;
	for (int i = startX; i <= endX; i++)
	{
		for (int j = startY; j <= endY; j++)
		{
			checkSum += board[i][j];
		}
	}

	// 모두 색이 같으면 탈출
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

	// 4개로 나누기

	// 11시
	Cut(startX, startY, endX - size / 2, endY - size / 2);

	// 1시
	Cut(startX, startY + size / 2, endX - size / 2, endY);

	// 5시
	Cut(startX + size / 2, startY, endX, endY - size / 2);

	// 7시
	Cut(startX + size / 2, startY + size / 2, endX, endY);


}

void Solution()
{
	//cout << "Sum: " << inputSum << endl;
	// 모두 칠해져있을 경우
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

	Cut(0, 0, n / 2 - 1, n / 2 - 1); // 11시
	Cut(0, n / 2, n / 2 - 1, n - 1); // 1시
	Cut(n / 2, 0, n - 1, n / 2 - 1); // 5시
	Cut(n / 2, n / 2, n - 1, n - 1); // 7시

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