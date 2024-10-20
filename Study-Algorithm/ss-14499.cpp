#include <bits/stdc++.h>
using namespace std;

/*
	N*M 지도
	지도 좌표 (r,c)

	주사위
	윗면 1
	동쪽을 바라보는 방향 3
	(x,y)에 놓여있다
	  2
	4 1 3
	  5
	  6

	가장 처음 주사위 모든 면은 0이다
	지도 각 칸은 정수가 쓰여있다
	이동한 칸이 0이면, 주사위 바닥면의 숫자가 칸에 복사된다
	이동한 칸이 0이 아니면, 칸은 0이 되고 칸의 숫자는 주사위 바닥면에 복사된다.

	주사위가 이동할때마다 상단에 적혀있는 값을 구하라
	바깥으로 이동은 무시하고 출력도 하지않는다.
	 지도의 각 칸에 쓰여 있는 수는 10 미만의 자연수 또는 0이다.

	1 ≤ N, M ≤ 20
	0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1
	1 ≤ K ≤ 1,000
	동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4

	윗면 - 바닥
	1 - 6
	2 - 5
	3 - 4
	4 - 3
	5 - 2
	6 - 1
*/

int n, m, k;
pair<int, int> location;
int jusawi[6];
int arr[24][24];
vector<int> v;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
vector<int> row(3, 0);
vector<int> column(4, 0);

void PrintJusawi()
{
	cout << "Row" << '\n';
	for (int i = 0; i < 3; i++)
		cout << row[i] << " ";
	cout << '\n';

	cout << "Column" << '\n';
	for (int i = 0; i < 4; i++)
		cout << column[i] << " ";
	cout << '\n';
}

void PrintBoard()
{
	cout << "Board" << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

void DFS(int kIdx, int y, int x)
{
	int dir = v[kIdx] - 1;
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	//cout << '\n' << "Start -> kIdx: " << kIdx << ", (" << y << ", " << x << "), Next -> (" << ny << ", " << nx << ")" << '\n';

	if (ny >= n || nx >= m || ny < 0 || nx < 0)
		return;

	// 주사위 업데이트 
	int temp = 0;
	if (dir == 0) // 동
	{
		rotate(row.begin(), row.begin() + 2, row.end());
		int temp = row[0];
		row[0] = column[3];
		column[3] = temp;
		column[1] = row[1];
	}
	else if (dir == 1) // 서
	{
		rotate(row.begin(), row.begin() + 1, row.end());
		int temp = row[2];
		row[2] = column[3];
		column[3] = temp;
		column[1] = row[1];
	}
	else if (dir == 2) // 북
	{
		rotate(column.begin(), column.begin() + 1, column.end());
		row[1] = column[1];
	}
	else if (dir == 3) // 남
	{
		rotate(column.begin(), column.begin() + 3, column.end());
		row[1] = column[1];
	}

	// 칸의 숫자에 따라 업데이트
	if (arr[ny][nx] == 0)
	{
		arr[ny][nx] = column[3];
	}
	else
	{
		column[3] = arr[ny][nx];
		arr[ny][nx] = 0;
	}
	//PrintJusawi();
	//PrintBoard();

	location = { ny,nx };
	cout << column[1] << '\n';
}

void Solution()
{
	for (int i = 0; i < v.size(); i++)
	{
		DFS(i, location.first, location.second);
	}
}

void Test()
{
	vector<int> a = { 1,2,3,4 };
	rotate(a.begin(), a.begin() + 3, a.end());
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//Test();

	cin >> n >> m >> location.first >> location.second >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		int in;
		cin >> in;
		v.push_back(in);
	}

	Solution();

	return 0;
}