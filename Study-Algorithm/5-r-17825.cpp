#include <bits/stdc++.h>
using namespace std;

/*
	시작칸에 말 4개
	10턴, 1~5 주사위
	이동마다 점수가 추가된다.
	점수의 최대값

	말이 이동을 마치는 칸에 다른 말이 있으면 이동할 수 없다.
	도착한 말은 고를 수 없다.

	2 - 4 - 6 - 8 - 10

	10 - 12 - 14 - 16 - 18 - 20
	10 - 13 - 16 - 19 - 25

	20 - 22 - 24 - 26 - 28 - 30
	20 - 22 - 24 - 25

	30 - 32 - 34 - 36 - 38 - 40
	30 - 28 - 27 - 26 - 25

	25 - 30 - 35 - 40

	40 - 0
*/

int jusawi[14];
vector<vector<int>> board(104);
int val[104];
int mal[5]; // board, pos
int sum;
int maxResult = INT_MIN;

void PrintBoard()
{
	cout << "== Board ==" << '\n';
	for (int i = 0; i < 44; i++)
	{
		if (board[i].size() == 0)
			continue;

		cout << i << " -> ";
		if (board[i].size() > 1)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				cout << board[i][j] << ", ";
			}
		}
		else
			cout << board[i][0];
		cout << '\n';
	}

	cout << "== Value ==" << '\n';
	for (int i = 0; i <= 100; i++)
	{
		if (val[i] == 0)
			continue;
		cout << "Val[" << i << "]: " << val[i] << '\n';
	}
	cout << '\n';
}

void MakeBoard()
{
	// 빨간 보드
	for (int i = 0; i < 20; i++)
		board[i].push_back(i + 1);
	board[20].push_back(100);

	for(int i=21; i<26; i++)
		board[i].push_back(i + 1);

	board[27].push_back(28);
	board[29].push_back(30);
	board[30].push_back(31);

	board[5].push_back(21); // 10-13
	board[10].push_back(27); // 20-22
	board[15].push_back(29); // 30-28
	board[26].push_back(20); // 35-40

	board[28].push_back(24); // 24-25
	board[31].push_back(24); // 26-25

	for (int i = 1; i <= 20; i++)
		val[i] = i * 2;
	val[21] = 13;
	val[22] = 16;
	val[23] = 19;
	val[24] = 25;
	val[25] = 30;
	val[26] = 35;

	val[27] = 22;
	val[28] = 24;

	val[29] = 28;
	val[30] = 27;
	val[31] = 26;
}

bool Check(int nextPos)
{
	if (nextPos == 100)
		return false;

	for (int i = 0; i < 4; i++)
	{
		if (mal[i] == 100)
			continue;

		if (mal[i] == nextPos)
			return true;
	}
	return false;
}

int Move(int i, int count)
{
	int addPos = jusawi[count];

	int startPos = mal[i];
	int curPos = startPos;
	int nextPos = curPos;

	while (addPos--)
	{
		// 파랑 화살표 시작
		if (curPos == startPos && (startPos == 5 || startPos == 10 || startPos == 15))
			nextPos = board[curPos][1];
		else
			nextPos = board[curPos][0];

		if (nextPos == 100)
			break;

		curPos = nextPos;
	}
	return nextPos;
}

void Go(int count)
{
	if (count >= 10)
	{
		//cout << "End -> " << sum << '\n';
		maxResult = max(maxResult, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		// 도착한 말인지 체크
		if (mal[i] == 100)
			continue;

		// 시작지점 체크 -파랑, 빨강
		int nextPos = Move(i, count);

		// 주사위 칸에 말이 있는지 체크
		if (Check(nextPos))
			continue;

		// temp
		int temp = mal[i];

		//cout<<"Count: " << count << ", Mal: " << i << ", Jusawi: " << jusawi[count] << ", Val: " << val[nextPos] << ", CurPos: " << mal[i]  << ", NextPos: " << nextPos << '\n';

		// 이동
		mal[i] = nextPos;
		sum += val[nextPos];

		Go(count + 1);

		// 백트래킹
		mal[i] = temp;
		sum -= val[nextPos];
	}
}

void Solution()
{
	MakeBoard();
	//PrintBoard();
	Go(0);

	cout << maxResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		cin >> jusawi[i];
	}

	Solution();

	return 0;
}