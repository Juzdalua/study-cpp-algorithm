#include <bits/stdc++.h>
using namespace std;

/*
	N * N
	�� ĭ���� ����
	���̶� �� �� �Ǵ� �� �� ���θ� ��Ÿ����

	�濡 ���� ���ĭ�� ���̰� ���ƾ��Ѵ�.
	���θ� ���Ƽ� ���� ���� �� �ִ�.
	���� ���̴� 1, ���̴� L
	���� ������ ����
		���δ� ���� ĭ�� ������, L���� ���ӵ� ĭ�� ������ �ٴ��� ��� ���ؾ� �Ѵ�.
		���� ĭ�� ���� ĭ�� ���� ���̴� 1�̾�� �Ѵ�.
		���θ� ���� ���� ĭ�� ���̴� ��� ���ƾ� �ϰ�, L���� ĭ�� ���ӵǾ� �־�� �Ѵ�.

	�Ʒ��� ���� ��쿡�� ���θ� ���� �� ����.
		���θ� ���� ���� �� ���θ� ���� ���
		���� ĭ�� ���� ĭ�� ���� ���̰� 1�� �ƴ� ���
		���� ������ ĭ�� ���̰� ��� ���� �ʰų�, L���� ���ӵ��� ���� ���
		���θ� ���ٰ� ������ ����� ���

	������ �� �ִ� ���� ������ ���ϴ� ���α׷�
	2 �� N �� 100
	1 �� L �� N
	�� ĭ�� ���̴� 10���� �۰ų� ���� �ڿ���
*/

int n, l;
int board[104][104];
int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };
int result;

void CheckRow(int y)
{
	int cnt = 1;
	int start = board[y][0];
	int num = start;
	//cout << '\n' << "Check Row -> Y: " << y << ", start: " << start << '\n';

	for (int i = 1; i < n; i++)
	{
		int now = board[y][i];
		//cout << "i: " << i << ", num: " << num << ", now: " << now << '\n';
		if (now == num)
		{
			cnt++;
		}
		else
		{
			if (abs(now - num) > 1)
				break;
			if (now > num && cnt < l)
				break;
			if (now < num && n - i < l)
				break;

			if (now > num)
			{
				cnt = 1;
			}
			if (now < num)
			{
				cnt = 0;
				for (int j = i; j < i + l; j++)
				{
					if (board[y][j] == now)
					{
						cnt++;
						//cout << "j: " << j << ", cnt: " << cnt << ", num: " << now << '\n';
					}
					else
					{
						break;
					}
				}
				if (cnt != l)
					break;

				cnt = 0;
				i += l - 1;
			}
			num = now;
		}

		if (i >= n - 1)
		{
			//cout << "Plus! -> y: " << y << ", start -> " << board[y][0] << '\n';
			result++;
		}
	}
}

void CheckColumn(int x)
{
	int cnt = 1;
	int start = board[0][x];
	int num = start;

	//cout << '\n' << "Check Column -> X: " << x << ", start: " << start << '\n';

	for (int i = 1; i < n; i++)
	{
		//cout << "i: " << i << ", now: " << board[i][x] << '\n';
		int now = board[i][x];
		if (now == num)
		{
			cnt++;
		}
		else
		{
			if (abs(now - num) > 1)
				break;
			if (now > num && cnt < l)
				break;
			if (now < num && n - i < l)
				break;

			if (now > num)
			{
				cnt = 1;
			}
			if (now < num)
			{
				cnt = 0;
				for (int j = i; j < i + l; j++)
				{
					if (board[j][x] == now)
					{
						cnt++;
						//cout << "j: " << j << ", cnt: " << cnt << ", num: " << now << '\n';
					}
					else
					{
						break;
					}
				}
				if (cnt != l)
					break;

				cnt = 0;
				i += l - 1;
			}
			num = now;
		}

		if (i >= n - 1)
		{
			result++;
			//cout << "Plus! -> x: " << x << ", start -> " << board[0][x] << '\n';
		}
	}
}

void Solution()
{
	// �� Ž��
	for (int i = 0; i < n; i++)
	{
		CheckRow(i);
	}

	// �� Ž��
	for (int i = 0; i < n; i++)
	{
		CheckColumn(i);
	}

	cout << result << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	Solution();

	return 0;
}