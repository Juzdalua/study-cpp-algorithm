#include <bits/stdc++.h>
using namespace std;

/*
	백준이가 정수를 외칠 때,
	동생은 지금까지 말한 수 중 중간값을 말한다.

	쌓인 수가 짝수개라면 중간 두 수 중 작은 수를 말한다.

	1, 5, 2, 10, -99, 7, 5
	1, 1, 2,  2,   2, 2, 5

	1 -> 1
	1, 5 -> 1
	1, 5, 2 -> 2 => 1, 2, 5
	1, 5, 2, 10 -> 2 => 1, 2, 5, 10
	1, 5, 2, 10, -99 -> 2 => -99, 1, 2, 5, 10
	1, 5, 2, 10, -99, 7 -> 2
	1, 5, 2, 10, -99, 7, 5 -> 5 => -99, 1, 2, 5, 5, 7, 10

	1 <= N <= 100'000 = 10^5
	-10'000 <= k <= 10'000
*/

int n;
vector<int> result;
priority_queue<int, vector<int>, greater<int>> upperPq; // 6 7 8 9 10
priority_queue<int> lowerPq; // 5 4 3 2 1

void Solution()
{
	//if (lowerPq.size() - upperPq.size() > 1)
	if (lowerPq.size() > upperPq.size() + 1)
	{
		upperPq.push(lowerPq.top());
		lowerPq.pop();
	}
	else if(upperPq.size() > lowerPq.size())
	{
		lowerPq.push(upperPq.top());
		upperPq.pop();
	}

	result.push_back(lowerPq.top());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		if (lowerPq.empty() || lowerPq.top() >= input)
			lowerPq.push(input);
		else
			upperPq.push(input);

		Solution();
	}

	for (int r : result)
		cout << r << '\n';

	return 0;
}