#include <bits/stdc++.h>
using namespace std;

/*
	�������� 1,2,...,N ��
	i��° ������ �������� i
	���� ������ ���� ����

	�� ���ǿ��� M���� ������ �����ִ�
	i��° ���ǿ� ���� j��° ���� (i,j)

	(i, 1)�� (i, 2), (i, M)�� �����ϴ�.
	(i, M)�� (i, M-1), (i, 1)�� �����ϴ�.
	(i, j)�� (i, j-1), (i, j+1)�� �����ϴ�. (2 �� j �� M-1)
	(1, j)�� (2, j)�� �����ϴ�.
	(N, j)�� (N-1, j)�� �����ϴ�.
	(i, j)�� (i-1, j), (i+1, j)�� �����ϴ�. (2 �� i �� N-1)

	������ ȸ���� ���������� ����ȴ�.
	ȸ���� ��ġ�� ���� �������� �Ѵ�.
	ȸ�� �� ���� ��ġ�� ���� �����ؾ��Ѵ�.

	��ȣ�� x�� ����� ������ d�������� kĭ ȸ����Ų��. -> d=0 �ð� ����, d=1 �ݽð� ����.
	���ǿ� ���� ���� ������, �����ϸ鼭 ���� ���� ���� ��� ã�´�.
	�׷��� ���� �ִ� ��쿡�� ���ǿ��� �����ϸ鼭 ���� ���� ��� �����.
	���� ��쿡�� ���ǿ� ���� ���� ����� ���ϰ�, ��պ��� ū ������ 1�� ����, ���� ������ 1�� ���Ѵ�.

	2 �� N, M �� 50
	1 �� T �� 50
	1 �� ���ǿ� ���� �� �� 1,000
	2 �� xi �� N
	0 �� di �� 1
	1 �� ki < M
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

		// ȸ��
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

		// ���� ���� Ȯ��
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (v[i][j] == 0)
					continue;

				// ���� ���� ó��
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

				// �ٸ� ���� ó��
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

	// �ݽð�
	rotate(temp1.begin(), temp1.begin() + 3, temp1.end());
	for (int& t1 : temp1)
		cout << t1 << " ";
	cout << '\n';

	// �ð�
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