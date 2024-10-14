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
	// ���� ����
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
		// �Ķ� ȭ��ǥ ����
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
		// ������ ������ üũ
		if (mal[i] == 100)
			continue;

		// �������� üũ -�Ķ�, ����
		int nextPos = Move(i, count);

		// �ֻ��� ĭ�� ���� �ִ��� üũ
		if (Check(nextPos))
			continue;

		// temp
		int temp = mal[i];

		//cout<<"Count: " << count << ", Mal: " << i << ", Jusawi: " << jusawi[count] << ", Val: " << val[nextPos] << ", CurPos: " << mal[i]  << ", NextPos: " << nextPos << '\n';

		// �̵�
		mal[i] = nextPos;
		sum += val[nextPos];

		Go(count + 1);

		// ��Ʈ��ŷ
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