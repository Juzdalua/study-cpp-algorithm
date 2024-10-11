#include <bits/stdc++.h>
using namespace std;

/*
	N�� ��������
	�����̸� ���� �κ����� ���� L
	����� ����������
	�ٸ��� ����� �����̸� ���´�
	�ʿ��� �κ����� �ּ� ������ ���϶�

	1 �� N �� 10,000
	1 �� L �� 1,000,000 - 10^5
	0 <= ������ ��ġ <= 1,000,000,000 - 10�� - 10^8
*/

int n, l;
vector<pair<int, int>> board;
pair<int, int> nowPos;
int result;

void Solution()
{
	sort(board.begin(), board.end());
	for (auto& b : board)
	{
		//cout << b.first << " : " << b.second << '\n';

		while (true)
		{
			if (nowPos.second < b.first)
			{
				result++;
				nowPos = { b.first, b.first + l - 1 };
				//cout << nowPos.first << ", " << nowPos.second << '\n';
			}
			if (nowPos.second < b.second)
			{
				result++;
				nowPos = { nowPos.second + 1, nowPos.second + 1 + l - 1 };
				//cout << nowPos.first << ", " << nowPos.second << '\n';
			}

			if (nowPos.second >= b.second)
				break;
		}
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
		int input1, input2;
		cin >> input1 >> input2;
		board.push_back({ input1, input2 - 1 });
	}

	Solution();

	return 0;
}