#include <bits/stdc++.h>
using namespace std;

/*
	����ĭ�� �� 4��
	10��, 1~5 �ֻ���
	�̵����� ������ �߰��ȴ�.
	������ �ִ밪

	���� �̵��� ��ġ�� ĭ�� �ٸ� ���� ������ �̵��� �� ����.
	������ ���� �� �� ����.

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
vector<vector<int>> board(44);
int val[50];
pair<int, int> mal[5]; // board, pos
int sum;
int maxResult = INT_MIN;

void PrintBoard()
{
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
}

void MakeBoard()
{
	// ���� ����
	for (int i = 0; i <= 20; i++)
		board[i].push_back(i + 1);
	board[21].push_back(49);

	// 10
	board[5].push_back(22);
	board[22].push_back(8);
	board[8].push_back(23);
	board[23].push_back(24);

	// 20
	board[10].push_back(11);
	board[11].push_back(12);
	board[12].push_back(24);

	// 30
	board[15].push_back(14);
	board[14].push_back(25);
	board[25].push_back(13);
	board[13].push_back(24);

	// 25
	board[24].push_back(26);
	board[26].push_back(27);
	board[27].push_back(20);

	val[49] = 0;
	for (int i = 1; i < 20; i++)
		val[i] = i * 2;
	val[22] = 13;
	val[23] = 19;
	val[24] = 25;
	val[25] = 27;
	val[26] = 30;
	val[27] = 35;
}

bool Check(int idx, int nextPos)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == idx)
			continue;

		if (mal[i].second == 49)
			continue;

		if (nextPos == mal[i].second)
			return true;
	}

	return false;
}

pair<int, int> Move(int i, int count)
{
	int cnt = jusawi[count];
	int curBoard = mal[i].first;
	int curPos = mal[i].second;
	int nextPos = 0;

	if (curPos == 5 || curPos == 10 || curPos == 15)
		curBoard = curPos / 5;

	while (cnt--)
	{
		if (curBoard == 0)
		{
			nextPos = board[curPos][0];
		}
		else
		{
			if (board[curPos].size() > 1)
				nextPos = board[curPos].back();
			else
				nextPos = board[curPos][0];
		}

		if (nextPos == 49)
		{
			return { 0, 49 };
		}
	}
	return { curBoard, nextPos };
}

void Go(int count)
{
	if (count >= 10)
	{
		maxResult = max(maxResult, sum);
		//cout << "End -> " << sum << '\n';
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		// �������� üũ
		if (mal[i].second == 49)
			continue;

		// �ֻ�����ŭ �̵�
		int curBoard = mal[i].first;
		int curPos = mal[i].second;
		int nextPos = curPos;
		int nextBoard = curBoard;

		if (curBoard == 0)
			nextPos += jusawi[count];
		else
			tie(nextBoard, nextPos) = Move(i, count);

		// ���� ��ġ�� ���� �ִ��� üũ
		if (Check(i, nextPos))
			continue;

		//cout << "Jusawi: " << jusawi[count] << ", Mal -> " << i << ", Cur Pos: " << mal[i].second << ", Next Pos: " << nextPos << '\n';

		// ��Ʈ��ŷ
		pair<int, int> temp = mal[i];
		mal[i] = { nextBoard, nextPos };
		sum += val[nextPos];

		Go(count + 1);

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