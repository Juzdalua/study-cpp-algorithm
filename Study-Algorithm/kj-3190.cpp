#include <bits/stdc++.h>
using namespace std;

/*
	����� ������ ���̰� �þ��
	�� �Ǵ� �ڱ� �ڽŰ� ������ �״´�

	N * N ����
	(0,0) ����, ���� 1
	���ĭ���� ����� �ִ�.
	ó�� ������ �������̴�

	���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
	���� ���̳� �ڱ��ڽ��� ���� �ε����� ������ ������.
	���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
	���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�. ��, �����̴� ������ �ʴ´�.

	(2 �� N �� 100)
	(0 �� K �� 100)
	������ �� �ʿ� �������� ���
*/

int n, k, l;
int board[104][104];
int result = 0;
queue<pair<int, char>> dir;
pair<int, int> currentDir;
queue<pair<int, int>> pos;
pair<int, int> head;


void PrintBoard()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}

void Exit()
{
	cout << result << '\n';
	exit(0);
}

void Go(int y, int x)
{
	//cout << "\n START ---> Time: " << result << ", Y: " << y << ", X: " << x << ", Head: (" << head.first << ", " << head.second << ")" << ", Cur Dir: (" << currentDir.first << ", " << currentDir.second << "), LEN: " << pos.size() << '\n';
	// �ð� ����
	result++;

	// �Ӹ� �̵�
	head = make_pair(head.first + y, head.second + x);

	// �� üũ
	if (head.first >= n || head.second >= n || head.first < 0 || head.second < 0)
	{
		//cout << "WALL" << '\n';
		Exit();
	}

	// ���� üũ
	queue<pair<int, int>> tempPos = pos;
	//cout << "SIZE: " << pos.size() <<'\n' << "Pos: ";
	while(!tempPos.empty())
	{
		//cout << "(" << tempPos.front().first << ", " << tempPos.front().second << "), ";

		pair<int, int> check = tempPos.front();
		tempPos.pop();

		if (check.first == head.first && check.second == head.second)
		{
			//cout << "Collision" << '\n';
			Exit();
		}
	}
	//cout << "'\n";

	// ���� �̵�
	pos.push(head);

	// ��� ���� ������ ���� ����
	if (board[head.first][head.second] == 0)
	{
		//cout << "No Apple" << '\n';
		pos.pop();
	}

	// ���� ��� ����
	else
	{
		//cout << "Eat Apple" << '\n';
		board[head.first][head.second] = 0;
	}

	//cout << "MOVE ---> Time: " << result << ", Y: " << y << ", X: " << x << ", Head: (" << head.first << ", " << head.second << ")" << ", Cur Dir: (" << currentDir.first << ", " << currentDir.second << ")" << '\n';
	// ���� ����
	if (!dir.empty() && dir.front().first == result)
	{
		char nextDir = dir.front().second;
		dir.pop();
		//cout << "NOW : " << result << ", Next: " << nextDir << '\n';

		// ������ 90�� ȸ��
		if (nextDir == 'D')
		{
			// ����
			if (currentDir.first == 0 && currentDir.second == 1)
			{
				// �Ʒ�
				currentDir = make_pair(1, 0);
			}

			// �Ʒ�
			else if (currentDir.first == 1 && currentDir.second == 0)
			{
				// ��
				currentDir = make_pair(0, -1);
			}

			// ��
			else if (currentDir.first == 0 && currentDir.second == -1)
			{
				// ��
				currentDir = make_pair(-1, 0);
			}

			// ��
			else if (currentDir.first == -1 && currentDir.second == 0)
			{
				// ����
				currentDir = make_pair(0, 1);
			}
		}

		// ���� 90�� ȸ��
		else if (nextDir == 'L')
		{
			// ����
			if (currentDir.first == 0 && currentDir.second == 1)
			{
				// ��
				currentDir = make_pair(-1, 0);
			}

			// ��
			else if (currentDir.first == -1 && currentDir.second == 0)
			{
				// ��
				currentDir = make_pair(0, -1);
			}

			// ��
			else if (currentDir.first == 0 && currentDir.second == -1)
			{
				// �Ʒ�
				currentDir = make_pair(1, 0);
			}

			// �Ʒ�
			else if (currentDir.first == 1 && currentDir.second == 0)
			{
				// ����
				currentDir = make_pair(0, 1);
			}
		}
	}

	//cout << "GO ---> Time: " << result << ", Y: " << y << ", X: " << x << ", Head: (" << head.first << ", " << head.second << ")" << ", Cur Dir: (" << currentDir.first << ", " << currentDir.second << ")" << '\n';
	// �̵�
	Go(currentDir.first, currentDir.second);
}

void Solution()
{
	//PrintBoard();

	head = make_pair(0, 0);
	pos.push(make_pair(0, 0));
	currentDir = make_pair(0, 1); // y,x
	Go(currentDir.first, currentDir.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	memset(board, 0, sizeof(board));
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int sec;
		char direction;
		cin >> sec >> direction;
		dir.push(make_pair(sec, direction));
	}

	Solution();

	return 0;
}