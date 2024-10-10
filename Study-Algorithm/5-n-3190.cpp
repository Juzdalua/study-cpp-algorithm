#include <bits/stdc++.h>
using namespace std;

/*
	사과를 먹으면 뱀의 길이가 늘어난다.
	벽또는 자신의 몸과 부딪히면 게임이 끝난다

	N * N 정사각형 보드
	시작은 (0,0) 길이는 1

	매초 아래와 같이 이동한다.
	1. 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
	2. 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
	3. 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
	4. 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.

	게임이 몇초만에 끝나는지 계산하라
	2 ≤ N ≤ 100
	0 ≤ K ≤ 100
	1 ≤ L ≤ 100

	L -> 왼쪽 회전, D -> 오른쪽 회전
*/

int n, k, l;
int board[104][104];
queue<pair<int, int>> body;
char dir[10'004];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 }; // 0-위, 1-오른, 2-아래, 3왼

void Exit(int count)
{
	cout << count << '\n';
	exit(0);
}

void MoveBody(int y, int x, bool isEat)
{
	body.push({ y,x });
	if (!isEat)
		body.pop();

	/*queue<pair<int, int>> temp = body;
	while (!temp.empty())
	{
		cout << temp.front().first << ", " << temp.front().second << '\n';
		temp.pop();
	}*/
}

void Go(int y, int x, int direction,int count)
{
	if (count > 0)
	{
		bool isEat = board[y][x] == 1 ? true : false;
		MoveBody(y, x, isEat);
		if (isEat)
		{
			board[y][x] = 0;
		}
	}

	int ny = y;
	int nx = x;
	if (dir[count] == 'D')
	{
		switch (direction)
		{
		case 0:
			nx += 1;
			direction = 1;
			break;
		case 1:
			ny += 1;
			direction = 2;
			break;
		case 2:
			nx -= 1;
			direction = 3;
			break;
		case 3:
			ny -= 1;
			direction = 0;
			break;

		default:
			break;
		}
	}
	else if (dir[count] == 'L')
	{
		switch (direction)
		{
		case 0:
			nx -= 1;
			direction = 3;
			break;
		case 1:
			ny -= 1;
			direction = 0;
			break;
		case 2:
			nx += 1;
			direction = 1;
			break;
		case 3:
			ny += 1;
			direction = 2;
			break;

		default:
			break;
		}
	}
	else
	{
		switch (direction)
		{
		case 0:
			ny -= 1;
			break;
		case 1:
			nx += 1;
			break;
		case 2:
			ny += 1;
			break;
		case 3:
			nx -= 1;
			break;

		default:
			break;
		}
	}

	if (ny >= n || nx >= n || ny < 0 || nx < 0)
		Exit(count + 1);

	queue< pair<int, int>> temp = body;
	while (!temp.empty())
	{
		int bodyY, bodyX;
		tie(bodyY, bodyX) = temp.front();
		temp.pop();
		if (bodyY == ny && bodyX == nx)
		{
			//cout << temp.size() << '\n';
			if (!temp.empty())
				Exit(count + 1);
		}
	}

	Go(ny, nx, direction, count + 1);
}

void Solution()
{
	/*cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';*/

	body.push({ 0,0 });
	Go(0, 0, 1, 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int num;
		cin >> num;
		cin >> dir[num];
	}

	Solution();

	return 0;
}