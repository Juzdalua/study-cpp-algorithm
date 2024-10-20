#include <bits/stdc++.h>
using namespace std;

/*
	N*M ����
	���� ��ǥ (r,c)

	�ֻ���
	���� 1
	������ �ٶ󺸴� ���� 3
	(x,y)�� �����ִ�
	  2
	4 1 3
	  5
	  6

	���� ó�� �ֻ��� ��� ���� 0�̴�
	���� �� ĭ�� ������ �����ִ�
	�̵��� ĭ�� 0�̸�, �ֻ��� �ٴڸ��� ���ڰ� ĭ�� ����ȴ�
	�̵��� ĭ�� 0�� �ƴϸ�, ĭ�� 0�� �ǰ� ĭ�� ���ڴ� �ֻ��� �ٴڸ鿡 ����ȴ�.

	�ֻ����� �̵��Ҷ����� ��ܿ� �����ִ� ���� ���϶�
	�ٱ����� �̵��� �����ϰ� ��µ� �����ʴ´�.
	 ������ �� ĭ�� ���� �ִ� ���� 10 �̸��� �ڿ��� �Ǵ� 0�̴�.

	1 �� N, M �� 20
	0 �� x �� N-1, 0 �� y �� M-1
	1 �� K �� 1,000
	������ 1, ������ 2, ������ 3, ������ 4

	���� - �ٴ�
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

	// �ֻ��� ������Ʈ 
	int temp = 0;
	if (dir == 0) // ��
	{
		rotate(row.begin(), row.begin() + 2, row.end());
		int temp = row[0];
		row[0] = column[3];
		column[3] = temp;
		column[1] = row[1];
	}
	else if (dir == 1) // ��
	{
		rotate(row.begin(), row.begin() + 1, row.end());
		int temp = row[2];
		row[2] = column[3];
		column[3] = temp;
		column[1] = row[1];
	}
	else if (dir == 2) // ��
	{
		rotate(column.begin(), column.begin() + 1, column.end());
		row[1] = column[1];
	}
	else if (dir == 3) // ��
	{
		rotate(column.begin(), column.begin() + 3, column.end());
		row[1] = column[1];
	}

	// ĭ�� ���ڿ� ���� ������Ʈ
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