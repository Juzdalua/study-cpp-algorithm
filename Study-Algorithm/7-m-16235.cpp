#include <bits/stdc++.h>
using namespace std;

/*
	N*N 땅
	(r,c) 1부터 시작
	시작시 양분은 칸마다 5

	M개의 나무 심는다
	1칸에 여러 나무가 심어질 수 있다

	각 칸의 양분만 먹을수있다
	한칸에 여러 나무가 있다면 나이가 어린 나무부터 양분을 먹는다
	자신의 나이만큼 양분을 먹지 못하면 죽는다

	4계절간 아래 반복
	봄- 자신의 나이만큼 양분을 먹고 나이가 1 증가.
	여름- 봄에 죽은 나무가 양분으로 변한다. 죽은 나무마다 나이/2 값이 칸에 양분으로 저장되고 소수점아래는 버린다.
	가을- 나무가 번식. 나이가 5의 배수. 인접한 8칸에 나이 1인 나무가 생긴다. 땅을 벗어나면 안생긴다
	겨울- 각 칸에 양분을 추가한다.
	K년이 지난 후 상도의 땅에 살아있는 나무의 개수

	땅 - 1 ≤ N ≤ 10
	나무 개수 - 1 ≤ M ≤ N^2
	K년 - 1 ≤ K ≤ 1,000
	양분 - 1 ≤ A[r][c] ≤ 100
	1 ≤ 입력으로 주어지는 나무의 나이 ≤ 10
*/

struct namu
{
	int age, x, y;
	bool alive, check;
};
int n, m, k;
int board[14][14];
int yangbun[14][14];
vector<namu> v;
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

bool Compare(namu& a, namu& b)
{
	if (a.age != b.age)
		return a.age < b.age;
	else if (a.y != b.y)
		return a.y < b.y;
	else
		return a.x < b.x;
}

void PrintBoard()
{
	//cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}
void PrintNamu()
{
	for (namu& na : v)
	{
		cout << "Age: " << na.age << ", (" << na.y << ", " << na.x << "), Alive: " << na.alive << ", Check: " << na.check << '\n';
	}
}

void Solution()
{
	//PrintBoard();
	//PrintNamu();

	while (k--)
	{
		//cout << '\n' << "Start -> " << k << '\n';
		sort(v.begin(), v.end(), Compare);

		// 봄
		for (namu& na : v)
		{
			if (!na.alive)
				continue;

			//cout << "(" << na.y << ", " << na.x << "), 양분-> " << board[na.y][na.x] << ", age: " << na.age << '\n';
			if (board[na.y][na.x] < na.age)
			{
				board[na.y][na.x] = 0;
				na.alive = false;
			}
			else
			{
				board[na.y][na.x] -= na.age;
				na.age++;
			}
		}

		/*cout << "봄" << '\n';
		PrintBoard();
		PrintNamu();*/

		// 여름
		for (namu& na : v)
		{
			if (na.alive)
				continue;
			if (na.check)
				continue;

			na.check = true;
			board[na.y][na.x] += na.age / 2;
		}

		/*cout << "여름" << '\n';
		PrintBoard();
		PrintNamu();*/

		// 가을
		int vSize = v.size();
		for (int i = 0; i < vSize; i++)
		{
			if (!v[i].alive)
				continue;

			if (v[i].age % 5 == 0)
			{
				for (int j = 0; j < 8; j++)
				{
					int ny = v[i].y + dy[j];
					int nx = v[i].x + dx[j];
					//cout << "Y: "<< v[i].y << ", X: " << v[i].x << ", dy[i]: "<<dy[i]<<", dx[i]"<<dx[i] << ", (" << ny << ", " << nx << ")" << '\n';
					if (ny >= n || nx >= n || ny < 0 || nx < 0)
						continue;

					int age = 1;
					int y = ny;
					int x = nx;
					bool alive = true;
					bool check = false;

					namu naa;
					naa.age = age;
					naa.x = x;
					naa.y = y;
					naa.alive = alive;
					naa.check = check;
					v.push_back(naa);
				}
			}
		}
		/*cout << "가을" << '\n';
		PrintBoard();
		PrintNamu();*/

		// 겨울
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				board[i][j] += yangbun[i][j];
			}
		}

		/*cout << "겨울" << '\n';
		PrintBoard();
		PrintNamu();*/
	}

	long long sum = 0;
	for (namu& na : v)
	{
		//cout << "Age: " << na.age << ", (" << na.y << ", " << na.x << "), Alive: " << na.alive << ", Check: " << na.check << '\n';
		if (!na.alive)
			continue;
		sum++;
	}
	cout << sum << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> yangbun[i][j];
			board[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		int age = in3;
		int y = in1 - 1;
		int x = in2 - 1;
		bool alive = true;
		bool check = false;

		namu na;
		na.age = age;
		na.x = x;
		na.y = y;
		na.alive = alive;
		na.check = check;

		v.push_back(na);
	}

	Solution();

	return 0;
}