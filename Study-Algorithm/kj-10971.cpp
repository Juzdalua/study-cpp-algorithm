#include <bits/stdc++.h>
using namespace std;

/*
	1~N�� ���ð� �ִ�.
	���� �������� �������� �ִ�.

	�� ���ÿ��� ����� N���� ���ø� ��� ��ġ��
	�ٽ� ������ ���÷� ���ƿ´�.

	�� �� ���� ���ô� �ٽ� �� �� ����.
	���� ����� ���� ������ �Ѵ�

	2 <= n <= 10

	n = 4
	0 10 15 20
	5  0  9 10
	6 13  0 12
	8  8  9  0
*/

int n;
int board[14][14];
long long visited[14];
long long sum = 0;
vector<long long> result;

void DFS(int start)
{
	if (accumulate(visited + 1, visited + n, 0) == n - 1)
	{
		if (board[start][0] != 0)
		{
			sum += board[start][0];
			result.push_back(sum);
			sum -= board[start][0];

			return;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (visited[i] == 1)
			continue;

		if (board[start][i] == 0)
			continue;

		visited[i] = 1;
		sum += board[start][i];

		DFS(i);

		visited[i] = 0;
		sum -= board[start][i];
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
		}
	}

	//visited[0] = 1;
	DFS(0);

	long long minResult = LLONG_MAX;
	for (auto& r : result)
	{
		//cout << r << " ";
		minResult = min(minResult, r);
	}

	cout << minResult << '\n';

	return 0;
}
