#include <bits/stdc++.h>
using namespace std;

/*
	사과를 먹으면 길이가 늘어난다
	벽 또는 자기 자신과 만나면 죽는다

	N * N 보드
	(0,0) 시작, 길이 1
	몇몇칸에는 사과가 있다.
	처음 방향은 오른쪽이다

	먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
	만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
	만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
	만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.

	(2 ≤ N ≤ 100)
	(0 ≤ K ≤ 100)
	게임이 몇 초에 끝나는지 출력
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
	// 시간 증가
	result++;

	// 머리 이동
	head = make_pair(head.first + y, head.second + x);

	// 벽 체크
	if (head.first >= n || head.second >= n || head.first < 0 || head.second < 0)
	{
		//cout << "WALL" << '\n';
		Exit();
	}

	// 몸통 체크
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

	// 몸통 이동
	pos.push(head);

	// 사과 먹지 않으면 꼬리 제거
	if (board[head.first][head.second] == 0)
	{
		//cout << "No Apple" << '\n';
		pos.pop();
	}

	// 먹은 사과 제거
	else
	{
		//cout << "Eat Apple" << '\n';
		board[head.first][head.second] = 0;
	}

	//cout << "MOVE ---> Time: " << result << ", Y: " << y << ", X: " << x << ", Head: (" << head.first << ", " << head.second << ")" << ", Cur Dir: (" << currentDir.first << ", " << currentDir.second << ")" << '\n';
	// 방향 설정
	if (!dir.empty() && dir.front().first == result)
	{
		char nextDir = dir.front().second;
		dir.pop();
		//cout << "NOW : " << result << ", Next: " << nextDir << '\n';

		// 오른쪽 90도 회전
		if (nextDir == 'D')
		{
			// 오른
			if (currentDir.first == 0 && currentDir.second == 1)
			{
				// 아래
				currentDir = make_pair(1, 0);
			}

			// 아래
			else if (currentDir.first == 1 && currentDir.second == 0)
			{
				// 왼
				currentDir = make_pair(0, -1);
			}

			// 왼
			else if (currentDir.first == 0 && currentDir.second == -1)
			{
				// 위
				currentDir = make_pair(-1, 0);
			}

			// 위
			else if (currentDir.first == -1 && currentDir.second == 0)
			{
				// 오른
				currentDir = make_pair(0, 1);
			}
		}

		// 왼쪽 90도 회전
		else if (nextDir == 'L')
		{
			// 오른
			if (currentDir.first == 0 && currentDir.second == 1)
			{
				// 위
				currentDir = make_pair(-1, 0);
			}

			// 위
			else if (currentDir.first == -1 && currentDir.second == 0)
			{
				// 왼
				currentDir = make_pair(0, -1);
			}

			// 왼
			else if (currentDir.first == 0 && currentDir.second == -1)
			{
				// 아래
				currentDir = make_pair(1, 0);
			}

			// 아래
			else if (currentDir.first == 1 && currentDir.second == 0)
			{
				// 오른
				currentDir = make_pair(0, 1);
			}
		}
	}

	//cout << "GO ---> Time: " << result << ", Y: " << y << ", X: " << x << ", Head: (" << head.first << ", " << head.second << ")" << ", Cur Dir: (" << currentDir.first << ", " << currentDir.second << ")" << '\n';
	// 이동
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