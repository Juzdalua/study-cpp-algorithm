#include <bits/stdc++.h>
using namespace std;

/*
	반지름이 1,2,...,N 원
	i번째 원판의 반지름은 i
	작은 원판이 제일 위에

	각 원판에는 M개의 정수가 적혀있다
	i번째 원판에 적힌 j번째 수는 (i,j)

	(i, 1)은 (i, 2), (i, M)과 인접하다.
	(i, M)은 (i, M-1), (i, 1)과 인접하다.
	(i, j)는 (i, j-1), (i, j+1)과 인접하다. (2 ≤ j ≤ M-1)
	(1, j)는 (2, j)와 인접하다.
	(N, j)는 (N-1, j)와 인접하다.
	(i, j)는 (i-1, j), (i+1, j)와 인접하다. (2 ≤ i ≤ N-1)

	원판의 회전은 독립적으로 수행된다.
	회전은 위치한 수를 기준으로 한다.
	회전 후 수의 위치는 전과 동일해아한다.

	번호가 x의 배수인 원판을 d방향으로 k칸 회전시킨다. -> d=0 시계 방향, d=1 반시계 방향.
	원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
	그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
	없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.

	2 ≤ N, M ≤ 50
	1 ≤ T ≤ 50
	1 ≤ 원판에 적힌 수 ≤ 1,000
	2 ≤ xi ≤ N
	0 ≤ di ≤ 1
	1 ≤ ki < M
*/

int n, m, t;
vector<vector<int>> v;
vector<tuple<int, int, int>> xdk;
int result;

void Sum()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] != 0)
				result += v[i][j];
		}
	}
}

void Print()
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << '\n';
	}
}

void RotatePan()
{
	for (int i = 0; i < xdk.size(); i++)
	{
		int x = get<0>(xdk[i]);
		int d = get<1>(xdk[i]);
		int k = get<2>(xdk[i]);

		// 회전
		for (int j = 1; j < v.size(); j++)
		{
			int num = x * j - 1;
			if (num >= v.size())
				break;

			auto next = d == 0 ? v[num].end() - k : v[num].begin() + k;
			rotate(v[num].begin(), next, v[num].end());
		}
		//Print();

		vector<vector<int>> temp = v;
		bool flag = true;

		// 인접 숫자 확인
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (v[i][j] == 0)
					continue;

				// 같은 원판 처리
				if ((j == 0 || j == m - 1) && v[i][0] == v[i][m - 1])
				{
					temp[i][0] = 0;
					temp[i][m - 1] = 0;
					flag = false;
				}
				else if (j != 0 && j != m - 1)
				{
					if (v[i][j] == v[i][j - 1])
					{
						temp[i][j] = 0;
						temp[i][j - 1] = 0;
						flag = false;
					}
					if (v[i][j] == v[i][j + 1])
					{
						temp[i][j] = 0;
						temp[i][j + 1] = 0;
						flag = false;
					}
				}

				// 다른 원판 처리
				if (i == 0 && v[0][j] == v[1][j])
				{
					temp[0][j] = 0;
					temp[1][j] = 0;
					flag = false;
				}
				else if (i == n - 1 && v[n - 1][j] == v[n - 2][j])
				{
					temp[n - 1][j] = 0;
					temp[n - 2][j] = 0;
					flag = false;
				}
				else if (i != 0 && i != n - 1)
				{
					if (v[i][j] == v[i - 1][j])
					{
						temp[i][j] = 0;
						temp[i - 1][j] = 0;
						flag = false;
					}
					if (v[i][j] == v[i + 1][j])
					{
						temp[i][j] = 0;
						temp[i + 1][j] = 0;
						flag = false;
					}
				}
			}
		}

		// v = temp
		v = temp;
		//Print();

		if (flag)
		{
			int cnt = 0;
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (v[i][j] != 0)
					{
						cnt++;
						sum += v[i][j];
					}
				}
			}
			float avg = static_cast<float>(sum) / static_cast<float>(cnt);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (v[i][j] != 0)
					{
						if (static_cast<float>(v[i][j]) > avg)
							v[i][j] -= 1;
						else if (static_cast<float>(v[i][j]) < avg)
							v[i][j] += 1;
					}
				}
			}
		}
		//Print();
	}
}

void Solution()
{
	RotatePan();
	Sum();
	cout << result << '\n';
}

void Test()
{
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> temp1 = vec;
	vector<int> temp2 = vec;

	for (int& tt : vec)
		cout << tt << " ";
	cout << '\n';

	// 반시계
	rotate(temp1.begin(), temp1.begin() + 3, temp1.end());
	for (int& t1 : temp1)
		cout << t1 << " ";
	cout << '\n';

	// 시계
	rotate(temp2.begin(), temp2.end() - 3, temp2.end());
	for (int& t2 : temp2)
		cout << t2 << " ";
	cout << '\n';

	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//Test();

	cin >> n >> m >> t;

	for (int i = 0; i < n; i++)
	{
		vector<int> vv;
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
			vv.push_back(input);
		}
		v.push_back(vv);
	}

	for (int i = 0; i < t; i++)
	{
		int in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		xdk.push_back({ in1,in2,in3 });
	}

	Solution();

	return 0;
}