#include <bits/stdc++.h>
using namespace std;

/*
	N개 물웅덩이
	웅덩이를 덮는 널빤지의 길이 L
	충분히 가지고있음
	다리를 만들어 웅덩이를 덮는다
	필요한 널빤지의 최소 개수를 구하라

	1 ≤ N ≤ 10,000
	1 ≤ L ≤ 1,000,000 - 10^5
	0 <= 웅덩이 위치 <= 1,000,000,000 - 10억 - 10^8
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