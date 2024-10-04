#include <bits/stdc++.h>
using namespace std;

/*
	바이러스 확산을 막기 위해 벽을 세운다
	연구소 N * M 직사각형
	각 칸은 빈칸 혹은 벽으로 이루어진다.
	바이러스는 상하좌우 인접한 칸으로 퍼져나간다.

	새로 세울 수 있는 벽의 수는 3개
	꼭 3개를 세워야한다.

	0-빈칸, 1-벽, 2-바이러스
	(3 ≤ N, M ≤ 8)

	벽을 세운 뒤 바이러스가 퍼질 수 없는 영역을 안전영역

	안전영역 크기의 최댓값을 구하라


	0 0 0 0 0 0
	1 0 0 0 0 2
	1 1 1 0 0 2
	0 0 0 0 0 2

	0 0 0 0 1 2
	1 0 0 1 2 2
	1 1 1 2 2 2
	0 0 0 1 2 2

*/

int n, m;
int board[10][10];
int wallCount = 0;
vector<pair<int, int>> emptyArea;
vector<pair<int, int>> virusArea;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int visited[10][10];
int maxResult = -1;

void Print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
	cout << "\n";
}

void CheckSafeArea()
{
	int check = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
				check++;
		}
	}

	maxResult = max(check, maxResult);
}

void DFS(int y, int x)
{
	//cout << "DFS -> (" << y << ", " << x << ")" << '\n';
	if (visited[y][x] == 0)
	{
		visited[y][x] = 1;
		board[y][x] = 2;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || nx >= m || ny < 0 || nx < 0)
			continue;
		if (board[ny][nx] != 0)
			continue;
		if (visited[ny][nx] != 0)
			continue;

		DFS(ny, nx);
	}
}

void SpreadVirus()
{
	for (auto& va : virusArea)
	{
		//cout << "Virus -> (" << va.first << ", " << va.second << ")" << '\n';
		DFS(va.first, va.second);
	}

	//Print();
}

void ResetVirus()
{
	for (auto& ea : emptyArea)
	{
		board[ea.first][ea.second] = 0;
	}
	memset(visited, 0, sizeof(visited));
}

void Combi(int start, vector<pair<int, int>>& v)
{
	if (v.size() == 3)
	{
		for (auto& vv : v)
		{
			board[vv.first][vv.second] = 1;
		}
		
		SpreadVirus();
		CheckSafeArea();
		ResetVirus();

		for (auto& vv : v)
		{
			board[vv.first][vv.second] = 0;
		}
		return;
	}

	for (int i = start + 1; i < emptyArea.size(); i++)
	{
		v.push_back(emptyArea[i]);
		Combi(i, v);
		v.pop_back();
	}
}

void Solution()
{
	// 0에서 3개 뽑아서 벽 세우기
	// 바이러스 이동시키기
	// 남은 0 중 최대값 찾기

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				emptyArea.push_back(make_pair(i, j));
			}
			else if (board[i][j] == 2)
			{
				virusArea.push_back(make_pair(i, j));
			}
		}
	}

	vector<pair<int, int>> v;
	Combi(-1, v);

	cout << maxResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(board, -1, sizeof(board));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	Solution();

	return 0;
}