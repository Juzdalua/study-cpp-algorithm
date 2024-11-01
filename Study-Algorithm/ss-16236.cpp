#include <bits/stdc++.h>
using namespace std;

/*
	N*N ũ��
	����� M����, ��� 1����
	��ĭ�� ����� �ִ� 1����
	������ ����� ũ��� �ڿ���

	ó�� �Ʊ��� ũ�� 2
	1�ʿ� �����¿� 1ĭ �̵�
	�ڽź��� ũ�Ⱑ ū ����� ĭ�� �� �� ����.
	���� ����Ⱑ �ִ°��� ���� �Դ´�
	ũ�Ⱑ ������ ���������� ��������

	�� �̻� ���� �� �ִ� ����Ⱑ ������ ���ٸ� �Ʊ� ���� ���� ���� ������ ��û�Ѵ�.
	���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
	���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����.
		�Ÿ��� �Ʊ� �� �ִ� ĭ���� ����Ⱑ �ִ� ĭ���� �̵��� ��, �������ϴ� ĭ�� ������ �ּڰ��̴�.
		�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����, �׷��� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.

	�̵��� 1�� �ɸ���
	�̵��� ���ÿ� �Դ´�
	�ڽ��� ũ��� �������� ����⸦ ������ ũ�Ⱑ 1 �����Ѵ�
	 �Ʊ� �� �� �� ���� ���� ���� ������ ��û���� �ʰ� ����⸦ ��Ƹ��� �� �ִ��� ���ϴ� ���α׷�

	 2 �� N �� 20
	 0: �� ĭ
	1, 2, 3, 4, 5, 6: ĭ�� �ִ� ������� ũ��
	9: �Ʊ� ����� ��ġ
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
		// ����� ũ�� Ȯ��
		if (board[v[i].first][v[i].second] >= sharkInfo.first)
			continue;

		//cout << "Start fish idx -> " << i << '\n';

		memset(visited, 0, sizeof(visited));

		// �ִܰ�� Ž��
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

		// ����� ����
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

		// ��� ��ġ ������Ʈ
		int sharkY = shark.first;
		int sharkX = shark.second;
		//cout << "Shark Size: " << sharkInfo.first << ", Fish Idx: " << fishIdx << ", (" << fishY << ", " << fishX << "), FishSize: " << board[fishY][fishX] << ", Distance: " << distance << '\n';

		result += distance;
		shark.first = fishY;
		shark.second = fishX;
		board[sharkY][sharkX] = 0;
		board[fishY][fishX] = 9;

		// ��� ũ�� ����
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