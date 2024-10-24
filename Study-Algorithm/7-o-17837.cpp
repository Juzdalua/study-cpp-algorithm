#include <bits/stdc++.h>
using namespace std;

/*
	N*N 체스판
	말의 개수 K개, 1~K번
	칸은 흰색, 빨간색, 파란색 중 하나
	이동방향 4방향
	말은 겹칠수있다
	말이 이동하면 위에 말도 같이 이동한다.

	턴 1번
	1번부터 K번 순서대로 움직인다
	말이 4개 이상 쌓이면 종료된다

	A번 말이 이동하려는 칸이
	흰색인 경우에는 그 칸으로 이동한다. 이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 A번 말을 올려놓는다.
		A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다.
		예를 들어, A, B, C로 쌓여있고, 이동하려는 칸에 D, E가 있는 경우에는 A번 말이 이동한 후에는 D, E, A, B, C가 된다.
	빨간색인 경우에는 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
		A, B, C가 이동하고, 이동하려는 칸에 말이 없는 경우에는 C, B, A가 된다.
		A, D, F, G가 이동하고, 이동하려는 칸에 말이 E, C, B로 있는 경우에는 E, C, B, G, F, D, A가 된다.
	파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다. 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다.
	체스판을 벗어나는 경우에는 파란색과 같은 경우이다.

	게임이 종료되는 턴의 번호

	0은 흰색, 1은 빨간색, 2는 파란색
	(1,1) 시작
	1234 →, ←, ↑, ↓
	1,000보다 크거나 절대로 게임이 종료되지 않는 경우에는 -1을 출력

	4 ≤ N ≤ 12
	4 ≤ K ≤ 10
*/

struct malstruct
{
	int y, x, dir;
};

int n, k;
int board[16][16];
vector<int> arr[16][16];
malstruct mal[14];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int turn;

void Check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j].size() >= 4)
			{
				cout << turn << '\n';
				exit(0);
			}
		}
	}
}

void Print()
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j].size() == 0)
				cout << board[i][j] << " ";
			else
			{
				cout << "[";
				for (int l = 0; l < arr[i][j].size(); l++)
				{
					if (l == 0)
						cout << arr[i][j][l];
					else
						cout << " " << arr[i][j][l];
				}
				cout << "]";
			}
		}
		cout << '\n';
	}

	cout << '\n';
	for (int i = 0; i < k; i++)
	{
		malstruct m = mal[i];
		cout << "(" << m.y << ", " << m.x << "), dir: " << m.dir << " -> " << i << '\n';
	}
}

void Solution()
{
	while (true)
	{
		turn++;
		if (turn > 1000)
			break;

		//Print();
		for (int i = 0; i < k; i++)
		{
			malstruct& ma = mal[i];
			int ny = ma.y + dy[ma.dir];
			int nx = ma.x + dx[ma.dir];
			int dir = ma.dir;

			//cout << '\n' << "Mal -> " << i << ", (" << ny << ", " << nx << ")" << ", dir: " << dir << " -> " << i << '\n';
			//Print();

			// 파랑, 경계 밖
			if (ny >= n || nx >= n || ny < 0 || nx < 0 || board[ny][nx] == 2)
			{
				if (dir == 0)
					dir = 1;
				else if (dir == 1)
					dir = 0;
				else if (dir == 2)
					dir = 3;
				else if (dir == 3)
					dir = 2;

				ma.dir = dir;
				ny = ma.y + dy[dir];
				nx = ma.x + dx[dir];
				if (ny >= n || nx >= n || ny < 0 || nx < 0 || board[ny][nx] == 2)
					continue;
			}

			vector<int> next;
			vector<int>& curBoard = arr[ma.y][ma.x];
			int size = 0;
			auto it = find(curBoard.begin(), curBoard.end(), i);
			if (it != curBoard.end())
			{
				while (it != curBoard.end())
				{
					next.push_back(*it);
					it++;
					size++;
				}
				while (size--)
				{
					curBoard.pop_back();
				}

				// 빨강
				if (board[ny][nx] == 1)
					reverse(next.begin(), next.end());

				for (int j = 0; j < next.size(); j++)
				{
					arr[ny][nx].push_back(next[j]);

					mal[next[j]].y = ny;
					mal[next[j]].x = nx;
				}

				ma.y = ny;
				ma.x = nx;
			}
			Check();
		}
	}

	if (turn > 1000)
		turn = -1;
	cout << turn << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		int y, x, dir;
		cin >> y >> x >> dir;
		mal[i].y = y - 1;
		mal[i].x = x - 1;
		mal[i].dir = dir - 1;

		arr[y - 1][x - 1].push_back(i);
	}

	Solution();

	return 0;
}