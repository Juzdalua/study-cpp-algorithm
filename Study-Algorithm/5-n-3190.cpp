#include <bits/stdc++.h>
using namespace std;

/*
	����� ������ ���� ���̰� �þ��.
	���Ǵ� �ڽ��� ���� �ε����� ������ ������

	N * N ���簢�� ����
	������ (0,0) ���̴� 1

	���� �Ʒ��� ���� �̵��Ѵ�.
	1. ���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
	2. ���� ���̳� �ڱ��ڽ��� ���� �ε����� ������ ������.
	3. ���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
	4. ���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�. ��, �����̴� ������ �ʴ´�.

	������ ���ʸ��� �������� ����϶�
	2 �� N �� 100
	0 �� K �� 100
	1 �� L �� 100

	L -> ���� ȸ��, D -> ������ ȸ��
*/

int n, k, l;
int board[104][104];
queue<pair<int, int>> body;
char dir[10'004];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 }; // 0-��, 1-����, 2-�Ʒ�, 3��

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