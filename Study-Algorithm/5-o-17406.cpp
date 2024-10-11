#include <bits/stdc++.h>
using namespace std;

/*
	N*M 배열A
	A의 갑은 각 행의 모든 수의 합의 최소값

	배열의 칸 (r, c)는 r행 c열
	회전연산  (r, c, s)
	가장 왼쪽 윗 칸이 (r-s, c-s)
	가장 오른쪽 아랫 칸이 (r+s, c+s)
	시계방향 90도 회전

	 (3, 4, 2) => (1,2), (5,6) -> (0,1), (4,5)
	 (1,2) (1,6) -> (0,1) (0,5)
	 (5,2) (5,6) -> (4,1) (4,5)


	 3 ≤ N, M ≤ 50
	1 ≤ K ≤ 6
	1 ≤ A[i][j] ≤ 100
	1 ≤ s
	1 ≤ r-s < r < r+s ≤ N
	1 ≤ c-s < c < c+s ≤ M

	A의 최소값을 구하라.
	배열 A와 사용 가능한 회전 연산이 주어졌을 때, 배열 A의 값의 최솟값을 구해보자.
	회전 연산은 모두 한 번씩 사용해야 하며, 순서는 임의로 정해도 된다.
*/

int n, m, k;
int board[54][54];
int visited[10];
int minResult = INT_MAX;
vector<tuple<int, int, int>> rotates;
vector<int> rotateIdx;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

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
	cout << '\n';
}

void CalcA(int arr[54][54])
{
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += arr[i][j];
		}
		minResult = min(minResult, sum);
	}
	//Print();
}

void RotateRight(int startX, int startY, int endX, int endY, int arr[54][54])
{
	if (startX == endX)
	{
		return;
	}

	int nx = startX;
	int ny = startY;
	int dir = 0;
	vector<int> v;
	while(true)
	{
		//cout << "dir: " << dir << ", ny: " << ny << ", nx: " << nx << '\n';
		if (nx == startX && ny == startY && v.size() != 0)
			break;

		v.push_back(arr[nx][ny]);

		if (nx == startX && ny == endY)
			dir++;

		if (nx == endX && ny == endY)
			dir++;

		if (nx == endX && ny == startY)
			dir++;

		ny += dx[dir];
		nx += dy[dir];
	}

	if (v.size() > 0)
		rotate(v.begin(), v.end()-1, v.end());

	nx = startX;
	ny = startY;
	dir = 0;
	for(int i=0; i<v.size(); i++)
	{
		//cout << "i: " << i << ", ny: " << ny << ", nx: " << nx << '\n';
		arr[nx][ny] = v[i];

		if (nx == startX && ny == endY)	
			dir++;

		if (nx == endX && ny == endY)
			dir++;

		if (nx == endX && ny == startY)
			dir++;

		ny += dx[dir];
		nx += dy[dir];
	}

	RotateRight(startX + 1, startY + 1, endX - 1, endY - 1, arr);
}

void Solution()
{
	//회전 순서 순열
	do
	{
		int temp[54][54] = { 0 };
		memcpy(temp, board, sizeof(board));

		for (int i = 0; i < rotateIdx.size(); i++)
		{
			int r = get<0>(rotates[rotateIdx[i]]);
			int c = get<1>(rotates[rotateIdx[i]]);
			int s = get<2>(rotates[rotateIdx[i]]);

			int startX = r - s - 1;
			int startY = c - s - 1;
			int endX = r + s - 1;
			int endY = c + s - 1;

			RotateRight(startX, startY, endX, endY, temp);
		}

		CalcA(temp);
	} while (next_permutation(rotateIdx.begin(), rotateIdx.end()));
	cout << minResult << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int input1, input2, input3;
		cin >> input1 >> input2 >> input3;
		rotates.push_back({ input1, input2, input3 });
		rotateIdx.push_back(i);
	}

	Solution();

	return 0;
}