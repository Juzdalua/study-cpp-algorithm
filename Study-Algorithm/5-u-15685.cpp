#include <bits/stdc++.h>
using namespace std;

/*
	드래곤커브
	1. 시작점
	2. 시작 방향
	3. 세대

	0세대: 길이 1
	1세대: 0세대 끝점을 기준으로 시계방향 90도 회전한 0세대를 이어 붙인것
	2세대: 4
	3세대: 8
	n세대: 2^n

	1 ≤ N ≤ 20
	0 ≤ x ≤ 100,
	0 ≤ y ≤ 100
	0 ≤ d ≤ 3,
	0 ≤ g ≤ 10

	크기가 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수를 출력
*/

struct dragon
{
	/*
		시작점(x, y)
		d: 시작 방향
		g: 세대

		0: x좌표가 증가하는 방향 (→)
		1: y좌표가 감소하는 방향 (↑)
		2: x좌표가 감소하는 방향 (←)
		3: y좌표가 증가하는 방향 (↓)
	*/
	int x, y, d, g;
};

int n;
dragon arr[24];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int board[104][104];
int visited[104][104];
int cnt;

vector<int> MakeDir(int gen, int dir)
{
	vector<int> dirs;
	dirs.push_back(dir);

	if (gen > 0)
		dirs.push_back((dir + 1) % 4);

	for (int i = 2; i <= gen; i++)
	{
		vector<int> temp = dirs;
		reverse(dirs.begin(), dirs.end());

		for (int j = 0; j < dirs.size(); j++)
		{
			temp.push_back((dirs[j] + 1) % 4);
		}
		dirs = temp;
	}

	return dirs;
}

void MakeDragon()
{
	for (int i = 0; i < n; i++)
	{
		int y = arr[i].x;
		int x = arr[i].y;
		int dir = arr[i].d;
		int gen = arr[i].g;

		visited[y][x] = 1;
		//cout << "(" << y << ", " << x << ")" << '\n';
		//cout << '\n';

		vector<int> td = MakeDir(gen, dir);
		for (int j = 0; j < td.size(); j++)
		{
			dir = td[j];
			int ny = y + dx[dir];
			int nx = x + dy[dir];

			if (ny > 100 || nx > 100 || ny < 0 || nx < 0)
				continue;

			visited[ny][nx] = 1;
			//cout << "(" << ny << ", " << nx << ")" << '\n';
			y = ny;
			x = nx;
		}
		//cout << '\n';
	}
}

void Solution()
{
	MakeDragon();

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100;j++)
		{
			if (visited[i][j] == 1 && visited[i + 1][j] == 1 && visited[i][j + 1] == 1 && visited[i + 1][j + 1] == 1)
			{
				cnt++;
				//cout << "i: " << i << ", j: " << j << '\n';
			}
		}
	}
	cout << cnt << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int in1, in2, in3, in4;
		cin >> in1 >> in2 >> in3 >> in4;
		arr[i].x = in1;
		arr[i].y = in2;
		arr[i].d = in3;
		arr[i].g = in4;
	}

	Solution();

	return 0;
}