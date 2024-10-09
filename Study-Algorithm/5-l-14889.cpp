#include <bits/stdc++.h>
using namespace std;

/*
	�౸ N�� ¦��
	��ŸƮ��, ��ũ��
	S[i][j] = �� ����� ���� ���� ������ ��, ���� �������� �ɷ�ġ

	��ŸƮ���� ��ũ���� �ɷ�ġ ���̸� �ּ�ȭ�Ϸ��Ѵ�.

	N(4 �� N �� 20, N�� ¦��)
	1 <= S[i][j] <= 100
*/

int n;
int board[24][24];
int visited[24];
int team1[24];
int team2[24];
int minResult = INT_MAX;

int TeamPower(int team[])
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (team[i] == 0)
			continue;

		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (team[j] == 0)
				continue;

			sum += board[i][j];
		}
	}

	return sum;
}

void Go(int idx, int count)
{
	if (count == n / 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 1)
				team1[i] = 1;
			else
				team2[i] = 1;
		}

		int power1 = TeamPower(team1);
		int power2 = TeamPower(team2);
		//cout << "Team1: " << power1 << ", Team2: " << power2 << '\n';

		minResult = min(minResult, abs(power1 - power2));
		memset(team1, 0, sizeof(team1));
		memset(team2, 0, sizeof(team2));
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (visited[i] != 0)
			continue;

		visited[i] = 1;
		Go(i + 1, count + 1);
		visited[i] = 0;
	}
}

void Solution()
{
	Go(0, 0);
	cout << minResult << '\n';
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

	Solution();

	return 0;
}