#include <bits/stdc++.h>
using namespace std;

/*
	N*N ��
	(r,c) 1���� ����
	���۽� ����� ĭ���� 5

	M���� ���� �ɴ´�
	1ĭ�� ���� ������ �ɾ��� �� �ִ�

	�� ĭ�� ��и� �������ִ�
	��ĭ�� ���� ������ �ִٸ� ���̰� � �������� ����� �Դ´�
	�ڽ��� ���̸�ŭ ����� ���� ���ϸ� �״´�

	4������ �Ʒ� �ݺ�
	��- �ڽ��� ���̸�ŭ ����� �԰� ���̰� 1 ����.
	����- ���� ���� ������ ������� ���Ѵ�. ���� �������� ����/2 ���� ĭ�� ������� ����ǰ� �Ҽ����Ʒ��� ������.
	����- ������ ����. ���̰� 5�� ���. ������ 8ĭ�� ���� 1�� ������ �����. ���� ����� �Ȼ����
	�ܿ�- �� ĭ�� ����� �߰��Ѵ�.
	K���� ���� �� ���� ���� ����ִ� ������ ����

	�� - 1 �� N �� 10
	���� ���� - 1 �� M �� N^2
	K�� - 1 �� K �� 1,000
	��� - 1 �� A[r][c] �� 100
	1 �� �Է����� �־����� ������ ���� �� 10
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

		// ��
		for (namu& na : v)
		{
			if (!na.alive)
				continue;

			//cout << "(" << na.y << ", " << na.x << "), ���-> " << board[na.y][na.x] << ", age: " << na.age << '\n';
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

		/*cout << "��" << '\n';
		PrintBoard();
		PrintNamu();*/

		// ����
		for (namu& na : v)
		{
			if (na.alive)
				continue;
			if (na.check)
				continue;

			na.check = true;
			board[na.y][na.x] += na.age / 2;
		}

		/*cout << "����" << '\n';
		PrintBoard();
		PrintNamu();*/

		// ����
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
		/*cout << "����" << '\n';
		PrintBoard();
		PrintNamu();*/

		// �ܿ�
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				board[i][j] += yangbun[i][j];
			}
		}

		/*cout << "�ܿ�" << '\n';
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