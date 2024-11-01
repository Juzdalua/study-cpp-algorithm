#include <bits/stdc++.h>
using namespace std;

/*
	N*N 크기
	물고기 M마리, 상어 1마리
	한칸에 물고기 최대 1마리
	물고기와 상어의 크기는 자연수

	처음 아기상어 크기 2
	1초에 상하좌우 1칸 이동
	자신보다 크기가 큰 물고기 칸은 갈 수 없다.
	작은 물고기가 있는곳은 가고 먹는다
	크기가 같으면 먹을수없고 지나간다

	더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
	먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
	먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
		거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
		거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

	이동은 1초 걸린다
	이동과 동시에 먹는다
	자신의 크기와 같은수의 물고기를 먹으면 크기가 1 증가한다
	 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램

	 2 ≤ N ≤ 20
	 0: 빈 칸
	1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
	9: 아기 상어의 위치
*/

int n, m;
pair<int, int> sharkInfo = { 2, 0 }; // size, eat
pair<int, int> shark; // y, x
int board[24][24];
int result;
vector<pair<int, int>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[24][24];

void Print()
{
	cout << "Fish Size: " << m << '\n';
}

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
	cout << '\n';
}

void PrintVisit()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

bool Compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

pair<int, int> CheckDistance()
{
	map<int, vector<pair<int, int>>> temp;
	for (int i = 0; i < m; i++)
	{
		// 물고기 크기 확인
		if (board[v[i].first][v[i].second] >= sharkInfo.first)
			continue;

		//cout << "Start fish idx -> " << i << '\n';

		memset(visited, 0, sizeof(visited));

		// 최단경로 탐색
		queue<pair<int, int>> q;
		q.push({ shark.first, shark.second });
		while (!q.empty())
		{
			int y = -1;
			int x = -1;
			tie(y, x) = q.front();
			q.pop();

			if (v[i].first == y && v[i].second == x)
			{
				temp[visited[y][x]].push_back({ v[i].first, v[i].second });
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= n || nx >= n || ny < 0 || nx < 0)
					continue;
				if (board[ny][nx] > sharkInfo.first)
					continue;
				if (visited[ny][nx] != 0)
					continue;

				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny,nx });
			}
		}
		//PrintVisit();
	}
	//cout << "TempSize: " << temp.size() << "\n";

	int idx = -1;
	for (auto& t : temp)
	{
		sort(t.second.begin(), t.second.end(), Compare);
		int y = t.second[0].first;
		int x = t.second[0].second;

		pair<int, int> findIdx = { y,x };

		auto it = find(v.begin(), v.end(), findIdx);
		idx = distance(v.begin(), it);
		return { idx, t.first };
	}
	return { idx, 0 };
}

void Solution()
{
	//Print();
	if (m == 0)
	{
		cout << 0 << '\n';
		exit(0);
	}

	while (true)
	{
		if (m == 0)
		{
			cout << result << '\n';
			exit(0);
		}

		// 물고기 제거
		int distance = 0;
		int fishIdx = -1;
		tie(fishIdx, distance) = CheckDistance();
		if (fishIdx == -1)
		{
			cout << result << '\n';
			exit(0);
		}

		int fishY = -1;
		int fishX = -1;
		tie(fishY, fishX) = v[fishIdx];
		v.erase(v.begin() + fishIdx);
		m--;

		// 상어 위치 업데이트
		int sharkY = shark.first;
		int sharkX = shark.second;
		//cout << "Shark Size: " << sharkInfo.first << ", Fish Idx: " << fishIdx << ", (" << fishY << ", " << fishX << "), FishSize: " << board[fishY][fishX] << ", Distance: " << distance << '\n';

		result += distance;
		shark.first = fishY;
		shark.second = fishX;
		board[sharkY][sharkX] = 0;
		board[fishY][fishX] = 9;

		// 상어 크기 증가
		sharkInfo.second++;
		if (sharkInfo.first == sharkInfo.second)
		{
			sharkInfo.first++;
			sharkInfo.second = 0;
		}
		//PrintBoard();
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
				shark = { i,j };
			else if (board[i][j] != 0)
			{
				m++;
				v.push_back({ i,j });
			}
		}
	}

	Solution();

	return 0;
}