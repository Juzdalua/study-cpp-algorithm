#include <iostream>
#include <cstring> 
#include <algorithm>
#include <vector>
using namespace std;

/*
	크기 N * N 체스판
	퀸N개를 서로 공격할 수 없게 놓는다
	퀸을 놓는 방법의 수를 구하라
	1 ≤ N < 15
*/

int n;
int posX[20];
int posY[20];

int Go(int y, int x)
{
	// 예외 처리
	for (int i = 0; i < y; i++)
	{
		// 가로 겹침
		if (y == posY[i])
			return 0;

		// 세로 겹침
		if (x == posX[i])
			return 0;

		// 대각선 겹침 - 동일한 대각선은 x-y 차이가 동일하다.
		if (abs(x - posX[i]) == abs(y - posY[i]))
			return 0;
	}

	// 종료조건
	if (y == n - 1)
	{
		return 1;
	}

	// 위치 저장
	posX[y] = x;
	posY[y] = y;

	// 재귀함수
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