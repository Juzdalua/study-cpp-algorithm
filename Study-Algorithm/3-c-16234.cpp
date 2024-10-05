#include <bits/stdc++.h>
using namespace std;

/*
	N * N 땅
	모든 나라의 크기는 1 * 1
	모든 국경선은 정사각형
	A[r][c] = r행 c열에 살고있는 사람의 수

	인구이동
	1. 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
	2. 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
	3. 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
	4. 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
	5. 연합을 해체하고, 모든 국경선을 닫는다.

	인구이동이 몇일 발생하는지 출력
	1 ≤ N ≤ 50,
	1 ≤ L ≤ R ≤ 100
	0 ≤ A[r][c] ≤ 100
*/

int n, l, r;
int board[54][54];
int visited[54][54];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
map<pair<int, int>, tuple<int, int, vector<pair<int, int>>>> bm; // bm[시작x,시작y] = (sum, count, [(현재x,현재y), ...])

void PrintVisited()
{
	cout << "\n" << "Print Visited" << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

void PrintBoard()
{
	cout << "\n" << "Print Board" << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

bool CheckDone()
{
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (!flag)
			break;
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				flag = false;
				break;
			}
		}
	}
	return flag;
}

void DFS(int y, int x, int startX, int startY)
{
	//cout << "DFS -> (" << y << ", " << x << "), START -> (" << startX << ", " << startY << ")" << '\n';
	if (visited[y][x] == 0)
		visited[y][x] = 1;

	get<0>(bm[{startX, startY}]) += board[y][x];
	get<1>(bm[{startX, startY}])++;
	get<2>(bm[{startX, startY}]).push_back({ y, x });

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= n || ny < 0 || nx < 0)
			continue;
		if (visited[ny][nx] != 0)
			continue;
		if (abs(board[y][x] - board[ny][nx]) >= l && abs(board[y][x] - board[ny][nx]) <= r)
			DFS(ny, nx, startX, startY);
	}
}

void Solution()
{
	int resultCount = 0;
	while (true)
	{
		memset(visited, 0, sizeof(visited));
		bm.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				DFS(i, j, i, j);
			}
		}

		int breakCount = 0;
		bool flag = false;
		for (auto& m : bm)
		{
			//cout << "SUM: " << get<0>(m.second) << ", Count: " << get<1>(m.second) << '\n';
			if (get<1>(m.second) == 1)
				breakCount++;

			if (breakCount == bm.size())
			{
				//PrintBoard();
				cout << resultCount << '\n';
				exit(0);
			}

			if (get<1>(m.second) > 1)
			{
				int avg = get<0>(m.second) / get<1>(m.second);
				for (auto& v : get<2>(m.second))
				{
					flag = true;
					board[v.first][v.second] = avg;
				}
			}
		}
		if (flag)
			resultCount++;

		/*if (resultCount == 1)
			break;*/
	}

	PrintBoard();
	//PrintVisited();

	cout << resultCount << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	Solution();

	return 0;
}